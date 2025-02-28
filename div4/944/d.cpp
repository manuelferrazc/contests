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

    while(n) {
        n--;
        cin >> s;

        int c = 1, e=0;
        for(int i=1;i<s.size();i++) {
            if(s[i]=='0' and s[i-1]=='1') c++;
            if(s[i]=='1' and s[i-1]=='0') e++;
        }
        if(e<=1) cout << c << endl;
        else cout << c+e-1 << endl;
    }

    return 0;
}