#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

void printbinaries(vector<int> delta, int n){
    int now = 0;
    for(int i = 0; i < (1 << n); i++){
        now += delta[i];

        for(int pos = n - 1; pos >= 0; pos--){
            cout << (now & (1 << pos) ? "1" : "0");
        }
        cout << endl;
    }
}

int main(){fastio
    int n; cin >> n;

    vector<int> delta((1 << n), 0);

    for(int i = 0; i < n; i++){
        int pot = (1 << i);
        for(int j = pot; j < (1 << n); j += pot * 4){
            delta[j] += pot;
            if(j + pot * 2 < (1 << n)) delta[j + pot * 2] -= pot;
        }
    }

    printbinaries(delta, n);

    return 0;
}