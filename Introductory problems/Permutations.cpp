#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

using namespace std;

int main(){ fastio
    ll n; cin >> n;
    ll answer[n];

    if(n == 1){
        cout << 1;
        return 0;
    }

    if(n <= 3){
        cout << "NO SOLUTION";
        return 0;
    }

    if(n == 4){
        cout << "3 1 4 2";
        return 0;
    }

    ll now = 1;

    for(ll i = 0; i < n; i += 2){
        answer[i] = now;
        now++;
    }
    for(ll i = 1; i < n; i += 2){
        answer[i] = now;
        now++;
    }

    for(ll i = 0; i < n; i++){
        cout << answer[i] << " ";
    }

}