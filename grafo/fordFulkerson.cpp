#include <bits/stdc++.h>
using namespace std;
#define V 6

bool bfs(int grafoResidual[V][V], int origem, int destino, int pai[]){
    bool visitado[V];
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

int fordFulkerson(int grafo[V][V], int origem, int destino){
    int grafoResidual[V][V];
    for(int i = 0; i < V; i++)
        for(int j = 0; j < V; j++)
            grafoResidual[i][j] = grafo[i][j];
    int pai[V];
    int fluxoMaximo = 0;
    while(bfs(grafoResidual, origem, destino, pai)){
        int fluxoCaminho = INT_MAX;
        // Descobre o gargalo do caminho
        for(int v = destino; v != origem; v = pai[v]){
            int u = pai[v];
            fluxoCaminho = min(fluxoCaminho, grafoResidual[u][v]);
        }
        // Atualiza o grafo residual
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
    int grafo[V][V] = {
        {0, 16, 13, 0, 0, 0},
        {0, 0, 10, 12, 0, 0},
        {0, 4, 0, 0, 14, 0},
        {0, 0, 9, 0, 0, 20},
        {0, 0, 0, 7, 0, 4},
        {0, 0, 0, 0, 0, 0}
    };
    cout << "Fluxo maximo: " << fordFulkerson(grafo, 0, 5) << endl;
    return 0;
}
