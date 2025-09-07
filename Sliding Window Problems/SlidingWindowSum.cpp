#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    ll n, k, x, a, b, c; cin >> n >> k >> x >> a >> b >> c;

    ll answer = 0, window = 0, array[n];

    array[0] = x;

    for(int i = 1; i < n; i++){
        array[i] = (a * array[i-1] + b) % c;
    }

    for(int i = 0; i < k; i++){
        window += array[i];
    }

    answer = answer ^ window;

    for(int i = k; i < n; i++){
        window += array[i];
        window -= array[i - k];

        answer = answer ^ window;
    }

    cout << answer << endl;


}