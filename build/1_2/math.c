/* Generated by Nimrod Compiler v0.8.9 */
/*   (c) 2010 Andreas Rumpf */

typedef long long int NI;
typedef unsigned long long int NU;
#include "nimbase.h"

N_NIMCALL(NIM_BOOL, Ispoweroftwo_94270)(NI X_94272) {
NIM_BOOL Result_94273;
Result_94273 = 0;
Result_94273 = ((NI64)(X_94272 & ((NI64)-(X_94272))) == X_94272);
goto BeforeRet;
BeforeRet: ;
return Result_94273;
}
N_NIMCALL(NI, Nextpoweroftwo_94276)(NI X_94278) {
NI Result_94279;
Result_94279 = 0;
Result_94279 = (NI64)(X_94278 - 1);
Result_94279 = (NI64)(Result_94279 | (NI64)((NU64)(Result_94279) >> (NU64)(32)));
Result_94279 = (NI64)(Result_94279 | (NI64)((NU64)(Result_94279) >> (NU64)(16)));
Result_94279 = (NI64)(Result_94279 | (NI64)((NU64)(Result_94279) >> (NU64)(8)));
Result_94279 = (NI64)(Result_94279 | (NI64)((NU64)(Result_94279) >> (NU64)(4)));
Result_94279 = (NI64)(Result_94279 | (NI64)((NU64)(Result_94279) >> (NU64)(2)));
Result_94279 = (NI64)(Result_94279 | (NI64)((NU64)(Result_94279) >> (NU64)(1)));
Result_94279 += 1;
return Result_94279;
}
N_NOINLINE(void, mathInit)(void) {
}
