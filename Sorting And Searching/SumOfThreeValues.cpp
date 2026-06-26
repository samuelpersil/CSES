#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    int n;
    ll x; 
    cin >> n >> x;
    pair<ll, ll> arr[n];
    for(int i = 0; i < n; i++){
        cin >> arr[i].first;
        arr[i].second = i + 1;
    }
    sort(arr, arr + n);

    int l = 0, r = n - 1;
    ll sum = -1;

    for(int i = 0; i < n - 2; i++){
        int l = i + 1, r = n - 1;
        while(l < r){
            sum = arr[i].first + arr[l].first + arr[r].first;
            if(sum == x){
                ll ans[] = {arr[i].second, arr[l].second, arr[r].second};
                sort(ans, ans + 3);
                for(int a : ans) cout << a << " ";
                cout << endl;
                return 0;
            }
            if(sum > x){
                r--;
            }
            else{
                l++;
            }
        }
    }

    cout << "IMPOSSIBLE" << endl;
    return 0;
}