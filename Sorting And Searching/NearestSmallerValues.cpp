#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define F first
#define S second

using namespace std;

int main(){fastio
    int n; cin >> n;

    stack<pair<int, int>> s;

    for(int i = 0; i < n; i++){
        int value; cin >> value;

        while(!s.empty() && value <= s.top().F){
            s.pop();
        }

        if(s.empty()) cout << "0 ";
        else cout << s.top().S << " ";

        s.push({value, i + 1});
    }

    cout << endl;
}