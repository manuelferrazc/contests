#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int mat[6][12];
    memset(mat, 0, sizeof mat);

    int n; cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 6; j++){
            string s; cin >> s;
            for(int k = 0; k < int(s.size()); k++) mat[j][s[k]-'A']++;
        }
    }

    for(int i = 0; i < 6; i++){
        for(int j = 0; j < 12; j++) if(mat[i][j] == n) cout << char(j+'A');
        cout << ' ';
    }
    cout << endl;

    return 0;
}