#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define MAXN 1001
#define F first
#define S second
 
using namespace std;
 
string matrix[MAXN];
 
bool visited[MAXN][MAXN];
int n, m;
 
void dfs(int i, int j){
    if(visited[i][j]) return;
    visited[i][j] = true;
 
    pair<int, int> neighbors[] = {{i - 1, j}, {i, j - 1}, {i, j + 1}, {i + 1, j}};
    for(auto v : neighbors){
        if(v.F >= 0 && v.F < n && v.S >= 0 && v.S < m && matrix[v.F][v.S] == '.'){
            dfs(v.F, v.S);
        }
    }
}
 
int main(){fastio
    int answer = 0; cin >> n >> m;
 
    for(int i = 0; i < n; i++){
        cin >> matrix[i];
    }
 
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matrix[i][j] != '#' && !visited[i][j]){
                answer++;
                dfs(i, j);
            }
        }
    }
 
    cout << answer;
 
 
 
}