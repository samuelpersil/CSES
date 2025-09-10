#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    int n, k; cin >> n >> k;
    
    int moves[k], dp[n + 1];
    dp[0] = 1;

    string answer = "WL";

    for(int i = 0; i < k; i++){
        cin >> moves[i];
    }
    //0 for winning
    //1 for loosing

    for(int i = 1; i <= n; i++){
        dp[i] = 0;
        for(auto move : moves){
            if(i - move >= 0){
                dp[i] |= dp[i - move];
            }
        }

        dp[i] = !dp[i];

        cout << answer[dp[i]];
    }

    cout << endl;
}