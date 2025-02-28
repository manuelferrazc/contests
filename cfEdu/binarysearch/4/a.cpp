#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,d;
vector<int> v;

bool check(double x) {
    vector<double> p(v.size()+1),m(v.size()+1);
    p[0] = m[0] = 0;
    for(int i=1;i<=n;i++) {
        p[i] = p[i-1]+(v[i-1]-x);
        m[i] = min(m[i-1],p[i]);
    }

    for(int i=d;i<=n;i++) 
        if(p[i]>=m[i-d]) return true;

    return false;
}

void get(double x) {
    vector<double> p(v.size()+1),m(v.size()+1);
    p[0] = m[0] = 0;
    for(int i=1;i<=n;i++) {
        p[i] = p[i-1]+(v[i-1]-x);
        m[i] = min(m[i-1],p[i]);
    }

    for(int i=d;i<=n;i++) {
        if(p[i]>=m[i-d]) {
            for(int j=0;;j++) {
                if(fabs(p[j]-m[i-d])<1e-9) {
                    cout << j+1 << ' ' << i << '\n';
                    return;
                }
            }
        }
    }
}

int main() { _
    cin >> n >> d;
    v.resize(n);
    for(auto &i:v) cin >> i;

    double l=0,r=100.0,ans=-1;

    while(fabs(r-l)>1e-9) {
        double m=(l+r)/2;

        if(check(m)) {
            ans=max(ans,m);
            l=m;
        } else r=m;
    }

    get(ans);

    return 0;
}
