#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0); cin.tie(nullptr); cout.tie(nullptr);
#define ll long long
#define endl '\n'

using namespace std;

string matrix[8];
int answer = 0, column[8] = {0}, diagonal1[8 * 2 - 1] = {0}, diagonal2[8 * 2 - 1] = {0};

void search(int i){
    if(i == 8){
        answer++;
        return;
    }

    for(int j = 0; j < 8; j++){
        if(matrix[i][j] == '.' && column[j] == 0 && diagonal1[i+j] == 0 && diagonal2[8 - i + j - 1] == 0){
            column[j] = 1, diagonal1[i+j] = 1, diagonal2[8 - i + j - 1] = 1;
            search(i + 1);
            column[j] = 0, diagonal1[i+j] = 0, diagonal2[8 - i + j - 1] = 0;
        }
    }
}

int main(){fastio
    
    for(int i = 0; i < 8; i++){
        cin >> matrix[i];
    }

    search(0);

    cout << answer;
}