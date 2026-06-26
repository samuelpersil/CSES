#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define oo 1000000000

using namespace std;

int minimum(int a, int b, int n, int tree[]) {
    a += n; b += n;
    int s = oo;
    while (a <= b) {
        if (a%2 == 1) s = min(s, tree[a++]);
        if (b%2 == 0) s = min(s, tree[b--]);
        a /= 2; b /= 2;
    }
    return s;
}

int main(){fastio
    int n, q; cin >> n >> q;

    int arr[n], tree[2 * n];

    tree[0] = 0;

    for(int i = 0; i < n; i++){
        cin >> arr[i];
        tree[n + i] = arr[i];
    }

    for(int i = n - 1; i > 0; i--){
        tree[i] = min(tree[2 * i], tree[2 * i + 1]);
    }

    while(q--){
        int a, b; cin >> a >> b;
        cout << minimum(--a, --b, n, tree) << endl;
    }

    return 0;
}