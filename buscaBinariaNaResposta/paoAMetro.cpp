#include <bits/stdc++.h>
using namespace std;

// Pão a metro

const int MAX = 1e4+10;

int N, K;
int paes[MAX];

bool possivel(int m){
    int qtde = 0;
    for(int i = 0; i < K; i++){
        if(paes[i] >= m){
            qtde += paes[i] / m;
        }
        if(qtde >= N){
            return true;
        }
    }

    return false;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> K;
    for(int i = 0; i < K; i++)
        cin >> paes[i];
    
    int ini = 1, fim = 10000;

    while(ini < fim){
        int m = (ini + fim + 1) / 2;
        if(!possivel(m)) fim = m - 1;
        else ini = m;
    }

    cout << ini << "\n";

    return 0;
}
