#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl '\n'

using namespace std;

int n, t; 
vector<int> arr;

bool search(int mid){
    int prods = 0;
    for(int x : arr){
        prods += mid / x;
        if(prods >= t) return true;
    }
    return prods >= t;
}

signed main(){fastio
    cin >> n >> t;
    arr.resize(n);
    for(int &x : arr) cin >> x;

    int l = 1, r = 1000000000000000000, mid, ans = 1;

    while(l <= r){
        mid = (l + r) / 2;
        if(search(mid)){
            ans = mid;
            r = mid - 1;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}