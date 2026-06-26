#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define MAXN 100001

using namespace std;

bool visited[MAXN];
vector<int> adj[MAXN], parent(MAXN, -1), ans;

void dfs(int u){
    if(visited[u]) return;
    visited[u] = true;

    for(auto v : adj[u]){
        if(v == u || v == parent[u]) continue;
        if(visited[v]){
            int start = v;
            ans.push_back(v);
            v = u;
            while(!(v == -1 || v == start)){
                ans.push_back(v);
                v = parent[v];
            }
            ans.push_back(start);
            return;
        }
        else{
            parent[v] = u;
            dfs(v);

            if(ans.size() != 0) return;
        }
    }
}

int main(){
    int n, m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    for(int i = 0; i < n; i++){
        if(!visited[i] && ans.size() == 0) dfs(i);
    }

    if(ans.size()){
        cout << ans.size() << endl;
        for(auto x : ans) cout << x + 1 << " ";
    }
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}