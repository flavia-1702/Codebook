#include <bits/stdc++.h>
using namespace std;

// Clientes do restaurante

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n; cin >> n;
    map<int, int> m;

    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        m[a] += 1;
        m[b] += -1;
    }

    int resp = 0, aux = 0;
    for(auto it = m.begin(); it != m.end(); it++){
        aux += it->second;
        resp = max(resp, aux);
    }

    cout << resp << "\n";

    return 0;
}
