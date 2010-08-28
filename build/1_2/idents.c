/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long long int NI;
typedef unsigned long long int NU;
#include "nimbase.h"

typedef struct TY48011 TY48011;
typedef struct NimStringDesc NimStringDesc;
typedef struct TGenericSeq TGenericSeq;
typedef struct TY48005 TY48005;
typedef struct TNimObject TNimObject;
typedef struct TNimType TNimType;
typedef struct TNimNode TNimNode;
typedef struct TY10202 TY10202;
typedef struct TY10218 TY10218;
typedef struct TY10590 TY10590;
typedef struct TY10214 TY10214;
typedef struct TY10210 TY10210;
typedef struct TY10588 TY10588;
typedef TY48011* TY48039[8192];
struct TGenericSeq {
NI len;
NI space;
};
typedef NIM_CHAR TY239[100000001];
struct NimStringDesc {
  TGenericSeq Sup;
TY239 data;
};
struct TNimType {
NI size;
NU8 kind;
NU8 flags;
TNimType* base;
TNimNode* node;
void* finalizer;
};
struct TNimObject {
TNimType* m_type;
};
struct TY48005 {
  TNimObject Sup;
NI Id;
};
struct TY48011 {
  TY48005 Sup;
NimStringDesc* S;
TY48011* Next;
NI H;
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
struct TNimNode {
NU8 kind;
NI offset;
TNimType* typ;
NCSTRING name;
NI len;
TNimNode** sons;
};
typedef NI TY8214[8];
struct TY10210 {
TY10210* Next;
NI Key;
TY8214 Bits;
};
N_NIMCALL(TY48011*, Getident_48023)(NCSTRING Identifier_48025, NI Length_48026, NI H_48027);
N_NIMCALL(NI, Cmpexact_48165)(NCSTRING A_48167, NCSTRING B_48168, NI Blen_48169);
static N_INLINE(void, asgnRefNoCycle)(void** Dest_11416, void* Src_11417);
static N_INLINE(TY10202*, Usrtocell_10622)(void* Usr_10624);
static N_INLINE(void, Rtladdzct_11256)(TY10202* C_11258);
N_NOINLINE(void, Addzct_10611)(TY10218* S_10614, TY10202* C_10615);
N_NIMCALL(NI, Cmpignorestyle_48042)(NCSTRING A_48044, NCSTRING B_48045, NI Blen_48046);
N_NIMCALL(void*, newObj)(TNimType* Typ_11907, NI Size_11908);
N_NIMCALL(NimStringDesc*, mnewString)(NI Len_1347);
N_NIMCALL(NI, Getnormalizedhash_38037)(NimStringDesc* S_38039);
N_NIMCALL(TY48011*, Getident_48016)(NimStringDesc* Identifier_48018);
TY48039 Buckets_48041;
NI Wordcounter_48233;
extern TY10590 Gch_10608;
extern TNimType* NTI48009; /* PIdent */
extern TNimType* NTI48011; /* TIdent */
N_NIMCALL(NI, Cmpexact_48165)(NCSTRING A_48167, NCSTRING B_48168, NI Blen_48169) {
NI Result_48170;
NIM_CHAR Aa_48171;
NIM_CHAR Bb_48172;
NI I_48173;
NI J_48174;
NIM_BOOL LOC3;
Result_48170 = 0;
Aa_48171 = 0;
Bb_48172 = 0;
I_48173 = 0;
J_48174 = 0;
I_48173 = 0;
J_48174 = 0;
Result_48170 = 1;
while (1) {
if (!(J_48174 < Blen_48169)) goto LA1;
Aa_48171 = A_48167[I_48173];
Bb_48172 = B_48168[J_48174];
Result_48170 = (NI64)(((NU8)(Aa_48171)) - ((NU8)(Bb_48172)));
LOC3 = !((Result_48170 == 0));
if (LOC3) goto LA4;
LOC3 = ((NU8)(Aa_48171) == (NU8)(0));
LA4: ;
if (!LOC3) goto LA5;
goto LA1;
LA5: ;
I_48173 += 1;
J_48174 += 1;
} LA1: ;
if (!(Result_48170 == 0)) goto LA8;
if (!!(((NU8)(A_48167[I_48173]) == (NU8)(0)))) goto LA11;
Result_48170 = 1;
LA11: ;
LA8: ;
return Result_48170;
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
N_NIMCALL(NI, Cmpignorestyle_48042)(NCSTRING A_48044, NCSTRING B_48045, NI Blen_48046) {
NI Result_48047;
NIM_CHAR Aa_48048;
NIM_CHAR Bb_48049;
NI I_48050;
NI J_48051;
NIM_BOOL LOC5;
NIM_BOOL LOC10;
NIM_BOOL LOC15;
Result_48047 = 0;
Aa_48048 = 0;
Bb_48049 = 0;
I_48050 = 0;
J_48051 = 0;
I_48050 = 0;
J_48051 = 0;
Result_48047 = 1;
while (1) {
if (!(J_48051 < Blen_48046)) goto LA1;
while (1) {
if (!((NU8)(A_48044[I_48050]) == (NU8)(95))) goto LA2;
I_48050 += 1;
} LA2: ;
while (1) {
if (!((NU8)(B_48045[J_48051]) == (NU8)(95))) goto LA3;
J_48051 += 1;
} LA3: ;
Aa_48048 = A_48044[I_48050];
Bb_48049 = B_48045[J_48051];
LOC5 = ((NU8)(65) <= (NU8)(Aa_48048));
if (!(LOC5)) goto LA6;
LOC5 = ((NU8)(Aa_48048) <= (NU8)(90));
LA6: ;
if (!LOC5) goto LA7;
Aa_48048 = ((NIM_CHAR) (((NI) ((NI64)(((NU8)(Aa_48048)) + 32)))));
LA7: ;
LOC10 = ((NU8)(65) <= (NU8)(Bb_48049));
if (!(LOC10)) goto LA11;
LOC10 = ((NU8)(Bb_48049) <= (NU8)(90));
LA11: ;
if (!LOC10) goto LA12;
Bb_48049 = ((NIM_CHAR) (((NI) ((NI64)(((NU8)(Bb_48049)) + 32)))));
LA12: ;
Result_48047 = (NI64)(((NU8)(Aa_48048)) - ((NU8)(Bb_48049)));
LOC15 = !((Result_48047 == 0));
if (LOC15) goto LA16;
LOC15 = ((NU8)(Aa_48048) == (NU8)(0));
LA16: ;
if (!LOC15) goto LA17;
goto LA1;
LA17: ;
I_48050 += 1;
J_48051 += 1;
} LA1: ;
if (!(Result_48047 == 0)) goto LA20;
if (!!(((NU8)(A_48044[I_48050]) == (NU8)(0)))) goto LA23;
Result_48047 = 1;
LA23: ;
LA20: ;
return Result_48047;
}
N_NIMCALL(TY48011*, Getident_48023)(NCSTRING Identifier_48025, NI Length_48026, NI H_48027) {
TY48011* Result_48239;
NI Idx_48240;
NI Id_48241;
TY48011* Last_48242;
NI LOC3;
NI LOC9;
NI I_48310;
NI HEX3Atmp_48327;
NI Res_48329;
Result_48239 = 0;
Idx_48240 = 0;
Id_48241 = 0;
Last_48242 = 0;
Idx_48240 = (NI64)(H_48027 & 8191);
Result_48239 = Buckets_48041[(Idx_48240)-0];
Last_48242 = NIM_NIL;
Id_48241 = 0;
while (1) {
if (!!((Result_48239 == NIM_NIL))) goto LA1;
LOC3 = Cmpexact_48165((*Result_48239).S->data, Identifier_48025, Length_48026);
if (!(LOC3 == 0)) goto LA4;
if (!!((Last_48242 == NIM_NIL))) goto LA7;
asgnRefNoCycle((void**) &(*Last_48242).Next, (*Result_48239).Next);
asgnRefNoCycle((void**) &(*Result_48239).Next, Buckets_48041[(Idx_48240)-0]);
asgnRefNoCycle((void**) &Buckets_48041[(Idx_48240)-0], Result_48239);
LA7: ;
goto BeforeRet;
goto LA2;
LA4: ;
LOC9 = Cmpignorestyle_48042((*Result_48239).S->data, Identifier_48025, Length_48026);
if (!(LOC9 == 0)) goto LA10;
Id_48241 = (*Result_48239).Sup.Id;
goto LA2;
LA10: ;
LA2: ;
Last_48242 = Result_48239;
Result_48239 = (*Result_48239).Next;
} LA1: ;
Result_48239 = (TY48011*) newObj(NTI48009, sizeof(TY48011));
(*Result_48239).Sup.Sup.m_type = NTI48011;
(*Result_48239).H = H_48027;
asgnRefNoCycle((void**) &(*Result_48239).S, mnewString(Length_48026));
I_48310 = 0;
HEX3Atmp_48327 = 0;
HEX3Atmp_48327 = (NI64)((NI64)(Length_48026 + 0) - 1);
Res_48329 = 0;
Res_48329 = 0;
while (1) {
if (!(Res_48329 <= HEX3Atmp_48327)) goto LA12;
I_48310 = Res_48329;
(*Result_48239).S->data[I_48310] = Identifier_48025[(NI64)(I_48310 - 0)];
Res_48329 += 1;
} LA12: ;
asgnRefNoCycle((void**) &(*Result_48239).Next, Buckets_48041[(Idx_48240)-0]);
asgnRefNoCycle((void**) &Buckets_48041[(Idx_48240)-0], Result_48239);
if (!(Id_48241 == 0)) goto LA14;
Wordcounter_48233 += 1;
(*Result_48239).Sup.Id = ((NI64)-(Wordcounter_48233));
goto LA13;
LA14: ;
(*Result_48239).Sup.Id = Id_48241;
LA13: ;
BeforeRet: ;
return Result_48239;
}
N_NIMCALL(TY48011*, Getident_48019)(NimStringDesc* Identifier_48021, NI H_48022) {
TY48011* Result_48230;
Result_48230 = 0;
Result_48230 = Getident_48023(Identifier_48021->data, Identifier_48021->Sup.len, H_48022);
return Result_48230;
}
N_NIMCALL(TY48011*, Getident_48016)(NimStringDesc* Identifier_48018) {
TY48011* Result_48223;
NI LOC1;
Result_48223 = 0;
LOC1 = Getnormalizedhash_38037(Identifier_48018);
Result_48223 = Getident_48023(Identifier_48018->data, Identifier_48018->Sup.len, LOC1);
return Result_48223;
}
N_NIMCALL(NIM_BOOL, Identeq_48028)(TY48011* Id_48030, NimStringDesc* Name_48031) {
NIM_BOOL Result_48036;
TY48011* LOC1;
Result_48036 = 0;
LOC1 = Getident_48016(Name_48031);
Result_48036 = ((*Id_48030).Sup.Id == (*LOC1).Sup.Id);
return Result_48036;
}
N_NOINLINE(void, identsInit)(void) {
Wordcounter_48233 = 1;
}
