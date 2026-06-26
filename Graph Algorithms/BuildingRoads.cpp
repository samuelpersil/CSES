#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'
#define F first
#define S second

using namespace std;

vector<int> parent, sizes;
int components;

int find(int x){
    while(x != parent[x]) x = parent[x];
    return x;
}

void join(int a, int b){
    a = find(a), b = find(b);
    if(a != b){
        if(sizes[a] < sizes[b]) swap(a, b);
        parent[b] = a;
        sizes[a] += sizes[b];
        components--;
    }
}

int main(){fastio
    int n, m; cin >> n >> m;

    components = n;
    parent.resize(n + 1, 0);
    sizes.resize(n + 1, 1);
    for(int i = 1; i <= n; i++){
        parent[i] = i;
    }

    while(m--){
        int a, b; cin >> a >> b;
        join(a, b);
    }

    cout << components - 1 << endl;

    for(int i = 2; i <= n; i++){
        if(find(1) != find(i)){
            cout << 1 << " " << i << endl;
            join(1, i);
        }
    }

    return 0;
}