#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define oo 1000000000000000000
#define MAXN 20

using namespace std;

ll n, best = oo, now = 0, tsum;
ll nums[MAXN];

void subset(ll i){
    if(i == n){
        if(tsum - 2 * now >= 0) best = min(best, tsum - 2 * now);
    }
    else{
        subset(i + 1);
        now += nums[i];
        subset(i + 1);
        now -= nums[i];
    }
}

int main(){fastio
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> nums[i];
        tsum += nums[i];
    }

    subset(0);

    cout << best;

}