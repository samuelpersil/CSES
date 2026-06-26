#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int main(){fastio
    ll x, y; cin >> x >> y;

    x--, y--;

    cout << (x ^ y);
    
}