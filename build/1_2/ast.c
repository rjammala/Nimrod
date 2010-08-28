/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long long int NI;
typedef unsigned long long int NU;
#include "nimbase.h"

typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TY49898 TY49898;
typedef struct TY49894 TY49894;
typedef struct TY49896 TY49896;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct TY49561 TY49561;
typedef struct TY49559 TY49559;
typedef struct TY49557 TY49557;
typedef struct TY48005 TY48005;
typedef struct TNimObject TNimObject;
typedef struct TY49527 TY49527;
typedef struct TY49525 TY49525;
typedef struct TY49545 TY49545;
typedef struct TY49523 TY49523;
typedef struct TY49549 TY49549;
typedef struct TY41532 TY41532;
typedef struct TY48011 TY48011;
typedef struct TY49517 TY49517;
typedef struct TY10202 TY10202;
typedef struct TY10218 TY10218;
typedef struct TY10590 TY10590;
typedef struct TY10214 TY10214;
typedef struct TY10210 TY10210;
typedef struct TY10588 TY10588;
typedef struct TY49547 TY49547;
typedef struct TY49537 TY49537;
typedef struct TY46008 TY46008;
typedef struct TY49541 TY49541;
typedef struct TY49567 TY49567;
typedef struct TY49565 TY49565;
typedef struct TY49563 TY49563;
typedef struct TY49573 TY49573;
typedef struct TY49571 TY49571;
typedef struct TY49569 TY49569;
typedef struct TY37013 TY37013;
struct TGenericSeq {
NI len;
NI space;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
typedef NimStringDesc* TY49016[10];
struct TY49898 {
NI Counter;
NI Max;
TY49894* Head;
TY49896* Data;
};
struct TNimType {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
};
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
struct TY49557 {
TY48005* Key;
TNimObject* Val;
};
struct TY49561 {
NI Counter;
TY49559* Data;
};
struct TY49527 {
TNimType* m_type;
NI Counter;
TY49525* Data;
};
struct TY41532 {
NI16 Line;
NI16 Col;
NI32 Fileindex;
};
struct TY49523 {
TY49549* Typ;
NimStringDesc* Comment;
TY41532 Info;
NU8 Flags;
NU8 Kind;
union {
struct {NI64 Intval;
} S1;
struct {NF64 Floatval;
} S2;
struct {NimStringDesc* Strval;
} S3;
struct {TY49545* Sym;
} S4;
struct {TY48011* Ident;
} S5;
struct {TY49517* Sons;
} S6;
} KindU;
};
struct TY10202 {
NI Refcount;
TNimType* Typ;
};
struct TY10218 {
NI Len;
NI Cap;
TY10202** D;
};
struct TY10214 {
NI Counter;
NI Max;
TY10210* Head;
TY10210** Data;
};
struct TY10588 {
NI Stackscans;
NI Cyclecollections;
NI Maxthreshold;
NI Maxstacksize;
NI Maxstackcells;
NI Cycletablesize;
};
struct TY10590 {
TY10218 Zct;
TY10218 Decstack;
TY10214 Cycleroots;
TY10218 Tempstack;
TY10588 Stat;
};
struct TNimObject {
TNimType* m_type;
};
struct TY48005 {
  TNimObject Sup;
NI Id;
};
typedef NI TY8214[8];
struct TY49894 {
TY49894* Next;
NI Key;
TY8214 Bits;
};
struct TY49537 {
NU8 K;
NU8 S;
NU8 Flags;
TY49549* T;
TY46008* R;
NI A;
};
struct TY49549 {
  TY48005 Sup;
NU8 Kind;
TY49547* Sons;
TY49523* N;
NU8 Flags;
NU8 Callconv;
TY49545* Owner;
TY49545* Sym;
NI64 Size;
NI Align;
NI Containerid;
TY49537 Loc;
};
struct TY49545 {
  TY48005 Sup;
NU8 Kind;
NU8 Magic;
TY49549* Typ;
TY48011* Name;
TY41532 Info;
TY49545* Owner;
NU32 Flags;
TY49527 Tab;
TY49523* Ast;
NU32 Options;
NI Position;
NI Offset;
TY49537 Loc;
TY49541* Annex;
};
struct TY49563 {
TY48005* Key;
TY49523* Val;
};
struct TY49567 {
NI Counter;
TY49565* Data;
};
struct TY49569 {
NI H;
TY49523* Key;
NI Val;
};
struct TY49573 {
NI Counter;
TY49571* Data;
};
struct TY48011 {
  TY48005 Sup;
NimStringDesc* S;
TY48011* Next;
NI H;
};
struct TY10210 {
TY10210* Next;
NI Key;
TY8214 Bits;
};
struct TY46008 {
  TNimObject Sup;
TY46008* Left;
TY46008* Right;
NI Length;
NimStringDesc* Data;
};
struct TY37013 {
  TNimObject Sup;
TY37013* Prev;
TY37013* Next;
};
struct TY49541 {
  TY37013 Sup;
NU8 Kind;
NIM_BOOL Generated;
TY46008* Name;
TY49523* Path;
};
struct TY49896 {
  TGenericSeq Sup;
  TY49894* data[SEQ_DECL_SIZE];
};
struct TY49559 {
  TGenericSeq Sup;
  TY49557 data[SEQ_DECL_SIZE];
};
struct TY49525 {
  TGenericSeq Sup;
  TY49545* data[SEQ_DECL_SIZE];
};
struct TY49517 {
  TGenericSeq Sup;
  TY49523* data[SEQ_DECL_SIZE];
};
struct TY49547 {
  TGenericSeq Sup;
  TY49549* data[SEQ_DECL_SIZE];
};
struct TY49565 {
  TGenericSeq Sup;
  TY49563 data[SEQ_DECL_SIZE];
};
struct TY49571 {
  TGenericSeq Sup;
  TY49569 data[SEQ_DECL_SIZE];
};
N_NIMCALL(void, Intsetinit_49922)(TY49898* S_49925);
N_NIMCALL(void*, newSeq)(TNimType* Typ_12403, NI Len_12404);
N_NIMCALL(void, unsureAsgnRef)(void** Dest_11422, void* Src_11423);
N_NIMCALL(void*, newObj)(TNimType* Typ_11907, NI Size_11908);
N_NIMCALL(TY49523*, Newnode_49708)(NU8 Kind_49710);
static N_INLINE(void, asgnRefNoCycle)(void** Dest_11416, void* Src_11417);
static N_INLINE(TY10202*, Usrtocell_10622)(void* Usr_10624);
static N_INLINE(void, Rtladdzct_11256)(TY10202* C_11258);
N_NOINLINE(void, Addzct_10611)(TY10218* S_10614, TY10202* C_10615);
N_NIMCALL(TGenericSeq*, incrSeq)(TGenericSeq* Seq_17035, NI Elemsize_17036);
N_NIMCALL(NI, Sonslen_49801)(TY49523* N_49803);
N_NIMCALL(NIM_BOOL, Intsetcontainsorincl_49926)(TY49898* S_49929, NI Key_49930);
N_NIMCALL(TY49894*, Intsetget_52083)(TY49898* T_52085, NI Key_52086);
N_NIMCALL(NI, Nexttry_52062)(NI H_52064, NI Maxhash_52065);
N_NIMCALL(void, Intsetincl_49912)(TY49898* S_49915, NI Key_49916);
N_NIMCALL(TY49894*, Intsetput_52194)(TY49898* T_52197, NI Key_52198);
N_NIMCALL(NIM_BOOL, Mustrehash_52051)(NI Length_52053, NI Counter_52054);
N_NIMCALL(void, Intsetenlarge_52142)(TY49898* T_52145);
N_NIMCALL(void, Intsetrawinsert_52103)(TY49898* T_52105, TY49896** Data_52107, TY49894* Desc_52108);
static N_INLINE(void, asgnRef)(void** Dest_11412, void* Src_11413);
static N_INLINE(void, Incref_11401)(TY10202* C_11403);
static N_INLINE(NIM_BOOL, Canbecycleroot_10626)(TY10202* C_10628);
static N_INLINE(void, Rtladdcycleroot_11252)(TY10202* C_11254);
N_NOINLINE(void, Incl_10474)(TY10214* S_10477, TY10202* Cell_10478);
static N_INLINE(void, Decref_11260)(TY10202* C_11262);
N_NIMCALL(void, Internalerror_41571)(NimStringDesc* Errmsg_41573);
static N_INLINE(void, appendString)(NimStringDesc* Dest_16992, NimStringDesc* Src_16993);
N_NIMCALL(NimStringDesc*, nimIntToStr)(NI X_17603);
N_NIMCALL(NimStringDesc*, rawNewString)(NI Space_16887);
N_NIMCALL(NI, Getid_49691)(void);
N_NIMCALL(void, Registerid_49932)(TY48005* Id_49934);
N_NIMCALL(NimStringDesc*, copyString)(NimStringDesc* Src_16908);
N_NIMCALL(void, genericSeqAssign)(void* Dest_17839, void* Src_17840, TNimType* Mt_17841);
N_NIMCALL(void, Newsons_49813)(TY49523* Father_49815, NI Length_49816);
N_NIMCALL(TGenericSeq*, setLengthSeq)(TGenericSeq* Seq_17203, NI Elemsize_17204, NI Newlen_17205);
N_NIMCALL(TY49523*, Copytree_49856)(TY49523* Src_49858);
N_NIMCALL(NI, Sonslen_49804)(TY49549* N_49806);
static N_INLINE(NI, cmpStrings)(NimStringDesc* A_16811, NimStringDesc* B_16812);
N_NIMCALL(void, Internalerror_41567)(TY41532 Info_41569, NimStringDesc* Errmsg_41570);
static N_INLINE(NIM_BOOL, eqStrings)(NimStringDesc* A_16847, NimStringDesc* B_16848);
N_NIMCALL(TY49523*, Newintnode_49711)(NU8 Kind_49713, NI64 Intval_49714);
static N_INLINE(void, appendChar)(NimStringDesc* Dest_17009, NIM_CHAR C_17010);
N_NIMCALL(NimStringDesc*, nimInt64ToStr)(NI64 X_17667);
N_NIMCALL(NimStringDesc*, nimFloatToStr)(NF X_17660);
N_NIMCALL(void, genericAssign)(void* Dest_17765, void* Src_17766, TNimType* Mt_17767);
N_NIMCALL(TY49549*, Newtype_49704)(NU8 Kind_49706, TY49545* Owner_49707);
N_NIMCALL(void, Assigntype_49777)(TY49549* Dest_49779, TY49549* Src_49780);
N_NIMCALL(void, Newsons_49817)(TY49549* Father_49819, NI Length_49820);
N_NIMCALL(TY49545*, Newsym_49699)(NU8 Symkind_49701, TY48011* Name_49702, TY49545* Owner_49703);
N_NIMCALL(void, objectInit)(void* Dest_17862, TNimType* Typ_17863);
N_NIMCALL(TY41532, Unknownlineinfo_41536)(void);
N_NIMCALL(void, Copystrtable_49781)(TY49527* Dest_49784, TY49527* Src_49785);
N_NIMCALL(void, Addson_49821)(TY49523* Father_49823, TY49523* Son_49824);
STRING_LITERAL(TMP49019, "", 0);
STRING_LITERAL(TMP49020, "stdcall", 7);
STRING_LITERAL(TMP49021, "cdecl", 5);
STRING_LITERAL(TMP49022, "safecall", 8);
STRING_LITERAL(TMP49023, "syscall", 7);
STRING_LITERAL(TMP49024, "inline", 6);
STRING_LITERAL(TMP49025, "noinline", 8);
STRING_LITERAL(TMP49026, "fastcall", 8);
STRING_LITERAL(TMP49027, "closure", 7);
STRING_LITERAL(TMP49028, "noconv", 6);
NIM_CONST TY49016 Callingconvtostr_49015 = {((NimStringDesc*) &TMP49019),
((NimStringDesc*) &TMP49020),
((NimStringDesc*) &TMP49021),
((NimStringDesc*) &TMP49022),
((NimStringDesc*) &TMP49023),
((NimStringDesc*) &TMP49024),
((NimStringDesc*) &TMP49025),
((NimStringDesc*) &TMP49026),
((NimStringDesc*) &TMP49027),
((NimStringDesc*) &TMP49028)}
;
NIM_CONST NU32 Overloadablesyms_49669 = 269824;
NIM_CONST NU64 Generictypes_49671 = 5632;
NIM_CONST NU64 Structuralequivtypes_49673 = 201130032;
NIM_CONST NU64 Concretetypes_49675 = IL64(1098437836806);
NIM_CONST NU64 Constantdatatypes_49677 = 851968;
NIM_CONST NU32 Exportablesymkinds_49679 = 1081280;
NIM_CONST NU8 Persistentnodeflags_49681 = 30;
STRING_LITERAL(TMP190894, "ID already used: ", 17);
STRING_LITERAL(TMP190956, "leValue", 7);
STRING_LITERAL(TMP190957, "SameValue", 9);
STRING_LITERAL(TMP190973, "getInt", 6);
STRING_LITERAL(TMP190974, "getFloat", 8);
STRING_LITERAL(TMP190975, "getStr", 6);
STRING_LITERAL(TMP190977, "getStrOrChar", 12);
STRING_LITERAL(TMP191044, "valueToString", 13);
NI Gid_49690;
TY49898 Usedids_49935;
extern TNimType* NTI49896; /* TTrunkSeq */
extern TNimType* NTI49559; /* TIdPairSeq */
extern TNimType* NTI49525; /* TSymSeq */
extern TNimType* NTI49513; /* PNode */
extern TNimType* NTI49517; /* TNodeSeq */
extern TY10590 Gch_10608;
extern TNimType* NTI49892; /* PTrunk */
extern TNimType* NTI49547; /* TTypeSeq */
extern TNimType* NTI49519; /* PType */
extern TNimType* NTI49549; /* TType */
extern TNimType* NTI49565; /* TIdNodePairSeq */
extern TNimType* NTI49557; /* TIdPair */
extern TNimType* NTI49521; /* PSym */
extern TNimType* NTI49545; /* TSym */
extern NU32 Goptions_40075;
extern TNimType* NTI49537; /* TLoc */
extern TNimType* NTI49571; /* TNodePairSeq */
N_NIMCALL(void, Intsetinit_49922)(TY49898* S_49925) {
unsureAsgnRef((void**) &(*S_49925).Data, (TY49896*) newSeq(NTI49896, 8));
(*S_49925).Max = 7;
(*S_49925).Counter = 0;
unsureAsgnRef((void**) &(*S_49925).Head, NIM_NIL);
}
N_NIMCALL(void, Initidtable_49752)(TY49561* X_49755) {
(*X_49755).Counter = 0;
unsureAsgnRef((void**) &(*X_49755).Data, (TY49559*) newSeq(NTI49559, 8));
}
N_NIMCALL(void, Initstrtable_49744)(TY49527* X_49747) {
(*X_49747).Counter = 0;
unsureAsgnRef((void**) &(*X_49747).Data, (TY49525*) newSeq(NTI49525, 8));
}
N_NIMCALL(TY49523*, Newnode_49708)(NU8 Kind_49710) {
TY49523* Result_50476;
Result_50476 = 0;
Result_50476 = (TY49523*) newObj(NTI49513, sizeof(TY49523));
(*Result_50476).Kind = Kind_49710;
(*Result_50476).Info.Fileindex = ((NI32) -1);
(*Result_50476).Info.Col = ((NI16) -1);
(*Result_50476).Info.Line = ((NI16) -1);
return Result_50476;
}
N_NIMCALL(void, Setid_49693)(NI Id_49695) {
Gid_49690 = ((Gid_49690 >= (NI64)(Id_49695 + 1)) ? Gid_49690 : (NI64)(Id_49695 + 1));
}
N_NIMCALL(TY49523*, Newnodei_49735)(NU8 Kind_49737, TY41532 Info_49738) {
TY49523* Result_50586;
Result_50586 = 0;
Result_50586 = Newnode_49708(Kind_49737);
(*Result_50586).Info = Info_49738;
return Result_50586;
}
static N_INLINE(TY10202*, Usrtocell_10622)(void* Usr_10624) {
TY10202* Result_10625;
Result_10625 = 0;
Result_10625 = ((TY10202*) ((NI64)((NU64)(((NI) (Usr_10624))) - (NU64)(((NI) (((NI)sizeof(TY10202))))))));
return Result_10625;
}
static N_INLINE(void, Rtladdzct_11256)(TY10202* C_11258) {
Addzct_10611(&Gch_10608.Zct, C_11258);
}
static N_INLINE(void, asgnRefNoCycle)(void** Dest_11416, void* Src_11417) {
TY10202* C_11418;
TY10202* C_11419;
if (!!((Src_11417 == NIM_NIL))) goto LA2;
C_11418 = 0;
C_11418 = Usrtocell_10622(Src_11417);
(*C_11418).Refcount = (NI64)((NU64)((*C_11418).Refcount) + (NU64)(8));
LA2: ;
if (!!(((*Dest_11416) == NIM_NIL))) goto LA5;
C_11419 = 0;
C_11419 = Usrtocell_10622((*Dest_11416));
(*C_11419).Refcount = (NI64)((NU64)((*C_11419).Refcount) - (NU64)(8));
if (!((NU64)((*C_11419).Refcount) < (NU64)(8))) goto LA8;
Rtladdzct_11256(C_11419);
LA8: ;
LA5: ;
(*Dest_11416) = Src_11417;
}
N_NIMCALL(void, Addson_49821)(TY49523* Father_49823, TY49523* Son_49824) {
if (!(*Father_49823).KindU.S6.Sons == 0) goto LA2;
asgnRefNoCycle((void**) &(*Father_49823).KindU.S6.Sons, (TY49517*) newSeq(NTI49517, 0));
LA2: ;
(*Father_49823).KindU.S6.Sons = (TY49517*) incrSeq(&((*Father_49823).KindU.S6.Sons)->Sup, sizeof(TY49523*));
asgnRefNoCycle((void**) &(*Father_49823).KindU.S6.Sons->data[(*Father_49823).KindU.S6.Sons->Sup.len-1], Son_49824);
}
N_NIMCALL(NI, Sonslen_49801)(TY49523* N_49803) {
NI Result_50901;
Result_50901 = 0;
if (!(*N_49803).KindU.S6.Sons == 0) goto LA2;
Result_50901 = 0;
goto LA1;
LA2: ;
Result_50901 = (*N_49803).KindU.S6.Sons->Sup.len;
LA1: ;
return Result_50901;
}
N_NIMCALL(TY49523*, Lastson_49807)(TY49523* N_49809) {
TY49523* Result_51699;
NI LOC1;
Result_51699 = 0;
LOC1 = Sonslen_49801(N_49809);
Result_51699 = (*N_49809).KindU.S6.Sons->data[(NI64)(LOC1 - 1)];
return Result_51699;
}
N_NIMCALL(NI, Getid_49691)(void) {
NI Result_49954;
Result_49954 = 0;
Result_49954 = Gid_49690;
Gid_49690 += 1;
return Result_49954;
}
N_NIMCALL(NI, Nexttry_52062)(NI H_52064, NI Maxhash_52065) {
NI Result_52066;
Result_52066 = 0;
Result_52066 = (NI64)((NI64)((NI64)(5 * H_52064) + 1) & Maxhash_52065);
return Result_52066;
}
N_NIMCALL(TY49894*, Intsetget_52083)(TY49898* T_52085, NI Key_52086) {
TY49894* Result_52087;
NI H_52088;
Result_52087 = 0;
H_52088 = 0;
H_52088 = (NI64)(Key_52086 & (*T_52085).Max);
while (1) {
if (!!(((*T_52085).Data->data[H_52088] == NIM_NIL))) goto LA1;
if (!((*(*T_52085).Data->data[H_52088]).Key == Key_52086)) goto LA3;
Result_52087 = (*T_52085).Data->data[H_52088];
goto BeforeRet;
LA3: ;
H_52088 = Nexttry_52062(H_52088, (*T_52085).Max);
} LA1: ;
Result_52087 = NIM_NIL;
BeforeRet: ;
return Result_52087;
}
N_NIMCALL(NIM_BOOL, Mustrehash_52051)(NI Length_52053, NI Counter_52054) {
NIM_BOOL Result_52055;
NIM_BOOL LOC1;
Result_52055 = 0;
LOC1 = ((NI64)(Length_52053 * 2) < (NI64)(Counter_52054 * 3));
if (LOC1) goto LA2;
LOC1 = ((NI64)(Length_52053 - Counter_52054) < 4);
LA2: ;
Result_52055 = LOC1;
return Result_52055;
}
static N_INLINE(NIM_BOOL, Canbecycleroot_10626)(TY10202* C_10628) {
NIM_BOOL Result_10629;
Result_10629 = 0;
Result_10629 = !((((*(*C_10628).Typ).flags &(1<<((((NU8) 1))&7)))!=0));
return Result_10629;
}
static N_INLINE(void, Rtladdcycleroot_11252)(TY10202* C_11254) {
Incl_10474(&Gch_10608.Cycleroots, C_11254);
}
static N_INLINE(void, Incref_11401)(TY10202* C_11403) {
NIM_BOOL LOC2;
(*C_11403).Refcount = (NI64)((NU64)((*C_11403).Refcount) + (NU64)(8));
LOC2 = Canbecycleroot_10626(C_11403);
if (!LOC2) goto LA3;
Rtladdcycleroot_11252(C_11403);
LA3: ;
}
static N_INLINE(void, Decref_11260)(TY10202* C_11262) {
NIM_BOOL LOC4;
(*C_11262).Refcount = (NI64)((NU64)((*C_11262).Refcount) - (NU64)(8));
if (!((NU64)((*C_11262).Refcount) < (NU64)(8))) goto LA2;
Rtladdzct_11256(C_11262);
goto LA1;
LA2: ;
LOC4 = Canbecycleroot_10626(C_11262);
if (!LOC4) goto LA5;
Rtladdcycleroot_11252(C_11262);
goto LA1;
LA5: ;
LA1: ;
}
static N_INLINE(void, asgnRef)(void** Dest_11412, void* Src_11413) {
TY10202* LOC4;
TY10202* LOC8;
if (!!((Src_11413 == NIM_NIL))) goto LA2;
LOC4 = Usrtocell_10622(Src_11413);
Incref_11401(LOC4);
LA2: ;
if (!!(((*Dest_11412) == NIM_NIL))) goto LA6;
LOC8 = Usrtocell_10622((*Dest_11412));
Decref_11260(LOC8);
LA6: ;
(*Dest_11412) = Src_11413;
}
N_NIMCALL(void, Intsetrawinsert_52103)(TY49898* T_52105, TY49896** Data_52107, TY49894* Desc_52108) {
NI H_52109;
H_52109 = 0;
H_52109 = (NI64)((*Desc_52108).Key & (*T_52105).Max);
while (1) {
if (!!(((*Data_52107)->data[H_52109] == NIM_NIL))) goto LA1;
H_52109 = Nexttry_52062(H_52109, (*T_52105).Max);
} LA1: ;
asgnRef((void**) &(*Data_52107)->data[H_52109], Desc_52108);
}
N_NIMCALL(void, Intsetenlarge_52142)(TY49898* T_52145) {
TY49896* N_52146;
NI Oldmax_52147;
NI I_52167;
NI Res_52191;
TY49896* LOC5;
N_52146 = 0;
Oldmax_52147 = 0;
Oldmax_52147 = (*T_52145).Max;
(*T_52145).Max = (NI64)((NI64)((NI64)((*T_52145).Max + 1) * 2) - 1);
N_52146 = (TY49896*) newSeq(NTI49896, (NI64)((*T_52145).Max + 1));
I_52167 = 0;
Res_52191 = 0;
Res_52191 = 0;
while (1) {
if (!(Res_52191 <= Oldmax_52147)) goto LA1;
I_52167 = Res_52191;
if (!!(((*T_52145).Data->data[I_52167] == NIM_NIL))) goto LA3;
Intsetrawinsert_52103(&(*T_52145), &N_52146, (*T_52145).Data->data[I_52167]);
LA3: ;
Res_52191 += 1;
} LA1: ;
LOC5 = (*T_52145).Data;
unsureAsgnRef((void**) &(*T_52145).Data, N_52146);
N_52146 = LOC5;
}
N_NIMCALL(TY49894*, Intsetput_52194)(TY49898* T_52197, NI Key_52198) {
TY49894* Result_52199;
NI H_52200;
NIM_BOOL LOC6;
Result_52199 = 0;
H_52200 = 0;
H_52200 = (NI64)(Key_52198 & (*T_52197).Max);
while (1) {
if (!!(((*T_52197).Data->data[H_52200] == NIM_NIL))) goto LA1;
if (!((*(*T_52197).Data->data[H_52200]).Key == Key_52198)) goto LA3;
Result_52199 = (*T_52197).Data->data[H_52200];
goto BeforeRet;
LA3: ;
H_52200 = Nexttry_52062(H_52200, (*T_52197).Max);
} LA1: ;
LOC6 = Mustrehash_52051((NI64)((*T_52197).Max + 1), (*T_52197).Counter);
if (!LOC6) goto LA7;
Intsetenlarge_52142(T_52197);
LA7: ;
(*T_52197).Counter += 1;
H_52200 = (NI64)(Key_52198 & (*T_52197).Max);
while (1) {
if (!!(((*T_52197).Data->data[H_52200] == NIM_NIL))) goto LA9;
H_52200 = Nexttry_52062(H_52200, (*T_52197).Max);
} LA9: ;
Result_52199 = (TY49894*) newObj(NTI49892, sizeof(TY49894));
asgnRef((void**) &(*Result_52199).Next, (*T_52197).Head);
(*Result_52199).Key = Key_52198;
unsureAsgnRef((void**) &(*T_52197).Head, Result_52199);
asgnRef((void**) &(*T_52197).Data->data[H_52200], Result_52199);
BeforeRet: ;
return Result_52199;
}
N_NIMCALL(void, Intsetincl_49912)(TY49898* S_49915, NI Key_49916) {
NI U_52290;
TY49894* T_52291;
U_52290 = 0;
T_52291 = 0;
T_52291 = Intsetput_52194(S_49915, (NI64)((NU64)(Key_49916) >> (NU64)(9)));
U_52290 = (NI64)(Key_49916 & 511);
(*T_52291).Bits[((NI64)((NU64)(U_52290) >> (NU64)(6)))-0] = (NI64)((*T_52291).Bits[((NI64)((NU64)(U_52290) >> (NU64)(6)))-0] | (NI64)((NU64)(1) << (NU64)((NI64)(U_52290 & 63))));
}
N_NIMCALL(NIM_BOOL, Intsetcontainsorincl_49926)(TY49898* S_49929, NI Key_49930) {
NIM_BOOL Result_52315;
NI U_52316;
TY49894* T_52317;
Result_52315 = 0;
U_52316 = 0;
T_52317 = 0;
T_52317 = Intsetget_52083(&(*S_49929), (NI64)((NU64)(Key_49930) >> (NU64)(9)));
if (!!((T_52317 == NIM_NIL))) goto LA2;
U_52316 = (NI64)(Key_49930 & 511);
Result_52315 = !(((NI64)((*T_52317).Bits[((NI64)((NU64)(U_52316) >> (NU64)(6)))-0] & (NI64)((NU64)(1) << (NU64)((NI64)(U_52316 & 63)))) == 0));
if (!!(Result_52315)) goto LA5;
(*T_52317).Bits[((NI64)((NU64)(U_52316) >> (NU64)(6)))-0] = (NI64)((*T_52317).Bits[((NI64)((NU64)(U_52316) >> (NU64)(6)))-0] | (NI64)((NU64)(1) << (NU64)((NI64)(U_52316 & 63))));
LA5: ;
goto LA1;
LA2: ;
Intsetincl_49912(S_49929, Key_49930);
Result_52315 = NIM_FALSE;
LA1: ;
return Result_52315;
}
static N_INLINE(void, appendString)(NimStringDesc* Dest_16992, NimStringDesc* Src_16993) {
memcpy(((NCSTRING) (&(*Dest_16992).data[((*Dest_16992).Sup.len)-0])), ((NCSTRING) ((*Src_16993).data)), ((NI32) ((NI64)((NI64)((*Src_16993).Sup.len + 1) * 1))));
(*Dest_16992).Sup.len += (*Src_16993).Sup.len;
}
N_NIMCALL(void, Registerid_49932)(TY48005* Id_49934) {
NIM_BOOL LOC5;
NimStringDesc* LOC9;
NimStringDesc* LOC10;
if (!NIM_FALSE) goto LA2;
LOC5 = ((*Id_49934).Id == -1);
if (LOC5) goto LA6;
LOC5 = Intsetcontainsorincl_49926(&Usedids_49935, (*Id_49934).Id);
LA6: ;
if (!LOC5) goto LA7;
LOC10 = nimIntToStr((*Id_49934).Id);
LOC9 = rawNewString(LOC10->Sup.len + 17);
appendString(LOC9, ((NimStringDesc*) &TMP190894));
appendString(LOC9, LOC10);
Internalerror_41571(LOC9);
LA7: ;
LA2: ;
}
N_NIMCALL(void, Addson_49825)(TY49549* Father_49827, TY49549* Son_49828) {
if (!(*Father_49827).Sons == 0) goto LA2;
asgnRef((void**) &(*Father_49827).Sons, (TY49547*) newSeq(NTI49547, 0));
LA2: ;
(*Father_49827).Sons = (TY49547*) incrSeq(&((*Father_49827).Sons)->Sup, sizeof(TY49549*));
asgnRef((void**) &(*Father_49827).Sons->data[(*Father_49827).Sons->Sup.len-1], Son_49828);
}
N_NIMCALL(void, Idsynchronizationpoint_49696)(NI Idrange_49698) {
Gid_49690 = (NI64)((NI64)((NI64)((NI64)(Gid_49690 / Idrange_49698) + 1) * Idrange_49698) + 1);
}
N_NIMCALL(NIM_BOOL, Intsetcontains_49908)(TY49898* S_49910, NI Key_49911) {
NIM_BOOL Result_52269;
NI U_52270;
TY49894* T_52271;
Result_52269 = 0;
U_52270 = 0;
T_52271 = 0;
T_52271 = Intsetget_52083(S_49910, (NI64)((NU64)(Key_49911) >> (NU64)(9)));
if (!!((T_52271 == NIM_NIL))) goto LA2;
U_52270 = (NI64)(Key_49911 & 511);
Result_52269 = !(((NI64)((*T_52271).Bits[((NI64)((NU64)(U_52270) >> (NU64)(6)))-0] & (NI64)((NU64)(1) << (NU64)((NI64)(U_52270 & 63)))) == 0));
goto LA1;
LA2: ;
Result_52269 = NIM_FALSE;
LA1: ;
return Result_52269;
}
N_NIMCALL(TY49523*, Newsymnode_49732)(TY49545* Sym_49734) {
TY49523* Result_50569;
Result_50569 = 0;
Result_50569 = Newnode_49708(((NU8) 3));
asgnRef((void**) &(*Result_50569).KindU.S4.Sym, Sym_49734);
asgnRef((void**) &(*Result_50569).Typ, (*Sym_49734).Typ);
(*Result_50569).Info = (*Sym_49734).Info;
return Result_50569;
}
N_NIMCALL(TY49523*, Newnodeit_49739)(NU8 Kind_49741, TY41532 Info_49742, TY49549* Typ_49743) {
TY49523* Result_50592;
Result_50592 = 0;
Result_50592 = Newnode_49708(Kind_49741);
(*Result_50592).Info = Info_49742;
asgnRef((void**) &(*Result_50592).Typ, Typ_49743);
return Result_50592;
}
N_NIMCALL(TY49549*, Newtype_49704)(NU8 Kind_49706, TY49545* Owner_49707) {
TY49549* Result_50597;
Result_50597 = 0;
Result_50597 = (TY49549*) newObj(NTI49519, sizeof(TY49549));
(*Result_50597).Sup.Sup.m_type = NTI49549;
(*Result_50597).Kind = Kind_49706;
asgnRef((void**) &(*Result_50597).Owner, Owner_49707);
(*Result_50597).Size = -1;
(*Result_50597).Align = 2;
(*Result_50597).Sup.Id = Getid_49691();
if (!NIM_FALSE) goto LA2;
Registerid_49932(&Result_50597->Sup);
LA2: ;
return Result_50597;
}
N_NIMCALL(void, Newsons_49813)(TY49523* Father_49815, NI Length_49816) {
if (!(*Father_49815).KindU.S6.Sons == 0) goto LA2;
asgnRefNoCycle((void**) &(*Father_49815).KindU.S6.Sons, (TY49517*) newSeq(NTI49517, 0));
LA2: ;
(*Father_49815).KindU.S6.Sons = (TY49517*) setLengthSeq(&((*Father_49815).KindU.S6.Sons)->Sup, sizeof(TY49523*), (NI64)((*Father_49815).KindU.S6.Sons->Sup.len + Length_49816));
}
N_NIMCALL(TY49523*, Copytree_49856)(TY49523* Src_49858) {
TY49523* Result_51504;
NI LOC4;
NI I_51665;
NI HEX3Atmp_51691;
NI LOC5;
NI Res_51693;
Result_51504 = 0;
if (!(Src_49858 == NIM_NIL)) goto LA2;
Result_51504 = NIM_NIL;
goto BeforeRet;
LA2: ;
Result_51504 = Newnode_49708((*Src_49858).Kind);
(*Result_51504).Info = (*Src_49858).Info;
asgnRef((void**) &(*Result_51504).Typ, (*Src_49858).Typ);
(*Result_51504).Flags = ((*Src_49858).Flags & 30);
switch ((*Src_49858).Kind) {
case ((NU8) 5) ... ((NU8) 10):
(*Result_51504).KindU.S1.Intval = (*Src_49858).KindU.S1.Intval;
break;
case ((NU8) 11):
case ((NU8) 12):
case ((NU8) 13):
(*Result_51504).KindU.S2.Floatval = (*Src_49858).KindU.S2.Floatval;
break;
case ((NU8) 3):
asgnRef((void**) &(*Result_51504).KindU.S4.Sym, (*Src_49858).KindU.S4.Sym);
break;
case ((NU8) 2):
asgnRefNoCycle((void**) &(*Result_51504).KindU.S5.Ident, (*Src_49858).KindU.S5.Ident);
break;
case ((NU8) 14) ... ((NU8) 16):
asgnRefNoCycle((void**) &(*Result_51504).KindU.S3.Strval, copyString((*Src_49858).KindU.S3.Strval));
break;
default:
genericSeqAssign(&(*Result_51504).KindU.S6.Sons, NIM_NIL, NTI49517);
LOC4 = Sonslen_49801(Src_49858);
Newsons_49813(Result_51504, LOC4);
I_51665 = 0;
HEX3Atmp_51691 = 0;
LOC5 = Sonslen_49801(Src_49858);
HEX3Atmp_51691 = (NI64)(LOC5 - 1);
Res_51693 = 0;
Res_51693 = 0;
while (1) {
if (!(Res_51693 <= HEX3Atmp_51691)) goto LA6;
I_51665 = Res_51693;
asgnRefNoCycle((void**) &(*Result_51504).KindU.S6.Sons->data[I_51665], Copytree_49856((*Src_49858).KindU.S6.Sons->data[I_51665]));
Res_51693 += 1;
} LA6: ;
break;
}
BeforeRet: ;
return Result_51504;
}
N_NIMCALL(void, Initidnodetable_49760)(TY49567* X_49763) {
(*X_49763).Counter = 0;
unsureAsgnRef((void**) &(*X_49763).Data, (TY49565*) newSeq(NTI49565, 8));
}
N_NIMCALL(TY49523*, Copynode_49853)(TY49523* Src_49855) {
TY49523* Result_51359;
Result_51359 = 0;
if (!(Src_49855 == NIM_NIL)) goto LA2;
Result_51359 = NIM_NIL;
goto BeforeRet;
LA2: ;
Result_51359 = Newnode_49708((*Src_49855).Kind);
(*Result_51359).Info = (*Src_49855).Info;
asgnRef((void**) &(*Result_51359).Typ, (*Src_49855).Typ);
(*Result_51359).Flags = ((*Src_49855).Flags & 30);
switch ((*Src_49855).Kind) {
case ((NU8) 5) ... ((NU8) 10):
(*Result_51359).KindU.S1.Intval = (*Src_49855).KindU.S1.Intval;
break;
case ((NU8) 11):
case ((NU8) 12):
case ((NU8) 13):
(*Result_51359).KindU.S2.Floatval = (*Src_49855).KindU.S2.Floatval;
break;
case ((NU8) 3):
asgnRef((void**) &(*Result_51359).KindU.S4.Sym, (*Src_49855).KindU.S4.Sym);
break;
case ((NU8) 2):
asgnRefNoCycle((void**) &(*Result_51359).KindU.S5.Ident, (*Src_49855).KindU.S5.Ident);
break;
case ((NU8) 14) ... ((NU8) 16):
asgnRefNoCycle((void**) &(*Result_51359).KindU.S3.Strval, copyString((*Src_49855).KindU.S3.Strval));
break;
default:
break;
}
BeforeRet: ;
return Result_51359;
}
N_NIMCALL(NI, Sonslen_49804)(TY49549* N_49806) {
NI Result_50765;
Result_50765 = 0;
if (!(*N_49806).Sons == 0) goto LA2;
Result_50765 = 0;
goto LA1;
LA2: ;
Result_50765 = (*N_49806).Sons->Sup.len;
LA1: ;
return Result_50765;
}
N_NIMCALL(TY49549*, Lastson_49810)(TY49549* N_49812) {
TY49549* Result_51715;
NI LOC1;
Result_51715 = 0;
LOC1 = Sonslen_49804(N_49812);
Result_51715 = (*N_49812).Sons->data[(NI64)(LOC1 - 1)];
return Result_51715;
}
N_NIMCALL(TY49523*, Newintnode_49711)(NU8 Kind_49713, NI64 Intval_49714) {
TY49523* Result_50496;
Result_50496 = 0;
Result_50496 = Newnode_49708(Kind_49713);
(*Result_50496).KindU.S1.Intval = Intval_49714;
return Result_50496;
}
N_NIMCALL(void, Discardsons_49859)(TY49523* Father_49861) {
genericSeqAssign(&(*Father_49861).KindU.S6.Sons, NIM_NIL, NTI49517);
}
static N_INLINE(NI, cmpStrings)(NimStringDesc* A_16811, NimStringDesc* B_16812) {
NI Result_16813;
NI32 LOC10;
Result_16813 = 0;
if (!(A_16811 == B_16812)) goto LA2;
Result_16813 = 0;
goto BeforeRet;
LA2: ;
if (!(A_16811 == NIM_NIL)) goto LA5;
Result_16813 = -1;
goto BeforeRet;
LA5: ;
if (!(B_16812 == NIM_NIL)) goto LA8;
Result_16813 = 1;
goto BeforeRet;
LA8: ;
LOC10 = strcmp(((NCSTRING) ((*A_16811).data)), ((NCSTRING) ((*B_16812).data)));
Result_16813 = ((NI) (LOC10));
goto BeforeRet;
BeforeRet: ;
return Result_16813;
}
N_NIMCALL(NIM_BOOL, Levalue_49868)(TY49523* A_49870, TY49523* B_49871) {
NIM_BOOL Result_49979;
Result_49979 = 0;
Result_49979 = NIM_FALSE;
switch ((*A_49870).Kind) {
case ((NU8) 5) ... ((NU8) 10):
if (!((*B_49871).Kind >= ((NU8) 5) && (*B_49871).Kind <= ((NU8) 10))) goto LA2;
Result_49979 = ((*A_49870).KindU.S1.Intval <= (*B_49871).KindU.S1.Intval);
LA2: ;
break;
case ((NU8) 11) ... ((NU8) 13):
if (!((*B_49871).Kind >= ((NU8) 11) && (*B_49871).Kind <= ((NU8) 13))) goto LA5;
Result_49979 = (((NF) ((*A_49870).KindU.S2.Floatval)) <= ((NF) ((*B_49871).KindU.S2.Floatval)));
LA5: ;
break;
case ((NU8) 14) ... ((NU8) 16):
if (!((*B_49871).Kind >= ((NU8) 14) && (*B_49871).Kind <= ((NU8) 16))) goto LA8;
Result_49979 = (cmpStrings((*A_49870).KindU.S3.Strval, (*B_49871).KindU.S3.Strval) <= 0);
LA8: ;
break;
default:
Internalerror_41567((*A_49870).Info, ((NimStringDesc*) &TMP190956));
break;
}
return Result_49979;
}
static N_INLINE(NIM_BOOL, eqStrings)(NimStringDesc* A_16847, NimStringDesc* B_16848) {
NIM_BOOL Result_16849;
NIM_BOOL LOC5;
NIM_BOOL LOC9;
NI32 LOC11;
Result_16849 = 0;
if (!(A_16847 == B_16848)) goto LA2;
Result_16849 = NIM_TRUE;
goto BeforeRet;
LA2: ;
LOC5 = (A_16847 == NIM_NIL);
if (LOC5) goto LA6;
LOC5 = (B_16848 == NIM_NIL);
LA6: ;
if (!LOC5) goto LA7;
Result_16849 = NIM_FALSE;
goto BeforeRet;
LA7: ;
LOC9 = ((*A_16847).Sup.len == (*B_16848).Sup.len);
if (!(LOC9)) goto LA10;
LOC11 = memcmp(((NCSTRING) ((*A_16847).data)), ((NCSTRING) ((*B_16848).data)), ((NI32) ((NI64)((*A_16847).Sup.len * 1))));
LOC9 = (LOC11 == ((NI32) 0));
LA10: ;
Result_16849 = LOC9;
goto BeforeRet;
BeforeRet: ;
return Result_16849;
}
N_NIMCALL(NIM_BOOL, Samevalue_49864)(TY49523* A_49866, TY49523* B_49867) {
NIM_BOOL Result_50094;
Result_50094 = 0;
Result_50094 = NIM_FALSE;
switch ((*A_49866).Kind) {
case ((NU8) 5) ... ((NU8) 10):
if (!((*B_49867).Kind >= ((NU8) 5) && (*B_49867).Kind <= ((NU8) 10))) goto LA2;
Result_50094 = ((*A_49866).KindU.S1.Intval == (*B_49867).KindU.S1.Intval);
LA2: ;
break;
case ((NU8) 11) ... ((NU8) 13):
if (!((*B_49867).Kind >= ((NU8) 11) && (*B_49867).Kind <= ((NU8) 13))) goto LA5;
Result_50094 = (((NF) ((*A_49866).KindU.S2.Floatval)) == ((NF) ((*B_49867).KindU.S2.Floatval)));
LA5: ;
break;
case ((NU8) 14) ... ((NU8) 16):
if (!((*B_49867).Kind >= ((NU8) 14) && (*B_49867).Kind <= ((NU8) 16))) goto LA8;
Result_50094 = eqStrings((*A_49866).KindU.S3.Strval, (*B_49867).KindU.S3.Strval);
LA8: ;
break;
default:
Internalerror_41567((*A_49866).Info, ((NimStringDesc*) &TMP190957));
break;
}
return Result_50094;
}
N_NIMCALL(TY49523*, Newinttypenode_49715)(NU8 Kind_49717, NI64 Intval_49718, TY49549* Typ_49719) {
TY49523* Result_50514;
Result_50514 = 0;
Result_50514 = Newintnode_49711(Kind_49717, Intval_49718);
asgnRef((void**) &(*Result_50514).Typ, Typ_49719);
return Result_50514;
}
N_NIMCALL(void, Delson_49833)(TY49523* Father_49835, NI Idx_49836) {
NI Length_51293;
NI I_51301;
NI HEX3Atmp_51351;
NI Res_51353;
if (!(*Father_49835).KindU.S6.Sons == 0) goto LA2;
goto BeforeRet;
LA2: ;
Length_51293 = 0;
Length_51293 = Sonslen_49801(Father_49835);
I_51301 = 0;
HEX3Atmp_51351 = 0;
HEX3Atmp_51351 = (NI64)(Length_51293 - 2);
Res_51353 = 0;
Res_51353 = Idx_49836;
while (1) {
if (!(Res_51353 <= HEX3Atmp_51351)) goto LA4;
I_51301 = Res_51353;
asgnRefNoCycle((void**) &(*Father_49835).KindU.S6.Sons->data[I_51301], (*Father_49835).KindU.S6.Sons->data[(NI64)(I_51301 + 1)]);
Res_51353 += 1;
} LA4: ;
(*Father_49835).KindU.S6.Sons = (TY49517*) setLengthSeq(&((*Father_49835).KindU.S6.Sons)->Sup, sizeof(TY49523*), (NI64)(Length_51293 - 1));
BeforeRet: ;
}
N_NIMCALL(TY49523*, Newstrnode_49724)(NU8 Kind_49726, NimStringDesc* Strval_49727) {
TY49523* Result_50536;
Result_50536 = 0;
Result_50536 = Newnode_49708(Kind_49726);
asgnRefNoCycle((void**) &(*Result_50536).KindU.S3.Strval, copyString(Strval_49727));
return Result_50536;
}
N_NIMCALL(NI64, Getint_51971)(TY49523* A_51973) {
NI64 Result_51974;
Result_51974 = 0;
switch ((*A_51973).Kind) {
case ((NU8) 6) ... ((NU8) 10):
Result_51974 = (*A_51973).KindU.S1.Intval;
break;
default:
Internalerror_41567((*A_51973).Info, ((NimStringDesc*) &TMP190973));
Result_51974 = 0;
break;
}
return Result_51974;
}
N_NIMCALL(TY49523*, Newfloatnode_49720)(NU8 Kind_49722, NF64 Floatval_49723) {
TY49523* Result_50519;
Result_50519 = 0;
Result_50519 = Newnode_49708(Kind_49722);
(*Result_50519).KindU.S2.Floatval = Floatval_49723;
return Result_50519;
}
N_NIMCALL(NF64, Getfloat_51987)(TY49523* A_51989) {
NF64 Result_51990;
Result_51990 = 0;
switch ((*A_51989).Kind) {
case ((NU8) 11) ... ((NU8) 13):
Result_51990 = (*A_51989).KindU.S2.Floatval;
break;
default:
Internalerror_41567((*A_51989).Info, ((NimStringDesc*) &TMP190974));
Result_51990 = 0.000000;
break;
}
return Result_51990;
}
N_NIMCALL(NimStringDesc*, Getstr_52003)(TY49523* A_52005) {
NimStringDesc* Result_52006;
Result_52006 = 0;
switch ((*A_52005).Kind) {
case ((NU8) 14) ... ((NU8) 16):
Result_52006 = copyString((*A_52005).KindU.S3.Strval);
break;
default:
Internalerror_41567((*A_52005).Info, ((NimStringDesc*) &TMP190975));
Result_52006 = copyString(((NimStringDesc*) &TMP49019));
break;
}
return Result_52006;
}
static N_INLINE(void, appendChar)(NimStringDesc* Dest_17009, NIM_CHAR C_17010) {
(*Dest_17009).data[((*Dest_17009).Sup.len)-0] = C_17010;
(*Dest_17009).data[((NI64)((*Dest_17009).Sup.len + 1))-0] = 0;
(*Dest_17009).Sup.len += 1;
}
N_NIMCALL(NimStringDesc*, Getstrorchar_52019)(TY49523* A_52021) {
NimStringDesc* Result_52022;
NimStringDesc* LOC1;
Result_52022 = 0;
switch ((*A_52021).Kind) {
case ((NU8) 14) ... ((NU8) 16):
Result_52022 = copyString((*A_52021).KindU.S3.Strval);
break;
case ((NU8) 5):
LOC1 = rawNewString(1);
appendChar(LOC1, ((NIM_CHAR) (((NI) (((NI) ((*A_52021).KindU.S1.Intval)))))));
appendString(LOC1, ((NimStringDesc*) &TMP49019));
Result_52022 = LOC1;
break;
default:
Internalerror_41567((*A_52021).Info, ((NimStringDesc*) &TMP190977));
Result_52022 = copyString(((NimStringDesc*) &TMP49019));
break;
}
return Result_52022;
}
N_NIMCALL(NimStringDesc*, Valuetostring_49872)(TY49523* A_49874) {
NimStringDesc* Result_50208;
Result_50208 = 0;
switch ((*A_49874).Kind) {
case ((NU8) 5) ... ((NU8) 10):
Result_50208 = nimInt64ToStr((*A_49874).KindU.S1.Intval);
break;
case ((NU8) 11):
case ((NU8) 12):
case ((NU8) 13):
Result_50208 = nimFloatToStr(((NF) ((*A_49874).KindU.S2.Floatval)));
break;
case ((NU8) 14) ... ((NU8) 16):
Result_50208 = copyString((*A_49874).KindU.S3.Strval);
break;
default:
Internalerror_41567((*A_49874).Info, ((NimStringDesc*) &TMP191044));
Result_50208 = copyString(((NimStringDesc*) &TMP49019));
break;
}
return Result_50208;
}
N_NIMCALL(TY49523*, Newidentnode_49728)(TY48011* Ident_49730, TY41532 Info_49731) {
TY49523* Result_50553;
Result_50553 = 0;
Result_50553 = Newnode_49708(((NU8) 2));
asgnRefNoCycle((void**) &(*Result_50553).KindU.S5.Ident, Ident_49730);
(*Result_50553).Info = Info_49731;
return Result_50553;
}
N_NIMCALL(void, Copyidtable_49796)(TY49561* Dest_49799, TY49561 Src_49800) {
NI I_50353;
NI HEX3Atmp_50355;
NI Res_50357;
(*Dest_49799).Counter = Src_49800.Counter;
if (!Src_49800.Data == 0) goto LA2;
goto BeforeRet;
LA2: ;
unsureAsgnRef((void**) &(*Dest_49799).Data, (TY49559*) newSeq(NTI49559, Src_49800.Data->Sup.len));
I_50353 = 0;
HEX3Atmp_50355 = 0;
HEX3Atmp_50355 = (Src_49800.Data->Sup.len-1);
Res_50357 = 0;
Res_50357 = 0;
while (1) {
if (!(Res_50357 <= HEX3Atmp_50355)) goto LA4;
I_50353 = Res_50357;
genericAssign((void*)&(*Dest_49799).Data->data[I_50353], (void*)&Src_49800.Data->data[I_50353], NTI49557);
Res_50357 += 1;
} LA4: ;
BeforeRet: ;
}
N_NIMCALL(void, Newsons_49817)(TY49549* Father_49819, NI Length_49820) {
if (!(*Father_49819).Sons == 0) goto LA2;
asgnRef((void**) &(*Father_49819).Sons, (TY49547*) newSeq(NTI49547, 0));
LA2: ;
(*Father_49819).Sons = (TY49547*) setLengthSeq(&((*Father_49819).Sons)->Sup, sizeof(TY49549*), (NI64)((*Father_49819).Sons->Sup.len + Length_49820));
}
N_NIMCALL(void, Assigntype_49777)(TY49549* Dest_49779, TY49549* Src_49780) {
NI LOC1;
NI I_50624;
NI HEX3Atmp_50626;
NI LOC2;
NI Res_50628;
(*Dest_49779).Kind = (*Src_49780).Kind;
(*Dest_49779).Flags = (*Src_49780).Flags;
(*Dest_49779).Callconv = (*Src_49780).Callconv;
asgnRefNoCycle((void**) &(*Dest_49779).N, (*Src_49780).N);
(*Dest_49779).Size = (*Src_49780).Size;
(*Dest_49779).Align = (*Src_49780).Align;
(*Dest_49779).Containerid = (*Src_49780).Containerid;
LOC1 = Sonslen_49804(Src_49780);
Newsons_49817(Dest_49779, LOC1);
I_50624 = 0;
HEX3Atmp_50626 = 0;
LOC2 = Sonslen_49804(Src_49780);
HEX3Atmp_50626 = (NI64)(LOC2 - 1);
Res_50628 = 0;
Res_50628 = 0;
while (1) {
if (!(Res_50628 <= HEX3Atmp_50626)) goto LA3;
I_50624 = Res_50628;
asgnRef((void**) &(*Dest_49779).Sons->data[I_50624], (*Src_49780).Sons->data[I_50624]);
Res_50628 += 1;
} LA3: ;
}
N_NIMCALL(TY49549*, Copytype_49768)(TY49549* T_49770, TY49545* Owner_49771, NIM_BOOL Keepid_49772) {
TY49549* Result_50636;
Result_50636 = 0;
Result_50636 = Newtype_49704((*T_49770).Kind, Owner_49771);
Assigntype_49777(Result_50636, T_49770);
if (!Keepid_49772) goto LA2;
(*Result_50636).Sup.Id = (*T_49770).Sup.Id;
goto LA1;
LA2: ;
(*Result_50636).Sup.Id = Getid_49691();
if (!NIM_FALSE) goto LA5;
Registerid_49932(&Result_50636->Sup);
LA5: ;
LA1: ;
asgnRef((void**) &(*Result_50636).Sym, (*T_49770).Sym);
return Result_50636;
}
N_NIMCALL(TY49545*, Newsym_49699)(NU8 Symkind_49701, TY48011* Name_49702, TY49545* Owner_49703) {
TY49545* Result_50648;
Result_50648 = 0;
Result_50648 = (TY49545*) newObj(NTI49521, sizeof(TY49545));
objectInit(Result_50648, NTI49545);
asgnRefNoCycle((void**) &(*Result_50648).Name, Name_49702);
(*Result_50648).Kind = Symkind_49701;
(*Result_50648).Flags = 0;
(*Result_50648).Info = Unknownlineinfo_41536();
(*Result_50648).Options = Goptions_40075;
asgnRef((void**) &(*Result_50648).Owner, Owner_49703);
(*Result_50648).Offset = -1;
(*Result_50648).Sup.Id = Getid_49691();
if (!NIM_FALSE) goto LA2;
Registerid_49932(&Result_50648->Sup);
LA2: ;
return Result_50648;
}
N_NIMCALL(void, Copystrtable_49781)(TY49527* Dest_49784, TY49527* Src_49785) {
NI I_50304;
NI HEX3Atmp_50306;
NI Res_50308;
(*Dest_49784).Counter = (*Src_49785).Counter;
if (!(*Src_49785).Data == 0) goto LA2;
goto BeforeRet;
LA2: ;
(*Dest_49784).Data = (TY49525*) setLengthSeq(&((*Dest_49784).Data)->Sup, sizeof(TY49545*), (*Src_49785).Data->Sup.len);
I_50304 = 0;
HEX3Atmp_50306 = 0;
HEX3Atmp_50306 = ((*Src_49785).Data->Sup.len-1);
Res_50308 = 0;
Res_50308 = 0;
while (1) {
if (!(Res_50308 <= HEX3Atmp_50306)) goto LA4;
I_50304 = Res_50308;
asgnRef((void**) &(*Dest_49784).Data->data[I_50304], (*Src_49785).Data->data[I_50304]);
Res_50308 += 1;
} LA4: ;
BeforeRet: ;
}
N_NIMCALL(TY49545*, Copysym_49773)(TY49545* S_49775, NIM_BOOL Keepid_49776) {
TY49545* Result_50641;
Result_50641 = 0;
Result_50641 = Newsym_49699((*S_49775).Kind, (*S_49775).Name, (*S_49775).Owner);
asgnRefNoCycle((void**) &(*Result_50641).Ast, NIM_NIL);
(*Result_50641).Info = (*S_49775).Info;
asgnRef((void**) &(*Result_50641).Typ, (*S_49775).Typ);
if (!Keepid_49776) goto LA2;
(*Result_50641).Sup.Id = (*S_49775).Sup.Id;
goto LA1;
LA2: ;
(*Result_50641).Sup.Id = Getid_49691();
if (!NIM_FALSE) goto LA5;
Registerid_49932(&Result_50641->Sup);
LA5: ;
LA1: ;
(*Result_50641).Flags = (*S_49775).Flags;
(*Result_50641).Magic = (*S_49775).Magic;
Copystrtable_49781(&(*Result_50641).Tab, &(*S_49775).Tab);
(*Result_50641).Options = (*S_49775).Options;
(*Result_50641).Position = (*S_49775).Position;
genericAssign((void*)&(*Result_50641).Loc, (void*)&(*S_49775).Loc, NTI49537);
asgnRefNoCycle((void**) &(*Result_50641).Annex, (*S_49775).Annex);
return Result_50641;
}
N_NIMCALL(void, Add_50990)(TY49523* Father_50992, TY49523* Son_50993) {
if (!(*Father_50992).KindU.S6.Sons == 0) goto LA2;
asgnRefNoCycle((void**) &(*Father_50992).KindU.S6.Sons, (TY49517*) newSeq(NTI49517, 0));
LA2: ;
(*Father_50992).KindU.S6.Sons = (TY49517*) incrSeq(&((*Father_50992).KindU.S6.Sons)->Sup, sizeof(TY49523*));
asgnRefNoCycle((void**) &(*Father_50992).KindU.S6.Sons->data[(*Father_50992).KindU.S6.Sons->Sup.len-1], Son_50993);
}
N_NIMCALL(void, Addsonifnotnil_49829)(TY49523* Father_49831, TY49523* N_49832) {
if (!!((N_49832 == NIM_NIL))) goto LA2;
Addson_49821(Father_49831, N_49832);
LA2: ;
}
N_NIMCALL(void, Intsetexcl_49917)(TY49898* S_49920, NI Key_49921) {
NI U_52297;
TY49894* T_52298;
U_52297 = 0;
T_52298 = 0;
T_52298 = Intsetget_52083(&(*S_49920), (NI64)((NU64)(Key_49921) >> (NU64)(9)));
if (!!((T_52298 == NIM_NIL))) goto LA2;
U_52297 = (NI64)(Key_49921 & 511);
(*T_52298).Bits[((NI64)((NU64)(U_52297) >> (NU64)(6)))-0] = (NI64)((*T_52298).Bits[((NI64)((NU64)(U_52297) >> (NU64)(6)))-0] & (NI64)((NU64) ~((NI64)((NU64)(1) << (NU64)((NI64)(U_52297 & 63))))));
LA2: ;
}
N_NIMCALL(void, Initnodetable_49764)(TY49573* X_49767) {
(*X_49767).Counter = 0;
unsureAsgnRef((void**) &(*X_49767).Data, (TY49571*) newSeq(NTI49571, 8));
}
N_NOINLINE(void, astInit)(void) {
if (!NIM_FALSE) goto LA2;
Intsetinit_49922(&Usedids_49935);
LA2: ;
}
