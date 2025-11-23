#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

ll expo(ll a, ll b, ll MOD){    
    if(b == 0) return 1;
    if(b % 2 == 0){
        ll half = expo(a, b/2, MOD) % MOD;
        return half * half % MOD;
    }
    return expo(a, b - 1, MOD) * a % MOD;
}


int main(){
    int t; cin >> t;

    while(t--){
        ll a, b, c; cin >> a >> b >> c;
        cout << expo(a, expo(b, c, 1000000006), 1000000007) << endl;
    }
}