#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;

// Dynamic range sum queries
 
struct segtree{
    ll n;
    vector<ll> st;
 
    segtree(ll n){
        this->n = n;
        st.resize(4*n, 0);
    }
 
    void build(vector<ll> &v){
        build(0, v.size()-1, v, 0);
    }
 
    ll query(ll l, ll r){
        return query(0, n-1, l, r, 0);
    }
 
    void update(ll id, ll value){
        update(0, n-1, id, value, 0);
    }
 
private:
    void build(ll start, ll end, vector<ll> &v, ll node){
        if(start == end){
            st[node] = v[start];
            return;
        }
 
        ll m = start + (end-start)/2;
        build(start, m, v, 2*node+1);
        build(m+1, end, v, 2*node+2);
 
        st[node] = st[2*node+1] + st[2*node+2];
    }
 
    ll query(ll start, ll end, ll l, ll r, ll node){
        if(l > end || r < start)
            return 0;
        
        if(start >= l && end <= r)
            return st[node];
 
        ll m = start + (end-start)/2;
        ll ql = query(start, m, l, r, 2*node+1);
        ll qr = query(m+1, end, l, r, 2*node+2);
 
        return ql + qr;
    }
 
    void update(ll start, ll end, ll id, ll value, ll node){
        if(start == end){
            st[node] = value;
            return;
        }
 
        ll m = start + (end-start)/2;
        if(id <= m)
            update(start, m, id, value, 2*node+1);
        else
            update(m+1, end, id, value, 2*node+2);
        
        st[node] = st[2*node+1] + st[2*node+2];
    }
};
 
int main(){
    ll n, q;
    cin >> n >> q;
 
    vector<ll> vet(n+1);
    for(ll i = 1; i <= n; i++)
        cin >> vet[i];
    
    segtree seg(vet.size());
    seg.build(vet);
    
    while(q--){
        ll a, b, c;
        cin >> a >> b >> c;
 
        if(a == 1)
            seg.update(b, c);
        else
            cout << seg.query(b, c) << "\n";
    }
 
    return 0;
}
