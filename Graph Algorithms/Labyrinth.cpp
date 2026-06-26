#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define MAXN 1000
#define F first
#define S second

using namespace std;

vector<vector<bool>> visited(MAXN, vector<bool>(MAXN, false));
pair<int, int> parent[MAXN][MAXN];
string matrix[MAXN];
queue<pair<int, int>> q;
int n, m;
pair<int, int> ans = {-1, -1};

void bfs(int i, int j){
    q.push({i, j});
    visited[i][j] = true;

    while(!q.empty()){

        pair<int, int> p = q.front(); q.pop();

        if(matrix[p.F][p.S] == 'B'){
            ans = {p.F, p.S};
            return;
        }
    
        pair<int, int> neighbors[] = {{p.F - 1, p.S}, {p.F, p.S - 1}, {p.F, p.S + 1}, {p.F + 1, p.S}};
        for(auto x : neighbors){
            if(x.F >= 0 && x.F < n && x.S >= 0 && x.S < m && matrix[x.F][x.S] != '#' && !visited[x.F][x.S]){
                parent[x.F][x.S] = {p.F, p.S};
                visited[x.F][x.S] = true;
                q.push({x.F, x.S});
            }
        }
    }
}

int main(){fastio
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        cin >> matrix[i];
    }

    pair<int, int> start;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] == 'A'){
                start = {i, j};
            }
        }
    }

    bfs(start.F, start.S);

    if(ans.F == -1 && ans.S == -1){
        cout << "NO" << endl;
    }

    else{
        cout << "YES" << endl;
        vector<pair<int, int>> steps;
        steps.push_back(ans);
        while(!(ans == start)){
            pair<int, int> p = parent[ans.F][ans.S];
            steps.push_back(p);
            ans = p;
        }

        cout << steps.size() - 1 << endl;
        for(int i = steps.size() - 2; i >= 0; i--){
            if(steps[i].F > steps[i + 1].F) cout << "D";
            else if(steps[i].F < steps[i + 1].F) cout << "U";
            else if(steps[i].S > steps[i + 1].S) cout << "R";
            else cout << "L";
        }
        cout << endl;
    }

    return 0;
}