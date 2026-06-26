#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    int n, m; cin >> n >> m;

    map<int, int> prices;

    for(int i = 0; i < n; i++){
        int value; cin >> value;
        prices[value]++;
    }

    while(m--){
        int x; cin >> x;

        auto price = prices.upper_bound(x);
        if(price == prices.begin()){
            cout << -1 << endl;
            continue;
        }
        price--;
        cout << (price)->first << endl;

        if(--(price->second) == 0){
            prices.erase(price->first);
        }
    }

    return 0;
}