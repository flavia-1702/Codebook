#include <bits/stdc++.h>
using namespace std;

// Cápsulas

typedef long long ll;

const int MAX = 1e8+10;
const int MAX2 = 100000 + 10;

int N, F;
int ciclos[MAX2];

bool possivel(int m){
    int total = 0;
    for(int i = 0; i < N; i++){
        total += m / ciclos[i];
        if(total >= F)
            return true;
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> F;
    for(int i = 0; i < N; i++) cin >> ciclos[i];

    int ini = 1, fim = MAX;
    while(ini < fim){
        int m = (ini+fim) / 2;
        if(!possivel(m)) ini = m + 1;
        else fim = m;
    }

    cout << fim << "\n";

    return 0;
}
