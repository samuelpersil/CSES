#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

struct DSU {
    int n;
    vector<int> parent, size;
    int components, biggest = 1;

    DSU(int n): n(n) {
        parent.resize(n, 0);
        size.assign(n, 1);
        components = n;

        for(int i=0;i<n;i++)
            parent[i] = i;
    }

    int find(int a) {
        if(a == parent[a]) return a;
        return parent[a] = find(parent[a]);
    }

    void join(int a, int b) {
        a = find(a); b = find(b);
        if(a != b) {
            if(size[a] < size[b]) swap(a, b);
            parent[b] = a;
            size[a] += size[b];
            components--;
            biggest = max(biggest, size[a]);
        }
    }
};

int main(){fastio
    int n, m; cin >> n >> m;

    DSU dsu(n);

    while(m--){
        int a, b; cin >> a >> b;
        dsu.join(a - 1, b - 1);

        cout << dsu.components << " " << dsu.biggest << endl;
    }

    return 0;
}