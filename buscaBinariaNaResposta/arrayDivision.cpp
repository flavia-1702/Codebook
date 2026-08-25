#include <bits/stdc++.h>
using namespace std;

// Array Division
 
typedef long long ll;
 
ll n, k;
vector<ll> vet;
 
bool possible(ll m){
    ll soma = 0, partes = 1;
 
    for(ll i = 0; i < vet.size(); i++){
        if(soma+vet[i] <= m)
            soma += vet[i];
        else{
            partes++;
            soma = vet[i];
        }
    }
 
    return partes <= k;
}
 
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
 
    cin >> n >> k;
 
    vet.resize(n);
    ll ini = 0, fim = 0;
    for(ll i = 0; i < n; i++){ 
        cin >> vet[i];
        fim += vet[i];
        ini = max(ini, vet[i]);
    }
 
    while(ini < fim){
        ll m = (ini+fim)/2;
        if(!possible(m)) ini = m+1;
        else fim = m;
    }
 
    cout << fim << "\n";
 
    return 0;
}
