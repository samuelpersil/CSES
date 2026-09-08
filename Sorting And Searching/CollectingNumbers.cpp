#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl '\n'
 
using namespace std;
 
signed main(){fastio
    int n; cin >> n;
    int positions[n + 1];
    int ans = 1;
    for(int i = 0; i < n; i++){
        int value; cin >> value;
        positions[value] = i;
    }
    for(int i = 1; i <= n; i++){
        if(i < n && positions[i] > positions[i + 1]) ans++;
    }
    cout << ans << endl;
}