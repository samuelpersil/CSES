#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long

using namespace std;

int main(){fastio
    int n; cin >> n;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cout << (i ^ j) << " ";
        }
        cout << endl;
    }
}