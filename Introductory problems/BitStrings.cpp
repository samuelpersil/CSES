#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long
#define MOD 1000000007
 
using namespace std;
 
int main(){fastio
    ll n; cin >> n;
    ll result = 1;
    while(n--){
        result = result * 2 % MOD;
    }
    cout << result;
}