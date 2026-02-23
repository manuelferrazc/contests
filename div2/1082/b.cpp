#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * yes = "YES\n";
const char * no  = "NO\n";

const char * solve() {
    int n;
    string x;
    cin >> n >> x;
    
    if(n==1 and x[0] == 'b') return no;
    if(n==1) return yes;
    if((n&1) and x[0]=='b') return no;

    for(int i=(n&1);i<n-1;i+=2) {
        if(x[i]!='?' and x[i]==x[i+1]) return no;
    }

    return yes;
    // int c[2];
    // c[0] = c[1] = 0;
    // int ex=0;
    // for(int i=0;i<n;i++) {
    //     if(x[i]=='?') ex++;
    //     else c[x[i]-'a']++;

    //     if((n&1) and (c[0]>c[1]+ex+1 or c[1]>c[0]+ex)) return no;
    //     else if(n%2==0) {
    //         if(i&1) {
    //             if(max(c[0],c[1])>min(c[0],c[1])+ex) return no;
    //         } else {
    //             if(max(c[0],c[1])>min(c[0],c[1])+ex+1) return no;
    //         }
    //     }
    // }

    // for(int i=1;i<n-1;i++) {
    //     if(x[i]=='?') continue;
    //     if(x[i]==x[i-1] and x[i]==x[i+1]) return no;
    // }

    // if(n&1 and (c[0]>(n+1)/2 or c[1]>n/2)) return no;
    // else if(n%2==0 and max(c[0],c[1])>n/2) return no;

    // return yes;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
