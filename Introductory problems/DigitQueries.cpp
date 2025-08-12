#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int main(){fastio
    int t; cin >> t;

    while(t--){
        ll n; cin >> n;

        ll magnitude = 1, order = 1;

        while(n > 9 * magnitude * order){
            n -= 9 * magnitude * order;
            order++;
            magnitude *= 10;
        }

        string target = to_string((n - 1)/order + magnitude);

        cout << target[(n - 1) % order] << endl;
    }
}