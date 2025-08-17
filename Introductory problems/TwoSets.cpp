#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long
#define F first
#define S second

using namespace std;

int main(){fastio
    ll n; cin >> n;

    if((n * (n + 1) / 2) % 2 != 0){
        cout << "NO";
    }
    else{
        cout << "YES" << endl;
        if(n % 2 == 0){
            cout << n/2 << endl;
            for(int i = 1; i <= n/2; i+=2){
                cout << i << " ";
            }
            for(int i = n; i > n/2; i-=2){
                cout << i << " ";
            }
            cout << endl << n/2 << endl;
            for(int i = 2; i <= n/2; i+=2){
                cout << i << " ";
            }
            for(int i = n - 1; i >= n/2; i-=2){
                cout << i << " ";
            }
        }
        else{
            ll first_pairs = (n + 1) / 4 - 1;
            cout << 2 * first_pairs + 1 << endl;
            cout << n << " ";
            for(int i = 1; i <= first_pairs; i++){
                cout << i << " ";
            }
            for(int i = first_pairs; i >= 1; i--){
                cout << n - i << " ";
            }
            cout << endl << n - 2 * first_pairs - 1 << endl;
            for(int i = first_pairs + 1; i <= n/2; i++){
                cout << i << " ";
            }
            for(int i = n/2; i >= first_pairs + 1; i--){
                cout << n - i << " ";
            }
        }
    }
}