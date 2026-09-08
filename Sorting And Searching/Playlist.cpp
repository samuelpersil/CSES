#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl '\n'

using namespace std;

signed main(){fastio
    int n; cin >> n;
    int arr[n];
    for(int &x : arr) cin >> x;
    int ans = 0, l = 0, r = 0;
    map<int, int> freq;
    while(r < n){
        int value = arr[r];
        while(l < r && freq[value] != 0){
            freq[arr[l]]--;
            if(freq[arr[l]] == 0) freq.erase(arr[l]);
            l++;
        }
        freq[arr[r]]++;

        ans = max(ans, (int) freq.size());
        r++;
    }
    cout << ans << endl;

    return 0;
}