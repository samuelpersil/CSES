#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define MOD 1000000007

using namespace std;

ll expo(ll a, ll b){    
    if(b == 0) return 1;
    if(b % 2 == 0) return expo(a, b/2) * expo(a, b/2) % MOD;
    return expo(a, b - 1) * a % MOD;
}


int main(){
    int t; cin >> t;

    while(t--){
        ll a, b; cin >> a >> b;
        cout << expo(a, b) << endl;
    }
}