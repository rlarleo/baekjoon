#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <stdlib.h>
#include <limits.h>
#include <cmath>
#include <queue>

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);
   
    int N;
    int S, M, L, XL, XXL, XXXL;
    int T, P;

    cin >> N;
    cin >> S >> M >> L >> XL >> XXL >> XXXL;
    cin >> T >> P;

    int resultT = S / T;
    if(S % T != 0) resultT ++;

    resultT += M / T;
    if(M % T != 0) resultT ++;

    resultT += L / T;
    if(L % T != 0) resultT ++;

    resultT += XL / T;
    if(XL % T != 0) resultT ++;

    resultT += XXL / T;
    if(XXL % T != 0) resultT ++;

    resultT += XXXL / T;
    if(XXXL % T != 0) resultT ++;

    cout << resultT << '\n' << N / P << ' ' << N % P;
    return 0;
}