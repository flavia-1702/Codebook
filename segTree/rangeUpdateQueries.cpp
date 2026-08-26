#include <bits/stdc++.h>
using namespace std;

typedef unsigned long long ull;

// Range update queries

struct segtree{
    ull n;
    vector<ull> st, lazy;

    segtree(ull n){
        this->n = n;
        st.resize(4*n, 0);
        lazy.resize(4*n, 0);
    }

    void build(vector<ull> &v){
        build(0, v.size()-1, v, 0);
    }

    ull query(ull l, ull r){
        return query(0, n-1, l, r, 0);
    }

    void update(ull l, ull r, ull value){
        update(0, n-1, l, r, value, 0);
    }

private:
    void build(ull start, ull end, vector<ull> &v, ull node){
        if(start == end){
            st[node] = v[start];
            return;
        }

        ull m = start + (end-start)/2;
        build(start, m, v, 2*node+1);
        build(m+1, end, v, 2*node+2);

        st[node] = st[2*node+1] + st[2*node+2];
    }

    ull query(ull start, ull end, ull l, ull r, ull node){
        if(start > r || end < l)
            return 0;
        
        if(lazy[node] != 0){
            st[node] += (end-start+1) * lazy[node];
            if(start != end){
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if(start >= l && end <= r)
            return st[node];

        ull m = start + (end-start)/2;
        ull ql = query(start, m, l, r, 2*node+1);
        ull qr = query(m+1, end, l, r, 2*node+2);

        return ql + qr;
    }

    void update(ull start, ull end, ull l, ull r, ull value, ull node){
        if(lazy[node] != 0){
            st[node] += (end-start+1) * lazy[node];
            if(start != end) {
                lazy[2*node+1] += lazy[node];
                lazy[2*node+2] += lazy[node];
            }
            lazy[node] = 0;
        }

        if(start > r || end < l)
            return;
    
        if(start >= l && end <= r) {
            st[node] += (end-start+1) * value;
            if(start != end){
                lazy[2*node+1] += value;
                lazy[2*node+2] += value;
            }
            return;
        }

        ull m = start + (end-start)/2;
        update(start, m, l, r, value, 2*node+1);
        update(m+1, end, l, r, value, 2*node+2);
        
        st[node] = st[2*node+1] + st[2*node+2];
    }
};

int main(){
    ull n, q;
    cin >> n >> q;

    vector<ull> vet(n);
    for(ull i = 0; i < n; i++)
        cin >> vet[i];

    segtree seg(vet.size());
    seg.build(vet);

    while(q--){
        ull op;
        cin >> op;
        if(op == 2){
            ull k;
            cin >> k; k--;
            cout << seg.query(k, k) << "\n";
        } else{
            ull a, b, u;
            cin >> a >> b >> u; a--; b--;
            seg.update(a, b, u);
        }
    }

    return 0;
}
