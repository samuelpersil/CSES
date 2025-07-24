#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

using namespace std;

int main(){ fastio
    ll n, input, sum; cin >> n;
    sum = n * (n + 1) / 2;

    n--;

    while(n--){
        cin >> input;
        sum -= input;
    }

    cout << sum;

}