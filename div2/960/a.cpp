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
    int t,n,m;
    cin >> t;
    bool b;
    map<int,int> map;

    while(t--) {
        cin >> n;
        map.clear();
        while (n--) {
            cin >> m;
            if(map.count(m)) map.at(m)++;
            else map.insert({m,1});
        }
        b=false;
        for(auto it = map.rbegin();it!=map.rend();it++) {
            if((it->second)&1) {
                b=true;
                break;
            }
            if(b) break;
        }
        if(b) cout << "YES\n";
        else cout << "NO\n";
    }
    
    return 0;
}