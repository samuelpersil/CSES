#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

using namespace std;

int main(){ fastio
    ll n, sum = -1e18, maximum = -1e18, value; cin >> n;

    while(n--){
        cin >> value;
        sum = max(value, sum + value);
        maximum = max(sum, maximum);
    }

    cout << maximum;

}