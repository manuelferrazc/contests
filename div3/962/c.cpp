#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
#define INF INT_MAX
#define LINF LONG_MAX
#define LLINF LONG_LONG_MAX
typedef long long ll;
typedef long l;
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> pii;



int main() { _
    int t,n,q,l,r,resp;
    cin >> t;
    string a,b;
    
    while(t--) {
        cin >> n >> q >> a >> b;
        vector<vector<int>> va(26,vector<int>(n)),vb(26,vector<int>(n));
        
        for(int i=0;i<26;i++) {va[i][0] = i==(a[0]-'a');vb[i][0] = i==(b[0]-'a');};
        for(int i=1;i<n;i++) {
            for(int j=0;j<26;j++) {
                va[j][i] = va[j][i-1]+(j==(a[i]-'a'));
                vb[j][i] = vb[j][i-1]+(j==(b[i]-'a'));
            }
        }

        while(q--) {
            resp=0;
            cin >> l >> r;
            l--;
            r--;
            for(int le = 0;le<26;le++) {
                if((va[le][r]-va[le][l]+(a[l]-'a'==le))>(vb[le][r]-vb[le][l]+(b[l]-'a'==le))) {
                    resp+=(va[le][r]-va[le][l]+(a[l]-'a'==le))-(vb[le][r]-vb[le][l]+(b[l]-'a'==le));
                }
            }
            cout << resp << '\n';
        }
    }
    return 0;
}