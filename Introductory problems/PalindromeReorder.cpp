#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define F first
#define S second

using namespace std;

int main(){ fastio
    string s; cin >> s;
    int size = s.length();
    unordered_map<char, int> freq;

    for(int i = 0; i < size; i++){
        freq[s[i]]++;
    }

    char ans[size];

    int count = 0, odds = 0;

    for(auto c : freq){
        while(c.S > 0){
            if(c.S % 2 == 1){
                if(odds == 1){
                    cout << "NO SOLUTION";
                    return 0;
                }
                ans[size/2] = c.F;
                c.S--;
                odds++;
            }
            else{
                ans[count] = c.F;
                ans[size - count - 1] = c.F;
                c.S -= 2;
                count++;
            }
        }
    }

    for(int i = 0; i < size; i++){
        cout << ans[i];
    }

}