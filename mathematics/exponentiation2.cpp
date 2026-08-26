#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Exponenciação 2

const int mod = 1e9 + 7;

ll potencia(ll a, ll b, ll m);

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    while(n--){
        ll a, b, c;
        cin >> a >> b >> c;

        ll expoente = potencia(b, c, mod-1);

        cout << potencia(a, expoente, mod) << "\n";
    }

    return 0;
}

ll potencia(ll a, ll b, ll m){
    if(b == 0)
        return 1;

    ll resultado = potencia(a, b / 2, m);

    if(b % 2 == 1)
        return (((resultado * resultado) % m) * a) % m;
    else
        return (resultado * resultado) % m;
}
