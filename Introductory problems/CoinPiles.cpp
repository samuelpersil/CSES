#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    int t; cin >> t;

    while(t--){
        ll a, b; cin >> a >> b;

        ll x = -1 * a + 2 * b, y = 2 * a - 1 * b;

        if(x >= 0 && y >= 0 && x % 3 == 0 && y % 3 == 0){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
    }

}