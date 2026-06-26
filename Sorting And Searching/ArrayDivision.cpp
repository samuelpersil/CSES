#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl '\n'
#define MAXN 200001

using namespace std;

int n, k, arr[MAXN];

bool ok(int mid){
    int sum = 0, count = 1;
    for(int i = 0; i < n; i++){
        if(arr[i] > mid || count > k) return false;
        if(sum + arr[i] <= mid) sum += arr[i];
        else{
            count++;
            sum = arr[i];
        }
    }

    return count <= k;
}

int32_t main(){fastio
    cin >> n >> k;

    int l = 0, r = 0, ans = -1; 

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        r += arr[i];
    }

    while(l <= r){
        int mid = (l + r)/2;

        if(ok(mid)){
            r = mid - 1;
            ans = mid;
        }
        else{
            l = mid + 1;
        }
    }

    cout << ans << endl;

    return 0;
}