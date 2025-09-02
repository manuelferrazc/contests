#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;

    vector<int> v(n);
    for(int &i:v) cin >> i;

    pair<int,int> p(INT_MAX,0);

    for(int t=2;t<100;t++) {
        int c=0;
        for(int i:v) {
            if(abs(i-t)<=1) continue;
            if(i>t) c+=i-t-1;
            else c+=t-i-1;
        }

        if(c<p.ff) {
            p.ff = c;
            p.ss = t;
        }
    }

    cout << p.ss << ' ' << p.ff << '\n';
    return 0;
}
