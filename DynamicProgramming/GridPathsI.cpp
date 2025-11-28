#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long
#define MOD 1000000007

using namespace std;

int main(){fastio
    int n; cin >> n;
    string matrix[n];

    for(int i = 0; i < n; i++){
        cin >> matrix[i];
    }

    vector<vector<ll>> dp(n, vector<ll>(n, 0));

    dp[n - 1][n - 1] = 1ll;

    for(int i = n - 1; i >= 0; i--){
        for(int j = n - 1; j >= 0; j--){
            if(matrix[i][j] == '*'){
                dp[i][j] = 0;
                continue;
            }
            ll a = 0, b = 0;

            if(j + 1 < n) a = dp[i][j + 1];
            if(i + 1 < n) b = dp[i + 1][j];

            dp[i][j] = max(dp[i][j], (a + b) % MOD);
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < n; j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }

    cout << dp[0][0] << endl;

    return 0;
}