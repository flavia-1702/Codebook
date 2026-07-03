#include <bits/stdc++.h>

using namespace std;

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

        int m = start + (end - start)/2;
        build(start, m, v, 2*node + 1);
        build(m+1, end, v, 2*node + 2);

        st[node] = st[2*node + 1] + st[2*node + 2];
    }

    int query(int start, int end, int l, int r, int node) {
        if(start > r || end < l)
            return 0;
        
        if(start >= l && end <= r)
            return st[node];

        int m = start + (end - start)/2;
        int ql = query(start, m, l, r, 2*node + 1);
        int qr = query(m+1, end, l, r, 2*node + 2);

        return ql + qr;
    }

    void update(int start, int end, int id, int value, int node) {
        if(start == end) {
            st[node] = value;
            return;
        }

        int m = start + (end - start)/2;
        if(id <= m)
            update(start, m, id, value, 2*node + 1);
        else
            update(m+1, end, id, value, 2*node + 2);
        
        st[node] = st[2*node + 1] + st[2*node + 2];
    }
};

int main() {
    vector<int> v = {-5,-2,3,6,7,9,12,22};
    segtree seg(v.size());
    seg.build(v);

    for(auto i : seg.st)
        cout << i << " ";
    cout << endl;

    for(int i = 0; i < v.size(); i++)
        cout << i << "-" << i << " " << seg.query(i, i) << endl;
    cout << endl << 1 << "-" << 2 << " " << seg.query(1, 2) << endl;
    cout << 2 << "-" << 5 << " " << seg.query(2, 5) << endl;
    cout << 0 << "-" << 7 << " " << seg.query(0, 7) << endl;

    seg.update(3, 10);

    for(int i = 0; i < v.size(); i++)
        cout << i << "-" << i << " " << seg.query(i, i) << endl;
    cout << endl << 1 << "-" << 2 << " " << seg.query(1, 2) << endl;
    cout << 2 << "-" << 5 << " " << seg.query(2, 5) << endl;
    cout << 0 << "-" << 7 << " " << seg.query(0, 7) << endl;

    return 0;
}
