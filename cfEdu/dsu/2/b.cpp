#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(vector<int> &p, int a) {
    return p[a] = (p[a]==a ? a : get(p,p[a]));
}

void Union(vector<int> &p, int a, int b) {
    p[a] = get(p,b);
}

int main() { _
    int n;
    cin >> n;
    vector<int> p(n+1);
    for(int i=0;i<=n;i++) p[i]=i;

    int x;
    for(int i=0;i<n;i++) {
        cin >> x;
        x--;
        auto sla = get(p,x);
        if(sla==n) sla = get(p,0);
        cout << sla+1 << ' ';
        Union(p,sla,sla+1);
    }
    
    cout << '\n';

    return 0;
}
