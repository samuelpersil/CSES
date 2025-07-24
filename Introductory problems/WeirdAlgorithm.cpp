#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

using namespace std;

int main(){ fastio
    ll n; cin >> n;

    cout << n << ' ';

    while(n != 1){
        if(n % 2 == 0){
            n /= 2;
        }
        else n = 3*n + 1;

        cout << n << ' ';
    }
}