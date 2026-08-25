#include <bits/stdc++.h>
using namespace std;

// Hambúrgueres

typedef long long ll;

string s;
ll qtde_p, qtde_s, qtde_q;
ll p_p, p_s, p_q;
ll r;
ll pao, salsicha, queijo;

bool possible(ll m){
    ll precisa_p = 0, precisa_s = 0, precisa_q = 0;
    if(pao > 0){
        precisa_p = (m*pao) - qtde_p;
        if(precisa_p < 0)
            precisa_p = 0;
    }
    if(salsicha > 0){
        precisa_s = (m*salsicha) - qtde_s;
        if(precisa_s < 0)
            precisa_s = 0;
    }
    if(queijo > 0){
        precisa_q = (m*queijo) - qtde_q;
        if(precisa_q < 0)
            precisa_q = 0;
    }
    
    ll valor = (precisa_p*p_p) + (precisa_s*p_s) + (precisa_q*p_q);

    return valor <= r;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> s;
    cin >> qtde_p >> qtde_s >> qtde_q;
    cin >> p_p >> p_s >> p_q;
    cin >> r;

    for(int i = 0; i < s.size(); i++){
        if(s[i] == 'B') pao++;
        if(s[i] == 'S') salsicha++;
        if(s[i] == 'C') queijo++;
    }

    ll ini = 0, fim = 1e13;
    while(ini < fim){
        ll m = (ini+fim+1)/2;
        if(!possible(m)) fim = m - 1;
        else ini = m;
    }
    
    cout << ini << "\n";

    return 0;
}
