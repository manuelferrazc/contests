#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

double dist(pair<double,double> &a,pair<double,double> &b) {
    return sqrt(pow(a.ff-b.ff,2)+pow(a.ss-b.ss,2));
}

int main() { _
    int n,k;
    cin >> n >> k;

    vector<pair<double,double>> v(n);
    for(pair<double,double> &p:v) cin >> p.ff >> p.ss;
    sort(v.begin(),v.end());

    double d=1e15;
    if(k==1) d=0;
    
    for(int i=0;i+k-1<n;i++) d=min(d,dist(v[i],v[i+k-1]));
    
    cout << fixed << setprecision(13) << d*d*(3.1415926535/4) << '\n';
    return 0;
}
