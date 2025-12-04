#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    int n; cin >> n;

    int coins[n];

    for(int i = 0; i < n; i++){
        cin >> coins[i];
    }

    sort(coins, coins + n);

    ll sum = 0;

    for(auto coin : coins){
        if(coin > sum + 1){
            cout << sum + 1 << endl;
            return 0;
        }

        sum += coin;
    }

    cout << sum + 1 << endl;


}