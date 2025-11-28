#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long
#define oo 1000000000
#define MAXN 1000
 
using namespace std;
 
int main(){fastio
    int n, x; cin >> n >> x;
 
    vector<int> prices(n), pages(n);
 
    for(int i = 0; i < n; i++){
        cin >> prices[i];
    }
    for(int i = 0; i < n; i++){
        cin >> pages[i];
    }
 
    vector<vector<int>> dp(n+1, vector<int>(x+1, 0));
 
    for(int i = 1; i <= n; i++){
        for(int j = 0; j <= x; j++){
            dp[i][j] = dp[i-1][j];
            if(j >= prices[i-1]){
                dp[i][j] = max(dp[i][j], dp[i-1][j - prices[i-1]] + pages[i-1]);
            }
        }
    }
    cout << dp[n][x] << endl;
    
    return 0;
}