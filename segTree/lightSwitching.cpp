#include <bits/stdc++.h>
using namespace std;

// Interruptor de luz

struct segtree{
    int n;
    vector<int> st, lazy;

    segtree(int n){
        this->n = n;
        st.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }

    void build(vector<int> &v){
        build(0, v.size()-1, v, 0);
    }

    int query(int l, int r){
        return query(0, n-1, l, r, 0);
    }

    void update(int l, int r, int value){
        update(0, n-1, l, r, value, 0);
    }

private:
    void build(int start, int end, vector<int> &v, int node){
        if(start == end){
            st[node] = v[start];
            return;
        }

        int m = start + (end-start)/2;
        build(start, m, v, 2*node+1);
        build(m+1, end, v, 2*node+2);

        st[node] = st[2*node+1] + st[2*node+2];
    }

    int query(int start, int end, int l, int r, int node){
        if(start > r || end < l)
            return 0;
        
        if(lazy[node] != 0){
            st[node] = (end-start+1) - st[node];
            if(start != end) {
                lazy[2*node+1] = lazy[2*node+1] ^ 1;
                lazy[2*node+2] = lazy[2*node+2] ^ 1;
            }
            lazy[node] = 0;
        }

        if(start >= l && end <= r)
            return st[node];

        int m = start + (end-start)/2;
        int ql = query(start, m, l, r, 2*node+1);
        int qr = query(m+1, end, l, r, 2*node+2);

        return ql + qr;
    }

    void update(int start, int end, int l, int r, int value, int node){
        if(lazy[node] != 0){
            st[node] = (end-start+1) - st[node]; //tamanho do segmento - quantidade de antiga
            if(start != end){
                lazy[2*node+1] = lazy[2*node+1] ^ 1;
                lazy[2*node+2] = lazy[2*node+2] ^ 1;
            }
            lazy[node] = 0;
        }

        if(start > r || end < l)
            return;
    
        if(start >= l && end <= r){
            st[node] = (end-start+1) - st[node];
            if(start != end){
                lazy[2*node+1] = lazy[2*node+1] ^ 1;
                lazy[2*node+2] = lazy[2*node+2] ^ 1;
            }
            return;
        }

        int m = start + (end-start)/2;
        update(start, m, l, r, value, 2*node+1);
        update(m+1, end, l, r, value, 2*node+2);
        
        st[node] = st[2*node+1] + st[2*node+2];
    }
};

int main(){
    int n, m;
    cin >> n >> m;

    vector<int> vet(n, 0);

    segtree seg(vet.size());
    seg.build(vet);

    while(m--){
        int op, s, e;
        cin >> op >> s >> e; s--; e--;
        if(op == 0)
            seg.update(s, e, 1);
        else
            cout << seg.query(s, e) << "\n";
    }
    return 0;
}
