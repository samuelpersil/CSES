#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl '\n'

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    if(a.first != b.first) return a.first < b.first;
    return a.second > b.second;
}

signed main(){fastio
    int n; cin >> n;
    vector<pair<int, int>> events;
    for(int i = 0; i < n; i++){
        int a, b; cin >> a >> b;
        events.push_back({a, 1});
        events.push_back({b, -1});
    }

    sort(events.begin(), events.end(), comp);

    int now = 0, best = 0;
    for(auto x : events){
        // cout << x.first << " " << x.second << endl;
        now += x.second;
        best = max(now, best);
    }

    cout << best << endl;

    return 0;
}