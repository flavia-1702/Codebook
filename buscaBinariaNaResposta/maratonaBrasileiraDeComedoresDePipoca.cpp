#include <bits/stdc++.h>
using namespace std;

// Maratona brasileira de comedores de pipoca

typedef long long ll;

const int MAX = 1e5+10;

ll N, C, T;
int pipocas[MAX];

bool possivel(ll chute){
    int competidores = 1;
    ll resta = chute * T;

    for(int i = 0; i < N; i++){
        if(resta >= pipocas[i]) resta -= pipocas[i];
        else{
            competidores++;
            resta = T * chute;
            i--;
        }

        if(competidores > C)
            return 0;
    }

    return 1;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> C >> T;
    for(ll i = 0; i < N; i++) cin >> pipocas[i];

    int l = 0, r = 1e9+1;
    while(l < r){
        int m = (l+r) / 2;
        if(!possivel(m)) l = m+1;
        else r = m;
    }

    cout << r << "\n";

    return 0;
}
