#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define F first
#define S second

using namespace std;

bool comp(pair<int, int> a, pair<int, int> b){
    return a.S < b.S;
}

int main(){fastio
    int n, time = 0, answer = 0; cin >> n;

    pair<int, int> array[n];

    for(int i = 0; i < n; i++){
        cin >> array[i].F >> array[i].S;
    }

    sort(array, array + n, comp);

    for(int i = 0; i < n; i++){
        if(array[i].F >= time){
            time = array[i].S;
            answer++;
        }
    }

    cout << answer;

}