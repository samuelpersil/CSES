#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr); 
#define ll long long
#define endl '\n'
#define MOD 1000000007

using namespace std;

int main(){fastio
    int n, m; cin >> n >> m;

    vector<int> adj[n];

    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        adj[b - 1].push_back(a - 1);
    }

    vector<vector<int>> dp((1 << n), vector<int>(n, 0));

    dp[1][0] = 1;

    for(int s = 2; s < (1 << n); s++){
        // does this start in the first city?
        if((s & 1) == 0) continue;

        //does this end at the last city => pass through all the cities?
        if((s & (1 << (n - 1))) == 1 && s != (1 << (n)) - 1) continue;

        for(int i = 0; i < n; i++){
            // is the city I in the set S?
            if((s & (1 << i)) == 0) continue;

            int before = s - (1 << i);
            for(auto a : adj[i]){
                if((before & (1 << a))){
                    dp[s][i] = (dp[s][i] + dp[before][a]) % MOD;
                }
            }
        }
    }

    cout << dp[(1 << n) - 1][n - 1] << endl;

    return 0;
}