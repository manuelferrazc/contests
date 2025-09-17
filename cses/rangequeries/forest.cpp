#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,q,x1,x2,y1,y2;
    cin >> n >> q;

    int sp[n+1][n+1];
    for(int i=0;i<=n;i++) sp[i][0] = sp[0][i] = 0;

    for(int i=1;i<=n;i++) {
        string s;
        cin >> s;

        for(int j=1;j<=n;j++) {
            sp[i][j]=sp[i-1][j]+sp[i][j-1]-sp[i-1][j-1];
            if(s[j-1]=='*') sp[i][j]++;
        }
    }

    while(q--) {
        cin >> x1 >> y1 >> x2 >> y2;
        x1--;
        y1--;

        cout << sp[x2][y2]-sp[x1][y2]-sp[x2][y1]+sp[x1][y1] << '\n';
    }
    
    return 0;
}
