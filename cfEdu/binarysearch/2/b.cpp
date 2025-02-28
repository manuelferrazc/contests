#include <bits/stdc++.h>
#include <iomanip>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
 
bool check(vector<double> &v, ll k, double s) {
    for(ull i=0;i<v.size();i++) {
        if(v[i]<s) continue;
        k-=floor(v[i]/s);
        if(k<=0) return true;
    }
    return false;
}
 
int main() { _
    int n, k;
    cin >> n >> k;
    vector<double> v(n);
    for(auto &i:v) cin >> i;
 
    double l=1e-7,r=10000000;
 
    while(fabs(r-l)>=1e-8) {
        double m = (l+r)/2;
        if(check(v,k,m)) l = m;
        else r = m;
    }
    cout << fixed << setprecision(8);
    cout << r << '\n';
 
    return 0;
}