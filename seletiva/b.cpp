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
typedef pair<int,int> pii;


int main() { _
    int n;
    cin >> n;
    vector<pii> v(n);
    map<int,int> s;
    ll largura = 0, max1=0, max2=0;
    for(int i=0;i<n;i++) {
        cin >> v[i].f >> v[i].s;
        largura+=v[i].f;
        if(s.count(v[i].s)) s.at(v[i].s)++;
        else s.insert({v[i].s,1});
    }

    auto it = s.rbegin();
    if((*it).s>1) max1=max2=(*it).f;
    else {
        max1 = (*it).f;
        it++;
        max2 = (*it).f;
    }
    
    for(int i=0;i<n;i++) {
        ll m = v[i].s==max1 ? max2 : max1;
        cout << (largura-v[i].f)*m << " ";
    }
    cout << endl;
    return 0;
}