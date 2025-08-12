#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){ fastio
    ll n, m, k; cin >> n >> m >> k;
    ll clients[n], sizes[m];

    for(int i = 0; i < n; i++){
        cin >> clients[i];
    }

    for(int i = 0; i < m; i++){
        cin >> sizes[i];
    }

    sort(clients, clients + n);
    
    sort(sizes, sizes + m);

    ll actual_size = 0, answer = 0;

    for(int i = 0; i < n; i++){
        while(sizes[actual_size] <= clients[i] && abs(clients[i] - sizes[actual_size]) > k && actual_size < m) actual_size++;
        if(abs(clients[i] - sizes[actual_size]) <= k){
            answer++;
            actual_size++;
        }
    }

    cout << answer;
}