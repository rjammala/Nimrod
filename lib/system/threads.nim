#
#
#            Nimrod's Runtime Library
#        (c) Copyright 2011 Andreas Rumpf
#
#    See the file "copying.txt", included in this
#    distribution, for details about the copyright.
#

## Thread support for Nimrod. **Note**: This is part of the system module.
## Do not import it directly. To active thread support you need to compile
## with the ``--threads:on`` command line switch.
##
## Nimrod's memory model for threads is quite different from other common 
## programming languages (C, Pascal): Each thread has its own
## (garbage collected) heap and sharing of memory is restricted. This helps
## to prevent race conditions and improves efficiency. See the manual for
## details of this memory model.
##
## Example:
##
## .. code-block:: nimrod
##
##  var
##    thr: array [0..4, TThread[tuple[a,b: int]]]
##    L: TLock
##  
##  proc threadFunc(interval: tuple[a,b: int]) {.thread.} =
##    for i in interval.a..interval.b:
##      Acquire(L) # lock stdout
##      echo i
##      Release(L)
##
##  InitLock(L)
##
##  for i in 0..high(thr):
##    createThread(thr[i], threadFunc, (i*10, i*10+5))
##  joinThreads(thr)
  
const
  maxRegisters = 256 # don't think there is an arch with more registers
  maxLocksPerThread* = 10 ## max number of locks a thread can hold
                          ## at the same time
  useStackMaskHack = false ## use the stack mask hack for better performance
  StackGuardSize = 4096
  ThreadStackMask = 1024*256*sizeof(int)-1
  ThreadStackSize = ThreadStackMask+1 - StackGuardSize

when defined(windows):
  type
    TSysThread = THandle
    TWinThreadProc = proc (x: pointer): int32 {.stdcall.}

  proc CreateThread(lpThreadAttributes: Pointer, dwStackSize: int32,
                     lpStartAddress: TWinThreadProc, 
                     lpParameter: Pointer,
                     dwCreationFlags: int32, 
                     lpThreadId: var int32): TSysThread {.
    stdcall, dynlib: "kernel32", importc: "CreateThread".}

  proc winSuspendThread(hThread: TSysThread): int32 {.
    stdcall, dynlib: "kernel32", importc: "SuspendThread".}
      
  proc winResumeThread(hThread: TSysThread): int32 {.
    stdcall, dynlib: "kernel32", importc: "ResumeThread".}

  proc WaitForMultipleObjects(nCount: int32,
                              lpHandles: ptr TSysThread,
                              bWaitAll: int32,
                              dwMilliseconds: int32): int32 {.
    stdcall, dynlib: "kernel32", importc: "WaitForMultipleObjects".}

  proc TerminateThread(hThread: TSysThread, dwExitCode: int32): int32 {.
    stdcall, dynlib: "kernel32", importc: "TerminateThread".}
    
  type
    TThreadVarSlot = distinct int32

  proc ThreadVarAlloc(): TThreadVarSlot {.
    importc: "TlsAlloc", stdcall, dynlib: "kernel32".}
  proc ThreadVarSetValue(dwTlsIndex: TThreadVarSlot, lpTlsValue: pointer) {.
    importc: "TlsSetValue", stdcall, dynlib: "kernel32".}
  proc ThreadVarGetValue(dwTlsIndex: TThreadVarSlot): pointer {.
    importc: "TlsGetValue", stdcall, dynlib: "kernel32".}
  
