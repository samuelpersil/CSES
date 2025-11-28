#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define endl '\n'
#define ll long long
#define oo 1000000000

using namespace std;

int main(){fastio
    int n; cin >> n;

    vector<int> steps(n + 1);

    steps[0] = 0;

    for(int i = 1; i <= n; i++){
        int number = i;
        steps[i] = oo;

        while(number > 0){
            steps[i] = min(steps[i], steps[i - number % 10] + 1);
            number /= 10;
        }
    }

    cout << steps[n] << endl;
}