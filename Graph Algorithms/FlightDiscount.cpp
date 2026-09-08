#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr); 
#define int long long
#define endl '\n'

using namespace std;

const int oo = 1e18;
const int MAXN = 1e5 + 1;
int n, m;
vector<array<int, 3>> adj[MAXN];
vector<array<int, 2>> d(MAXN, {oo, oo});
bool processed[MAXN][2];

void dijkstra(int start){
    priority_queue<array<int, 3>> pq;

    d[start][0] = 0;
    d[start][1] = 0;
    pq.push({0, start, 0});

    while(!pq.empty()){
        auto [dist, u, used] = pq.top(); pq.pop();

        if(-dist > d[u][used]) continue;
        // if(processed[u][used]) continue;
        // processed[u][used] = true;

        for(auto [b, w, is_ticket] : adj[u]){
            if(is_ticket && used) continue;
            if(d[u][used] + w < d[b][used + is_ticket]){
                d[b][used + is_ticket] = d[u][used] + w;
                pq.push({-d[b][used + is_ticket], b, used + is_ticket});
            }
        }

        // debug
        // cout << -dist << " " << u << " " << used << " " << endl;
        // for(int i = 0; i < n; i++){
        //     cout << d[i][0] << " ";
        // }
        // cout << endl;

        // for(int i = 0; i < n; i++){
        //     cout << d[i][1] << " ";
        // }
        // cout << endl << endl;
    }
}

signed main(){fastio
    cin >> n >> m;
    for(int i = 0; i < m; i++){
        int a, b, c; cin >> a >> b >> c;
        a--, b--;
        adj[a].push_back({b, c, 0});
        adj[a].push_back({b, c/2, 1});
    }

    dijkstra(0);

    cout << min(d[n - 1][0], d[n - 1][1]) << endl;

    return 0;
}