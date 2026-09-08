#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl '\n'
#define MAXN 1001
#define oo 1000000000

using namespace std;

queue<pair<int, int>> q;
bool visited[MAXN][MAXN];
pair<int, int> from[MAXN][MAXN];
int n, m;
string ans;
pair<int ,int> start;
string matrix[MAXN];
int monster_times[MAXN][MAXN];
int player_times[MAXN][MAXN];
map<pair<int, int>, char> direction;

signed main(){
    cin >> n >> m;
    for(int i = 0; i < n; i++) cin >> matrix[i];
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            monster_times[i][j] = oo;
            player_times[i][j] = oo;
            if(matrix[i][j] == 'A'){
                start = {i, j};
                player_times[i][j] = 0;
            }
            else if(matrix[i][j] == 'M'){
                q.push({i, j});
                monster_times[i][j] = 0;
            }
        }
    }

    direction[{1, 0}] = 'D';
    direction[{-1, 0}] = 'U';
    direction[{0, 1}] = 'R';
    direction[{0, -1}] = 'L';

    while(!q.empty()){
        pair<int, int> u = q.front(); q.pop();
        
        pair<int, int> adj[] = {{u.first - 1, u.second}, {u.first, u.second - 1}, {u.first, u.second + 1}, {u.first + 1, u.second}};
        for(auto v : adj){
            if(v.first >= 0 && v.first < n && v.second >= 0 && v.second < m && matrix[v.first][v.second] != '#' && monster_times[v.first][v.second] == oo){
                monster_times[v.first][v.second] = monster_times[u.first][u.second] + 1;
                q.push(v);
            }
        }
    }

    // for(int i = 0; i < n; i++){
    //     for(int j = 0; j < m; j++){
    //         cout << (monster_times[i][j] == oo ? -1 : monster_times[i][j]) << " ";
    //     }
    //     cout << endl;
    // }

    visited[start.first][start.second] = true;
    q.push(start);
    while(!q.empty()){
        pair<int, int> u = q.front(); q.pop();
        // cout << u.first << " " << u.second << endl;
        if(u.first == n - 1 || u.first == 0 || u.second == m - 1 || u.second == 0){
            pair<int, int> v = u;
    
            while(v != start){
                pair<int, int> diff {v.first - from[v.first][v.second].first, v.second - from[v.first][v.second].second};
                ans.push_back(direction[diff]);
                v = from[v.first][v.second];
            }
            reverse(ans.begin(), ans.end());
            if(ans.empty()) ans.push_back('0');
            break;
        }
    
        pair<int, int> adj[] = {{u.first - 1, u.second}, {u.first, u.second - 1}, {u.first, u.second + 1}, {u.first + 1, u.second}};
        for(auto v : adj){
            // cout << " " << v.first << " " << v.second << endl;
            if(v.first >= 0 && v.first < n && v.second >= 0 && v.second < m && matrix[v.first][v.second] != '#' && !visited[v.first][v.second] && monster_times[v.first][v.second] > player_times[u.first][u.second] + 1){
                visited[v.first][v.second] = true;
                from[v.first][v.second] = u;
                player_times[v.first][v.second] = player_times[u.first][u.second] + 1;
                q.push(v);
            }
        }
    }
    
    if(ans.size() > 0){
        cout << "YES" << endl;
        if(ans[0] != '0') cout << ans.size() << endl;
        for(auto x : ans) cout << x;
        cout << endl;
    }
    else cout << "NO" << endl;

    return 0;
}