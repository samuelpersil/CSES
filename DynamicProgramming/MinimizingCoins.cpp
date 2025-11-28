#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define MAXN 1000001
#define oo 1000000000

using namespace std;

int main(){fastio
    int n, x; cin >> n >> x;

    vector<int> dp(MAXN, oo);
    int coins[n];

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    dp[0] = 0;

    for(int i = 1; i <= x; i++){
        for(auto c : coins){
            if(i - c >= 0){
                dp[i] = min(dp[i], dp[i - c] + 1);
            }
        }
    }

    cout << (dp[x] == oo ? -1 : dp[x]) << endl;

    return 0;
}