else:
  {.passL: "-pthread".}
  {.passC: "-pthread".}

  type
    TSysThread {.importc: "pthread_t", header: "<sys/types.h>",
                 final, pure.} = object
    Tpthread_attr {.importc: "pthread_attr_t",
                     header: "<sys/types.h>", final, pure.} = object
                 
    Ttimespec {.importc: "struct timespec",
                header: "<time.h>", final, pure.} = object
      tv_sec: int
      tv_nsec: int

  proc pthread_attr_init(a1: var TPthread_attr) {.
    importc, header: "<pthread.h>".}
  proc pthread_attr_setstacksize(a1: var TPthread_attr, a2: int) {.
    importc, header: "<pthread.h>".}

  proc pthread_create(a1: var TSysThread, a2: var TPthread_attr,
            a3: proc (x: pointer) {.noconv.}, 
            a4: pointer): cint {.importc: "pthread_create", 
            header: "<pthread.h>".}
  proc pthread_join(a1: TSysThread, a2: ptr pointer): cint {.
    importc, header: "<pthread.h>".}

  proc pthread_cancel(a1: TSysThread): cint {.
    importc: "pthread_cancel", header: "<pthread.h>".}

  proc AcquireSysTimeoutAux(L: var TSysLock, timeout: var Ttimespec): cint {.
    importc: "pthread_mutex_timedlock", header: "<time.h>".}

  proc AcquireSysTimeout(L: var TSysLock, msTimeout: int) {.inline.} =
    var a: Ttimespec
    a.tv_sec = msTimeout div 1000
    a.tv_nsec = (msTimeout mod 1000) * 1000
    var res = AcquireSysTimeoutAux(L, a)
    if res != 0'i32: raise newException(EResourceExhausted, $strerror(res))

  type
    TThreadVarSlot {.importc: "pthread_key_t", pure, final,
                   header: "<sys/types.h>".} = object

  proc pthread_getspecific(a1: TThreadVarSlot): pointer {.
    importc: "pthread_getspecific", header: "<pthread.h>".}
  proc pthread_key_create(a1: ptr TThreadVarSlot, 
                          destruct: proc (x: pointer) {.noconv.}): int32 {.
    importc: "pthread_key_create", header: "<pthread.h>".}
  proc pthread_key_delete(a1: TThreadVarSlot): int32 {.
    importc: "pthread_key_delete", header: "<pthread.h>".}

  proc pthread_setspecific(a1: TThreadVarSlot, a2: pointer): int32 {.
    importc: "pthread_setspecific", header: "<pthread.h>".}
  
  proc ThreadVarAlloc(): TThreadVarSlot {.inline.} =
    discard pthread_key_create(addr(result), nil)
  proc ThreadVarSetValue(s: TThreadVarSlot, value: pointer) {.inline.} =
    discard pthread_setspecific(s, value)
  proc ThreadVarGetValue(s: TThreadVarSlot): pointer {.inline.} =
    result = pthread_getspecific(s)

  when useStackMaskHack:
    proc pthread_attr_setstack(attr: var TPthread_attr, stackaddr: pointer,
                               size: int): cint {.
      importc: "pthread_attr_setstack", header: "<pthread.h>".}

const
  emulatedThreadVars = true

when emulatedThreadVars:
  # the compiler generates this proc for us, so that we can get the size of
  # the thread local var block; we use this only for sanity checking though
  proc NimThreadVarsSize(): int {.noconv, importc: "NimThreadVarsSize".}

# we preallocate a fixed size for thread local storage, so that no heap
# allocations are needed. Currently less than 7K are used on a 64bit machine.
# We use ``float`` for proper alignment:
type
  TThreadLocalStorage = array [0..1_000, float]

  PGcThread = ptr TGcThread
  TGcThread {.pure.} = object
    sys: TSysThread
    next, prev: PGcThread
    stackBottom, stackTop: pointer
    stackSize: int
    inbox: TThreadLocalStorage
    when emulatedThreadVars and not useStackMaskHack:
      tls: TThreadLocalStorage
    else:
      nil

# XXX it'd be more efficient to not use a global variable for the 
# thread storage slot, but to rely on the implementation to assign slot 0
# for us... ;-)
var globalsSlot = ThreadVarAlloc()
#const globalsSlot = TThreadVarSlot(0)
#sysAssert checkSlot.int == globalsSlot.int

proc GetThreadLocalVars(): pointer {.compilerRtl, inl.} =
  result = addr(cast[PGcThread](ThreadVarGetValue(globalsSlot)).tls)

when useStackMaskHack:
  proc MaskStackPointer(offset: int): pointer {.compilerRtl, inl.} =
    var x {.volatile.}: pointer
    x = addr(x)
    result = cast[pointer]((cast[int](x) and not ThreadStackMask) +% 
      (0) +% offset)

# create for the main thread. Note: do not insert this data into the list
# of all threads; it's not to be stopped etc.
when not defined(useNimRtl):
  when not useStackMaskHack:
    var mainThread: TGcThread
    ThreadVarSetValue(globalsSlot, addr(mainThread))
    initStackBottom()
    initGC()
  
  var heapLock: TSysLock
  InitSysLock(HeapLock)

  when emulatedThreadVars:
    if NimThreadVarsSize() > sizeof(TThreadLocalStorage):
      echo "too large thread local storage size requested"
      quit 1

  var
    threadList: PGcThread
    
  proc registerThread(t: PGcThread) = 
    # we need to use the GC global lock here!
    AcquireSys(HeapLock)
    t.prev = nil
    t.next = threadList
    if threadList != nil: 
      sysAssert(threadList.prev == nil)
      threadList.prev = t
    threadList = t
    ReleaseSys(HeapLock)
  
  proc unregisterThread(t: PGcThread) =
    # we need to use the GC global lock here!
    AcquireSys(HeapLock)
    if t == threadList: threadList = t.next
    if t.next != nil: t.next.prev = t.prev
    if t.prev != nil: t.prev.next = t.next
    # so that a thread can be unregistered twice which might happen if the
    # code executes `destroyThread`:
    t.next = nil
    t.prev = nil
    ReleaseSys(HeapLock)
    
  # on UNIX, the GC uses ``SIGFREEZE`` to tell every thread to stop so that
  # the GC can examine the stacks?
  proc stopTheWord() = nil
    
