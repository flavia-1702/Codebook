#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Soma máxima do subarray

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n; cin >> n;

    vector<ll> v(n);
    for(int i = 0; i < n; i++) cin >> v[i];

    ll soma = v[0];
    ll resp = v[0];

    for(int i = 1; i < n; i++){
        soma = max(v[i], soma + v[i]);
        resp = max(resp, soma);
    }

    cout << resp << "\n";

    return 0;
}
