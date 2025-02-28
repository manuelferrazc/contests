#include <bits/stdc++.h>

using namespace std;

int main() {
    int n;
    cin >> n;

    vector<vector<int>> v(n,vector<int>(n));

    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> v[i][j];

    bool b=false;
    for(int c=0;c<n;c++) {
        for(int l=1;l<n;l++) {
            if(v[l-1][c]>=v[l][c]) {b=true;break;}
        }
        if(b) break;
    }

    bool b2 = false;
    for(int l=0;l<n;l++) {
        for(int c=1;c<n;c++) {
            if(v[l][c-1]>=v[l][c]) {b2=true;break;}
        }
        if(b2) break;
    }

    if(b == false and b2==false) cout << "0\n";
    else if(b and b2) cout << "2\n";
    else if(b2==false) cout << "3\n";
    else cout << "1\n";

    return 0;
}