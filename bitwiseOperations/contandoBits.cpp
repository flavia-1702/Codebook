#include <bits/stdc++.h>
using namespace std;

// Contando bits

typedef long long ll;

int main(){
    ll n; cin >> n;
    ll total = 0;
// n = 6 -> 7
// full = 0
// r = 7
// cycle = 8
    for(ll bit = 1; bit <= n; bit *= 2){ // bit é a quantidade de 1 que tem naquele ciclo
        ll cycle = bit*2; // quantidade de números do ciclo

        ll full = (n+1)/cycle; // quantos ciclos completos
        ll r = (n+1)%cycle; // quantos bits sobraram

        total += full * bit;
        ll zero = 0;
        total += max(zero, r - bit);
    }

    cout << total << '\n';

    return 0;
}
