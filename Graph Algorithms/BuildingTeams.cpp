#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define MAXN 100001

using namespace std;

bool visited[MAXN];
vector<int> adj[MAXN];
vector<int> teams(MAXN, 0);
int ans, n;

void dfs(int u, int team){
    if(visited[u]){
        if(teams[u] != team){
            ans = 0;
        }
        return;
    }

    visited[u] = true;
    teams[u] = team;

    int next_team = (team == 1 ? 2 : 1);

    for(int v : adj[u]){
        dfs(v, next_team);
    }
}

int main(){fastio
    int m; cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b; cin >> a >> b;
        a--, b--;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    ans = 1;
    for(int i = 0; i < n; i++){
        if(!visited[i]) dfs(i, 1);
    }

    if(ans){
        for(int i = 0; i < n; i++){
            cout << teams[i] << " ";
        }
        cout << endl;
    }
    else cout << "IMPOSSIBLE" << endl;

    return 0;
}