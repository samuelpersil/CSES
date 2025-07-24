#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long

using namespace std;

int main(){ fastio
    string s; cin >> s;

    char last = 'A';
    ll answer = 0, now_sequence = 0;

    for(auto c : s){
        if(c == last){
            now_sequence++;
        }
        else{
            now_sequence = 1;
            last = c;
        }
        answer = max(now_sequence, answer);
    }

    cout << answer;

}