# We jump through some hops here to ensure that Nimrod thread procs can have
# the Nimrod calling convention. This is needed because thread procs are 
# ``stdcall`` on Windows and ``noconv`` on UNIX. Alternative would be to just
# use ``stdcall`` since it is mapped to ``noconv`` on UNIX anyway. However, 
# the current approach will likely result in less problems later when we have
# GC'ed closures in Nimrod.

type
  TThread* {.pure, final.}[TParam] = object of TGcThread ## Nimrod thread.
    fn: proc (p: TParam)
    data: TParam

proc initInbox(p: pointer)
proc freeInbox(p: pointer)
when not defined(boehmgc) and not hasSharedHeap:
  proc deallocOsPages()
  
template ThreadProcWrapperBody(closure: expr) =
  ThreadVarSetValue(globalsSlot, closure)
  var t = cast[ptr TThread[TParam]](closure)
  when useStackMaskHack:
    var tls: TThreadLocalStorage
  when not defined(boehmgc) and not hasSharedHeap:
    # init the GC for this thread:
    setStackBottom(addr(t))
    initGC()
  t.stackBottom = addr(t)
  registerThread(t)
  initInbox(addr(t.inbox))
  try:
    when false:
      var a = addr(tls)
      var b = MaskStackPointer(1293920-372736-303104-36864)
      c_fprintf(c_stdout, "TLS:    %p\nmasked: %p\ndiff:   %ld\n",
                a, b, cast[int](a) - cast[int](b))
    t.fn(t.data)
  finally:
    # XXX shut-down is not executed when the thread is forced down!
    freeInbox(addr(t.inbox))
    unregisterThread(t)
    when defined(deallocOsPages): deallocOsPages()
  
{.push stack_trace:off.}
when defined(windows):
  proc threadProcWrapper[TParam](closure: pointer): int32 {.stdcall.} = 
    ThreadProcWrapperBody(closure)
    # implicitely return 0
else:
  proc threadProcWrapper[TParam](closure: pointer) {.noconv.} = 
    ThreadProcWrapperBody(closure)
{.pop.}

