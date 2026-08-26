#include <bits/stdc++.h>
using namespace std;

// Christmas party

typedef long long ll;

const int mod = 1e9+7;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<ll> dp(n+1);

    dp[0] = 1;

    if(n >= 1)
        dp[1] = 0;

    for(int i = 2; i <= n; i++){
        dp[i] = (i-1) * (dp[i-1] + dp[i-2]) % mod;
    }

    cout << dp[n] << "\n";

    return 0;
}
