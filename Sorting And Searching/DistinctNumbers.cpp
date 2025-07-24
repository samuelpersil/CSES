#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){ fastio
    ll n, val; cin >> n;

    set<ll> numbers;

    while(n--){
        cin >> val;
        numbers.insert(val);
    }

    cout << numbers.size();
}