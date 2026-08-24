#include <bits/stdc++.h>
using namespace std;

// Festival de cinema

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
 
    vector<pair<int, int>> filmes(n);
 
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        filmes[i] = {b, a};
    }
 
    sort(filmes.begin(), filmes.end());
 
    int cont = 0, fim_atual = 0;
 
    for(auto& f : filmes){
        if(f.second >= fim_atual){
            cont++;
            fim_atual = f.first;
        }
    }
 
    cout << cont << "\n";

    return 0;
}
