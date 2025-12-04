#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define MAXN 1000001
#define oo 1000000000
#define MOD 1000000007

using namespace std;

int main(){fastio
    int n; cin >> n;

    vector<ll> dp(n + 1);

    dp[0] = 1, dp[1] = 1;

    for(int i = 2; i <= n; i++){
        dp[i] = 0;

        for(int j = 1; j <= 6; j++){
            if(i - j >= 0){
                dp[i] = (dp[i] + dp[i - j]) % MOD;
            }
        }
    }

    cout << dp[n] << endl;

    return 0;
}