#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define oo 1000000000

using namespace std;

int a[1001], b[1001];

int dp[1001][1001];

int main(){fastio
    int n, m; cin >> n >> m;

    for(int i = 0; i < n; i++){
        cin >> a[i];
    }

    for(int i = 0; i < m; i++){
        cin >> b[i];
    }

    for(int i = 0; i <= n; i++){
        dp[i][0] = 0;
    }
    for(int i = 0; i <= m; i++){
        dp[0][i] = 0;
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            if(a[i - 1] == b[j - 1]){
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else{
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    cout << dp[n][m] << endl;

    vector<int> lcs;

    int i = n, j = m;

    while(i > 0 && j > 0){
        if(a[i - 1] == b[j - 1]){
            lcs.push_back(a[i - 1]);
            i--, j--;
        }
        else if(dp[i - 1][j] >= dp[i][j - 1]){
            i--;
        }
        else{
            j--;
        }
    }

    reverse(lcs.begin(), lcs.end());
    for(auto c : lcs){
        cout << c << " ";
    }
    cout << endl;

    return 0;
}