proc joinThread*[TParam](t: TThread[TParam]) {.inline.} = 
  ## waits for the thread `t` to finish.
  when hostOS == "windows":
    discard WaitForSingleObject(t.sys, -1'i32)
  else:
    discard pthread_join(t.sys, nil)

proc joinThreads*[TParam](t: openArray[TThread[TParam]]) = 
  ## waits for every thread in `t` to finish.
  when hostOS == "windows":
    var a: array[0..255, TSysThread]
    sysAssert a.len >= t.len
    for i in 0..t.high: a[i] = t[i].sys
    discard WaitForMultipleObjects(t.len, cast[ptr TSysThread](addr(a)), 1, -1)
  else:
    for i in 0..t.high: joinThread(t[i])

when false:
  # XXX a thread should really release its heap here somehow:
  proc destroyThread*[TParam](t: var TThread[TParam]) =
    ## forces the thread `t` to terminate. This is potentially dangerous if
    ## you don't have full control over `t` and its acquired resources.
    when hostOS == "windows":
      discard TerminateThread(t.sys, 1'i32)
    else:
      discard pthread_cancel(t.sys)
    unregisterThread(addr(t))

proc createThread*[TParam](t: var TThread[TParam], 
                           tp: proc (param: TParam) {.thread.}, 
                           param: TParam) =
  ## creates a new thread `t` and starts its execution. Entry point is the
  ## proc `tp`. `param` is passed to `tp`.
  t.data = param
  t.fn = tp
  t.stackSize = ThreadStackSize
  when hostOS == "windows":
    var dummyThreadId: int32
    t.sys = CreateThread(nil, ThreadStackSize, threadProcWrapper[TParam],
                         addr(t), 0'i32, dummyThreadId)
    if t.sys <= 0:
      raise newException(EResourceExhausted, "cannot create thread")
  else:
    var a: Tpthread_attr
    pthread_attr_init(a)
    pthread_attr_setstacksize(a, ThreadStackSize)
    if pthread_create(t.sys, a, threadProcWrapper[TParam], addr(t)) != 0:
      raise newException(EResourceExhausted, "cannot create thread")

when useStackMaskHack:
  proc runMain(tp: proc (dummy: pointer) {.thread.}) {.compilerproc.} =
    var mainThread: TThread[pointer]
    createThread(mainThread, tp, nil)
    joinThread(mainThread)

# --------------------------- lock handling ----------------------------------

type
  TLock* = TSysLock ## Nimrod lock
  
const
  noDeadlocks = false # compileOption("deadlockPrevention")

when nodeadlocks:
  var
    deadlocksPrevented*: int ## counts the number of times a 
                             ## deadlock has been prevented
    locksLen {.threadvar.}: int
    locks {.threadvar.}: array [0..MaxLocksPerThread-1, pointer]

  proc OrderedLocks(): bool = 
    for i in 0 .. locksLen-2:
      if locks[i] >= locks[i+1]: return false
    result = true

proc InitLock*(lock: var TLock) {.inline.} =
  ## Initializes the lock `lock`.
  InitSysLock(lock)

proc TryAcquire*(lock: var TLock): bool {.inline.} = 
  ## Try to acquires the lock `lock`. Returns `true` on success.
  result = TryAcquireSys(lock)
  when noDeadlocks:
    if not result: return
    # we have to add it to the ordered list. Oh, and we might fail if
    # there is no space in the array left ...
    if locksLen >= len(locks):
      ReleaseSys(lock)
      raise newException(EResourceExhausted, "cannot acquire additional lock")
    # find the position to add:
    var p = addr(lock)
    var L = locksLen-1
    var i = 0
    while i <= L:
      sysAssert locks[i] != nil
      if locks[i] < p: inc(i) # in correct order
      elif locks[i] == p: return # thread already holds lock
      else:
        # do the crazy stuff here:
        while L >= i:
          locks[L+1] = locks[L]
          dec L
        locks[i] = p
        inc(locksLen)
        sysAssert OrderedLocks()
        return
    # simply add to the end:
    locks[locksLen] = p
    inc(locksLen)
    sysAssert OrderedLocks(g)

proc Acquire*(lock: var TLock) =
  ## Acquires the lock `lock`.
  when nodeadlocks:
    var p = addr(lock)
    var L = locksLen-1
    var i = 0
    while i <= L:
      sysAssert locks[i] != nil
      if locks[i] < p: inc(i) # in correct order
      elif locks[i] == p: return # thread already holds lock
      else:
        # do the crazy stuff here:
        if locksLen >= len(locks):
          raise newException(EResourceExhausted, 
              "cannot acquire additional lock")
        while L >= i:
          ReleaseSys(cast[ptr TSysLock](locks[L])[])
          locks[L+1] = locks[L]
          dec L
        # acquire the current lock:
        AcquireSys(lock)
        locks[i] = p
        inc(locksLen)
        # acquire old locks in proper order again:
        L = locksLen-1
        inc i
        while i <= L:
          AcquireSys(cast[ptr TSysLock](locks[i])[])
          inc(i)
        # DANGER: We can only modify this global var if we gained every lock!
        # NO! We need an atomic increment. Crap.
        discard system.atomicInc(deadlocksPrevented, 1)
        sysAssert OrderedLocks(g)
        return
        
    # simply add to the end:
    if locksLen >= len(locks):
      raise newException(EResourceExhausted, "cannot acquire additional lock")
    AcquireSys(lock)
    locks[locksLen] = p
    inc(locksLen)
    sysAssert OrderedLocks(g)
  else:
    AcquireSys(lock)
  
proc Release*(lock: var TLock) =
  ## Releases the lock `lock`.
  when nodeadlocks:
    var p = addr(lock)
    var L = locksLen
    for i in countdown(L-1, 0):
      if locks[i] == p: 
        for j in i..L-2: locks[j] = locks[j+1]
        dec locksLen
        break
  ReleaseSys(lock)

# ------------------------ message passing support ---------------------------

proc getInBoxMem*[TMsg](t: var TThread[TMsg]): pointer {.inline.} =
  result = addr(t.inbox)

proc getInBoxMem*(): pointer {.inline.} =
  result = addr(cast[PGcThread](ThreadVarGetValue(globalsSlot)).inbox)

