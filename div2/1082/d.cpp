#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no  = "NO\n";
const char * eol = "\n";

const char * solve() {
    int n,k;
    cin >> n >> k;

    if(k<n or 2*n-1<k) return no;

    queue<int> q;
    while(k<2*n-1) {
        q.push(n);
        q.push(n);
        
        k--;
        n--;
    }

    if(n==1) {
         q.push(1);
         q.push(1);
    } else if(n) {
        q.push(1);
        q.push(2);
        for(int i=3;i<=n;i++) {
            q.push(i);
            q.push(i-2);
        }
        q.push(n-1);
        q.push(n);
    }

    cout << yes;
    while(q.size()) {
        cout << q.front() << ' ';
        q.pop();
    }
    return eol;
    
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
