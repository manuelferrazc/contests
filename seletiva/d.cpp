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
typedef pair<int,int> pii;

void solve() {
    int p;
    cin >> p;
    string s;
    cin >> s;

    int n,e;
    cin >> n >> e;

    for(int i=0;i<e;i++) {
        int a,b;
        cin >> a >> b;
    }
    int ganhou = e-(n-1);
    
    if(s[(ganhou)%p]=='1') cout << "2\n";
    else cout << "1\n";
}

int main() { _
    int t;
    cin >> t;

    while(t--) solve();

    return 0;
}