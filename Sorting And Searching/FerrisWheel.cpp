#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    int n, x; cin >> n >> x;

    int arr[n];

    for(auto &x : arr) cin >> x;

    sort(arr, arr + n, greater<int>());

    int l = 0, r = n - 1;

    while(l <= r){
        if(l == r) l++;

        else if(arr[l] + arr[r] <= x){
            l++, r--;
        }

        else l++;
    }

    cout << l << endl;

    return 0;
}