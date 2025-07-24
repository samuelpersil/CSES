#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){ fastio
    ll n; cin >> n;
    ll answer;

    for(ll k = 1; k < n + 1; k++){
        if(k == 1) cout << 0;
        else if(k == 2) cout << 6;
        else if(k == 3) cout << 28;
        else{
            answer = ( ( k * k * (k * k - 1) - (2*4+3*8+4*( (k-4)*4 + 4  )+6*( (k-4) * 4) + 8 *(k-4)*(k-4))  ) / 2 );
            cout << answer;
        }
        cout << endl;
    }
}