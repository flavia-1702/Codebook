#include <bits/stdc++.h>
using namespace std;
const int MAX = 1005;
int grafo[MAX][MAX];
int grafoResidual[MAX][MAX];
int pai[MAX];

bool bfs(int V, int origem, int destino){
    bool visitado[MAX];
    memset(visitado, false, sizeof(visitado));
    queue<int> fila;
    fila.push(origem);
    visitado[origem] = true;
    pai[origem] = -1;
    while(!fila.empty()){
        int atual = fila.front();
        fila.pop();
        for(int prox = 0; prox < V; prox++){
            if(!visitado[prox] && grafoResidual[atual][prox] > 0){
                pai[prox] = atual;
                if(prox == destino)
                    return true;
                visitado[prox] = true;
                fila.push(prox);
            }
        }
    }
    return false;
}

int fordFulkerson(int V, int origem, int destino){
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            grafoResidual[i][j] = grafo[i][j];
    int fluxoMaximo = 0;
    while(bfs(V, origem, destino)){
        int fluxoCaminho = INT_MAX;
        for(int v = destino; v != origem; v = pai[v]){
            int u = pai[v];
            fluxoCaminho = min(fluxoCaminho, grafoResidual[u][v]);
        }
        for(int v = destino; v != origem; v = pai[v]){
            int u = pai[v];
            grafoResidual[u][v] -= fluxoCaminho;
            grafoResidual[v][u] += fluxoCaminho;
        }
        fluxoMaximo += fluxoCaminho;
    }
    return fluxoMaximo;
}

int main(){
    int n, m, k;
    cin >> n >> m >> k;

    int origem = 0;
    int destino = n + m + 1;
    int V = destino + 1;

    for(int i = 1; i <= n; i++)
        grafo[origem][i] = 1;

    for(int i = 0; i < k; i++){
        int menino, menina;
        cin >> menino >> menina;
        grafo[menino][n + menina] = 1;
    }

    for(int i = 1; i <= m; i++)
        grafo[n + i][destino] = 1;

    int resposta = fordFulkerson(V, origem, destino);
    
    cout << resposta << endl;
    for(int menino = 1; menino <= n; menino++){
        for(int menina = 1; menina <= m; menina++){
            if(grafo[menino][n + menina] == 1 &&
               grafoResidual[menino][n + menina] == 0){
                cout << menino << " " << menina << endl;
            }
        }
    }
    return 0;
}
