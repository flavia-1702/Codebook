#include <bits/stdc++.h>
using namespace std;

// Coeficientes binomiais

typedef long long ll;

const int mod = 1e9+7;
const int MAX = 1e6;

ll potencia(ll a, ll b);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    // Calcula os fatoriais
    vector<ll> fat(MAX+1);

    fat[0] = 1;

    for(int i = 1; i <= MAX; i++)
        fat[i] = (fat[i-1]*i) % mod;

    int n;
    cin >> n;

    while(n--){
        int a, b;
        cin >> a >> b;

        ll resultado = fat[a];

        resultado = (resultado * potencia(fat[b], mod-2)) % mod;

        resultado = (resultado * potencia(fat[a-b], mod-2)) % mod;

        cout << resultado << "\n";
    }

    return 0;
}

ll potencia(ll a, ll b){
    if(b == 0)
        return 1;

    ll resultado = potencia(a, b/2);

    if(b % 2 == 1)
        return (((resultado * resultado) % mod) * a) % mod;
    else
        return (resultado * resultado) % mod;
}
