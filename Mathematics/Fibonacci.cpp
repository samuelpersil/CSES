#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define vll vector<ll>
#define MOD 1000000007

using namespace std;

vector<vll> mult(vector<vll> a, vector<vll> b){
    vector<vll> to_return = {{0, 0}, {0, 0}};
    to_return[0][0] = (a[0][0] * b[0][0] + a[0][1] * b[1][0]) % MOD; 
    to_return[0][1] = (a[0][0] * b[0][1] + a[0][1] * b[1][1]) % MOD;
    to_return[1][0] = (a[1][0] * b[0][0] + a[1][1] * b[1][0]) % MOD;
    to_return[1][1] = (a[1][0] * b[0][1] + a[1][1] * b[1][1]) % MOD;    

    return to_return;
}

vector<vll> expo(vector<vll> mat, ll b){
    if(b == 0) return {{1, 0}, {0, 1}};
    else if(b % 2 == 0){
        vector<vll> half = expo(mat, b/2);
        return mult(half, half);
    }
    else return mult(expo(mat, b - 1), mat);
}

int main(){fastio
    ll n; cin >> n;

    vector<vll> transformation = expo({{1, 1}, {1, 0}}, n);

    cout << transformation[0][1] << endl;

    // for(auto a : transformation){
    //     for(auto b : a){
    //         cout << b << " ";
    //     }
    //     cout << endl;
    // }

    return 0;
}