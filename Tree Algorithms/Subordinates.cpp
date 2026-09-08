#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl '\n'
#define MAXN 200002

using namespace std;

vector<int> adj[MAXN];
vector<int> subs(MAXN, 0);

int dfs(int u, int source){
    // cout << u + 1 << " " << source + 1 << endl;
    int ans = 0;
    for(int v : adj[u]){
        if(v == source) continue;

        ans += dfs(v, u) + 1;
    }

    return subs[u] = ans;
}

signed main(){fastio
    int n; cin >> n;
    for(int i = 0; i < n - 1; i++){
        int a; cin >> a;
        a--;
        adj[a].push_back(i + 1);
    }

    dfs(0, 0);

    for(int i = 0; i < n; i++){
        cout << subs[i] << " ";
    }

    return 0;
}