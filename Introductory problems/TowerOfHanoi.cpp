#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

void hanoi(int n, int from, int to, int aux){
    if(n == 0) return;

    hanoi(n - 1, from, aux, to);
    cout << from << " " << to << endl;
    hanoi(n - 1, aux, to, from);

}

int main(){fastio
    int n; cin >> n;

    cout << ((1 << n) - 1) << endl;
    hanoi(n, 1, 3, 2);
    return 0;
}