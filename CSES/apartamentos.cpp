
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Apartamentos

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    ll n, m, k;
    cin >> n >> m >> k;

    vector<ll> pessoas(n);
    vector<ll> apartamentos(m);

    for(ll i = 0; i < n; i++) cin >> pessoas[i];
    for(ll i = 0; i < m; i++) cin >> apartamentos[i];

    sort(pessoas.begin(), pessoas.end());
    sort(apartamentos.begin(), apartamentos.end());

    ll resp = 0, i = 0, j = 0;
    while(i < n && j < m){
        if(pessoas[i] - k > apartamentos[j])
            j++;
        else{
            if(pessoas[i] + k < apartamentos[j])
                i++;
            else if(pessoas[i] - k <= apartamentos[j] && pessoas[i] + k >= apartamentos[j]){
                resp++;
                i++;
                j++;
            }
        }
    }

    cout << resp << "\n";

    return 0;
}
