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


int main() { 
    int t,n,k;
    cin >> t;
    char c;

    while(t--) {
        cin >> n >> k;
        vector<vector<int>> v(n,vector<int>(n));
        for(int i=0;i<n;i++) for(int j=0;j<n;j++){
            cin >> c;
            v[i][j] = c-'0';
        }
        int s = n/k;
        vector<vi> resp(s,vi(s));
        for(int i=0;i<s;i++) for(int j=0;j<s;j++) resp[i][j] = v[i*k][j*k];

        for(int i=0;i<s;i++) {
            for(int j=0;j<s;j++) cout << resp[i][j];
            cout << '\n';
        }
    }
    return 0;
}