#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
 
using namespace std;
 
int main(){fastio
    ll n; cin >> n;
    ll ans = 0;
    ll pow = 2;
    n++;
 
    while(n >= pow/2){
        ll a = n / pow, b = pow / 2;
        ans += a * b + max(0LL, n % pow - b);
        pow *= 2;
    }
    cout << ans << endl;
 
    return 0;
 
}