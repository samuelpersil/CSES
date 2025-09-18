#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

int main(){fastio
    int n; cin >> n;

    int array[n];

    for(int i = 0; i < n; i++){
        cin >> array[i];
    }

    sort(array, array + n);

    ll middle = array[n/2], answer = 0;

    for(int i = 0; i < n; i++){
        answer += abs(array[i] - middle);
    }

    cout << answer << endl;
}