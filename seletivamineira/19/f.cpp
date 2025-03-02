#include <bits/stdc++.h>
 
using namespace std;
 
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define f first
#define s second
typedef long long ll;
typedef unsigned long long ull;

struct st {
    ll problems;
    ll pen;
    ll id;

};

bool operator<(st x, st y) {
    if(x.problems>y.problems) return true;
    else if(x.problems<y.problems) return false;
    else {
        if(x.pen<y.pen) return true;
        else if(x.pen>y.pen) return false;
        else return x.id<=y.id;
    }
}

int main() { _
    ll n;
    cin >> n;
    vector<st> v(n);
    for(ll i=0;i<n;i++) cin >> v[i].id >> v[i].problems >> v[i].pen;

    sort(v.begin(),v.end());
    ll pos = 1,ig=1;
    for(ll i=0;i<n;i++) {
        cout << pos << ' ' << v[i].id << ' ' << v[i].problems << ' ' << v[i].pen << '\n';
        if(i<n-1 and (v[i].problems!=v[i+1].problems or v[i].pen!=v[i+1].pen)) pos+=ig,ig=1;
        else {ig++;} 
    }
    return 0;
}
