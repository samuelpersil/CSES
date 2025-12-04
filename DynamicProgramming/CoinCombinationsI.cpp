#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define MAXN 1000001
#define oo 1000000000
#define MOD 1000000007
 
using namespace std;
 
int main(){fastio
    int n, x; cin >> n >> x;
 
    int coins[n];
 
    vector<int> dp(x + 1);
 
    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }
 
    dp[0] = 1;
 
    for(int i = 1; i <= x; i++){
        dp[i] = 0;
        for(auto c : coins){
            if(i - c >= 0){
                dp[i] = (dp[i] + dp[i - c]) % MOD;
            }
        }
    }
 
    cout << dp[x] << endl;
 
    return 0;
}