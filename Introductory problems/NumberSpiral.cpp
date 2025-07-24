#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){ fastio
    ll t; cin >> t;

    while(t--){
        ll i, j, diagonal, diagonal2;
        cin >> i >> j;

        diagonal = max(i, j);
        diagonal2 = (diagonal - 1) * (diagonal - 1) + diagonal;

        if(i == j){
            cout << diagonal2;
        }
        
        else if(diagonal % 2 == 0){
            if(i > j){
                cout << diagonal2 + (diagonal - j);
            }
            else{
                cout << diagonal2 - (diagonal - i);
            }
        }
        else{
            if(i > j){
                cout << diagonal2 - (diagonal - j);
            }
            else{
                cout << diagonal2 + (diagonal - i);
            }
        }

        cout << endl;

    }
}