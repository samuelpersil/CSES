#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define int long long
#define endl '\n'

using namespace std;

const int neutral = 0;

struct Segtree {
    int n;
    vector<int> tree;

    Segtree(int n) : n(n), tree(2*n, neutral) {}

    int f(int a, int b){
        return a + b;
    }

    void build(){
        for(int i = n - 1; i >= 1; i--){
            tree[i] = f(tree[2*i], tree[2*i+1]);
        }
    }

    int query(int l, int r){
        l += n; r += n;
        int s = neutral;
        while(l <= r){
            if(l%2 == 1) s = f(s, tree[l++]);
            if(r%2 == 0) s = f(s, tree[r--]);
            l /= 2; r /= 2;
        }
        return s;
    }

    void update(int k, int x){
        k += n;
        tree[k] += x;
        for(k /= 2; k >= 1; k /= 2){
            tree[k] = f(tree[2*k], tree[2*k+1]);
        }
    }
};

signed main(){fastio
    int n, q; cin >> n >> q;
    int arr[n];
    for(auto &x : arr) cin >> x;
    Segtree seg(n);
    seg.build();

    while(q--){
        int op; cin >> op;
        if(op == 1){
            int a, b, u; cin >> a >> b >> u;
            a--, b--;
            seg.update(a, u);
            if(b + 1 < n) seg.update(b + 1, -u);
        }
        if(op == 2){
            int k; cin >> k;
            k--;
            cout << arr[k] + seg.query(0, k) << endl;;
        }
    }

    return 0;
}


