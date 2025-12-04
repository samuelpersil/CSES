#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
 
using namespace std;
 
int lis(vector<int> &arr, int n){
    vector<int> dp;
 
    for(int i = 0; i < n; i++){
        int l = lower_bound(dp.begin(), dp.end(), arr[i]) - dp.begin();
 
        if(l == dp.size()){
            dp.push_back(arr[i]);
        }
        else{
            dp[l] = arr[i];
        }
    }
 
    return dp.size();
}
 
int main(){fastio
    int n; cin >> n;
 
    vector<int> arr(n);
 
    for(int i = 0; i < n; i++){
        cin >> arr[i];
    }
 
    cout << lis(arr, n) << endl;
    
}