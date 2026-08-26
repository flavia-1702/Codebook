#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
const int mod = 1e9 + 7;
 
ll potencia(int a, int b);

// Exponenciação
 
int main(){
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
 
    int n;
    cin >> n;
 
    while(n--){
        ll a, b;
        cin >> a >> b;
 
        cout << potencia(a, b) << "\n";
    }
 
    return 0;
}

ll potencia(int a, int b){
    if(b == 0)
        return 1;
    
    ll resultado = potencia(a, b/2);
    if(b % 2 == 1)
        return (((resultado * resultado) % mod) * a) % mod;
    else
        return (resultado * resultado) % mod;
}
