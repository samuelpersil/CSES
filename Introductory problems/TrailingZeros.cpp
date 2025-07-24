#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){ fastio
    ll n, answer = 0; cin >> n;

    while(n >= 5){
        answer += n / 5;
        n /= 5;
    }

    cout << answer;
}