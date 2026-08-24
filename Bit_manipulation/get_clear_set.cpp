#include <bits/stdc++.h>
using namespace std;

int get_ith_bit(int n, int i){
    int mask = (n >> i);
    if(mask & 1) return 1;
    else return 0;
}

int clear_ith_bit(int n, int i){
    int mask = (1 << i);
    mask = ~(mask);
    return (n&mask);
}

int set_ith_bit(int n, int i){
    int mask = (1 << i);
    return (n|mask);
}

int main(){
    int n; cin >> n;
    int i; cin >> i;
    return 0;
}
