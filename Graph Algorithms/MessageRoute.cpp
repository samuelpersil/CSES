#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define MAXN 100001

using namespace std;

bool visited[MAXN];
vector<int> adj[MAXN];
int parent[MAXN], distance_[MAXN];
queue<int> q;

void bfs(int start){
    q.push(start);
    parent[start] = start;
    visited[start] = true;
    distance_[start] = 0;

    while(!q.empty()){
        int u = q.front(); q.pop();

        for(int x : adj[u]){
            if(!visited[x]){
                visited[x] = true;
                distance_[x] = distance_[u] + 1;
                parent[x] = u;
                q.push(x);
            }
        }
    }
}

int main(){fastio
    int n, m; cin >> n >> m;

    while(m--){
        int a, b; cin >> a >> b;
        adj[a].push_back(b);
        adj[b].push_back(a);
    }

    bfs(1);

    if(!visited[n]){
        cout << "IMPOSSIBLE" << endl;
    }
    else{
        cout << distance_[n] + 1 << endl;
        vector<int> steps;
        int x = n;
        while(parent[x] != x){
            steps.push_back(x);
            x = parent[x];
        }
        steps.push_back(1);
        for(int i = steps.size() - 1; i >= 0; i--){
            cout << steps[i] << " ";
        }
        cout << endl;
    }
    

    return 0;
}