#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    int n; cin >> n;
    vector<int> coins(n);
    int total = 0, possibles_count = 0;

    for(auto &x : coins){
        cin >> x;
        total += x;
    }

    vector<bool> possible(total + 1);

    possible[0] = true;

    for(int i = 0; i < n; i++){
        for(int x = total; x >= 0; x--){
            if(possible[x]) {
                possible[x + coins[i]] = true;
            }
        }
    }

    for(int i = 1; i <= total; i++){
        if(possible[i]) possibles_count++;
    }

    cout << possibles_count << endl;
    
    for(int i = 1; i <= total; i++){
        if(possible[i]) cout << i << " ";
    }
    cout << endl;

    return 0;
}