#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define F first
#define S second

using namespace std;

int main(){fastio
    int n, x; cin >> n >> x;

    pair<int, int> arr[n];

    for(int i = 0; i < n; i++){
        cin >> arr[i].F;
        arr[i].S = i + 1;
    }

    sort(arr, arr + n);

    ll sum = 0, l = 0, r = n - 1;

    while(l < r){
        sum = arr[l].F + arr[r].F;
        if(sum == x){
            cout << arr[l].S << " " << arr[r].S << endl;
            return 0;
        }
        else if(sum > x){
            r--;
        }
        else{
            l++;
        }
    }

    cout << "IMPOSSIBLE" << endl;




    return 0;
}