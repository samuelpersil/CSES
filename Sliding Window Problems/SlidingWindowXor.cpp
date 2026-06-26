#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl '\n'

using namespace std;

signed main(){fastio
    int n, k; cin >> n >> k;
    int x, a, b, c; cin >> x >> a >> b >> c;
    int arr[n];
    arr[0] = x;
    for(int i = 1; i < n; i++){
        arr[i] = (a * arr[i - 1] + b) % c;
    }

    int ans = 0, window = 0;

    for(int i = 0; i < k; i++){
        window ^= arr[i];
    }

    ans = window;

    for(int i = k; i < n; i++){
        window ^= arr[i];
        window ^= arr[i - k];
        ans ^= window;
    }

    cout << ans << endl;

    return 0;
}