#include <bits/stdc++.h>
using namespace std;

// Static range minimum queries
 
struct segtree {
    int n;
    vector<int> st;
 
    segtree(int n) {
        this->n = n;
        st.resize(4*n, 0);
    }
 
    void build(vector<int> &v) {
        build(0, v.size()-1, v, 0);
    }
 
    int query(int l, int r) {
        return query(0, n-1, l, r, 0);
    }
 
    void update(int id, int value) {
        update(0, n-1, id, value, 0);
    }
 
private:
    void build(int start, int end, vector<int> &v, int node) {
        if(start == end) {
            st[node] = v[start];
            return;
        }
 
        int m = start + (end-start)/2;
        build(start, m, v, 2*node+1);
        build(m+1, end, v, 2*node+2);
 
        st[node] = min(st[2*node+1], st[2*node+2]);
    }
 
    int query(int start, int end, int l, int r, int node) {
        if(start > r || end < l)
            return INT_MAX;
        
        if(start >= l && end <= r)
            return st[node];
 
        int m = start + (end-start)/2;
        int ql = query(start, m, l, r, 2*node+1);
        int qr = query(m+1, end, l, r, 2*node+2);
 
        return min(ql, qr);
    }
 
    void update(int start, int end, int id, int value, int node) {
        if(start == end) {
            st[node] = value;
            return;
        }
 
        int m = start + (end-start)/2;
        if(id <= m)
            update(start, m, id, value, 2*node+1);
        else
            update(m+1, end, id, value, 2*node+2);
        
        st[node] = st[2*node+1] + st[2*node+2];
    }
};
 
int main(){
    int n, q;
    cin >> n >> q;
 
    vector<int> vet(n);
    for(int i = 0; i < n; i++)
        cin >> vet[i];
 
    segtree seg(vet.size());
    seg.build(vet);
 
    while(q--){
        int a, b;
        cin >> a >> b;
        cout << seg.query(a-1, b-1) << "\n";
    }
 
    return 0;
}
