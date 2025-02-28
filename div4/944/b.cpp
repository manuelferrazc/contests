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
typedef pair<int,int> pii;


int main() { _
    int n; cin >> n;
    string s;

    while(n--) {
        cin >> s;
        bool mudou = false;
        char start = s[0];
        for(int i=1;i<s.size();i++) {
            if(s[i]!=start) {
                mudou = true;
                s[0] = s[i];
                s[i] = start;
                break;
            }
        }
        if(mudou) {
            cout << "YES\n" << s << endl;
        } else cout << "NO\n";
    }
    

    return 0;
}