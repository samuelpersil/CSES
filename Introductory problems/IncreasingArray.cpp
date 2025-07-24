#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n';

using namespace std;

int main(){ fastio
    ll n; cin >> n;
    ll last, now, moves = 0;

    for(ll i = 0; i < n; i++){
        cin >> now;
        if(i == 0){
            last = now;
            continue;
        }
        else if(now < last){
            moves += (last - now);
        }

        last = max(now, last);
    }

    cout << moves;
}