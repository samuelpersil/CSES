#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define oo 1000000000

using namespace std;

int a[1001], b[1001];

int dp[1001][1001];

int lcs(int i, int j){
    if(i == 0 || j == 0){
        return 0;
    }

    if(dp[i][j] != -1) return dp[i][j];
    if(a[i - 1] == b[j - 1]){
        return dp[i][j] = lcs(i - 1, j - 1) + 1;
    }
    else{
        return dp[i][j] = max(lcs(i - 1, j), lcs(i, j - 1));
    }
}

int main(){fastio
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    for(int i = 0; i <= n; i++){
        for(int j = 0; j <= m; j++){
            dp[i][j] = -1;
        }
    }

    cout << lcs(n, m) << endl;

    vector<int> lcs_result;
    int i = n, j = m;

    while(i > 0 && j > 0){
        if(a[i-1] == b[j-1]){
            lcs_result.push_back(a[i-1]);
            i--; 
            j--;
        }
        else if(dp[i-1][j] >= dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    reverse(lcs_result.begin(), lcs_result.end());

    for(auto c : lcs_result){
        cout << c << " ";
    }

    cout << endl;

    return 0;
}