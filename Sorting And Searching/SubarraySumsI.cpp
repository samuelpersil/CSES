#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    ll n, x; cin >> n >> x;

    ll array[n], sum = 0, answer = 0, r = 0, l = 0;

    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    sum += array[0];

    while(r < n){
        //cout << l << " " << r << " " << sum << endl;
        if(sum == x){
            answer++;
            r++;
            if(r < n) sum += array[r];
        }
        else if(sum > x && l != r){
            l++;
            sum -= array[l - 1];
        }
        else{
            r++;
            if(r < n) sum += array[r];
        }
    }

    cout << answer << endl;
}
