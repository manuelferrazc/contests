#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

double k;

bool testa(vector<double> &v, double d) {
    double x = 0;

    for(ull i=0;i<v.size();i++) {
        if(v[i]>d) x+=(v[i]-d)*k;
        else x-=d-v[i];
    }

    return x>0.0;
}

void bb(vector<double> &v, double a, double b) {
    if(fabs(a-b)<1e-7) {
        cout << a << '\n';
        exit(0);
    }

    double m = (a+b)/2;

    if(testa(v,m)) bb(v,m,b);
    bb(v,a,m);
}

int main() { _
    int n;
    cin >> n >> k;
    k/=100;
    k = 1-k;

    vector<double> v(n);
    for(int i=0;i<n;i++) cin >> v[i];

    sort(v.rbegin(),v.rend());
    cout << fixed << setprecision(9);

    bb(v,0,1000);

    return 0;
}
