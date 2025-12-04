#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'

using namespace std;

int main(){fastio
    int n; cin >> n;

    int ans = 0;
    while(n > 0){
        string s = to_string(n);

        n -= (*max_element(s.begin(), s.end()) - '0');
        ans++;
    }    

    cout << ans << endl;
}