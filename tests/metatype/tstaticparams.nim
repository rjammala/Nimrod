discard """
  file: "tstaticparams.nim"
  output: "abracadabra\ntest\n3\n15\4"
"""

type 
  TFoo[T; Val: static[string]] = object
    data: array[4, T]

  TBar[T; I: static[int]] = object
    data: array[I, T]

  TA1[T; I: static[int]] = array[I, T]
  TA2[T; I: static[int]] = array[0..I, T]
  TA3[T; I: static[int]] = array[I-1, T]

proc takeFoo(x: TFoo) =
  echo "abracadabra"
  echo TFoo.Val

var x: TFoo[int, "test"]
takeFoo(x)

var y: TBar[float, 4]
echo high(y.data)

var
  t1: TA1[float, 1]
  t2: TA2[string, 4]
  t3: TA3[int, 10]

# example from the manual:
type
  Matrix[M,N: static[int]; T] = array[0..(M*N - 1), T]
    # Note how `Number` is just a type constraint here, while
    # `static[int]` requires us to supply a compile-time int value

  AffineTransform2D[T] = Matrix[3, 3, T]
  AffineTransform3D[T] = Matrix[4, 4, T]

var m: AffineTransform3D[float]
echo high(m)

proc getRows(mtx: Matrix): int =
  result = mtx.M

echo getRows(m)
