#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int main(){ fastio
    ll n, q; cin >> n >> q;

    ll sums[n + 1], value, a, b;

    sums[1] = 0;
    for(int i = 2; i < n + 2; i++){
        cin >> value;
        if(i == 2) sums[2] = value;
        else sums[i] = sums[i - 1] + value;
    }

    while(q--){
        cin >> a >> b;
        cout << sums[b+1] - sums[a] << endl;
    }
}