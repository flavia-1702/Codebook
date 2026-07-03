#include <bits/stdc++.h>
using namespace std;
 
const int MAX = 505;
 
int n, m;
 
int grafo[MAX][MAX];
int residual[MAX][MAX];
int pai[MAX];
 
vector<pair<int,int>> ruas;
 
bool bfs(int origem, int destino){
    memset(pai, -1, sizeof(pai));
    bool visitado[MAX] = {0};
 
    queue<int> fila;
    fila.push(origem);
 
    visitado[origem] = true;
 
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
 
        for(int v = 1; v <= n; v++){
            if(!visitado[v] && residual[u][v] > 0){
                pai[v] = u;
                visitado[v] = true;
                if(v == destino)
                    return true;
                fila.push(v);
            }
        }
    }
 
    return false;
}
 
int fordFulkerson(int origem, int destino){
 
    for(int i = 1; i <= n; i++)
        for(int j = 1; j <= n; j++)
            residual[i][j] = grafo[i][j];
 
    int fluxo = 0;
    while(bfs(origem,destino)){
        int gargalo = INT_MAX;
        for(int v = destino; v != origem; v = pai[v]){
            int u = pai[v];
            gargalo = min(gargalo,residual[u][v]);
        }
 
        for(int v = destino; v != origem; v = pai[v]){
            int u = pai[v];
            residual[u][v] -= gargalo;
            residual[v][u] += gargalo;
        }
        fluxo += gargalo;
    }
    return fluxo;
}
 
int main(){
    cin >> n >> m;

    for(int i = 0; i < m; i++){
        int a, b;
        cin >> a >> b;
        ruas.push_back({a,b}); 
        grafo[a][b]++;
        grafo[b][a]++;
    }
 
    int resposta = fordFulkerson(1,n);
    cout << resposta << "\n";
 
    bool visitado[MAX] = {0};
 
    queue<int> fila;
    fila.push(1);
    visitado[1] = true;
 
    while(!fila.empty()){
        int u = fila.front();
        fila.pop();
        for(int v = 1; v <= n; v++){
            if(!visitado[v] && residual[u][v] > 0){
                visitado[v] = true;
                fila.push(v);
            }
        }
    }
 
    for(int i = 0; i < ruas.size(); i++){
        if(visitado[ruas[i].first] && !visitado[ruas[i].second])
            cout << ruas[i].first << " " << ruas[i].second << "\n";
        else if(visitado[ruas[i].second] && !visitado[ruas[i].first])
            cout << ruas[i].first << " " << ruas[i].second << "\n";
    }

    return 0;
}
