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

    array<int,3> v[n];
    for(int i=0;i<n;i++) {
        int x;
        cin >> x;

        v[i][0] = x;
        v[i][1] = min(i,n-i-1);
        v[i][2] = max(i,n-i-1);
    }

    if(n<3) {
        int x = 0;
        for(auto[a,b,c]:v) x = max(x,a);
        for(int i=0;i<n;i++) cout << x << ' ';
        cout << '\n';
        return 0;
    }

    array<int,3> v2[n-2];
    for(int i=1;i<n-1;i++) {
        v2[i-1][0] = min(v[i][0],max(v[i-1][0],v[i+1][0]));
        v2[i-1][1] = min(i-1,n-i-2);
    }

    auto f = [] (array<int,3> const &a, array<int,3> const &b) -> bool {
        if(a[0]>b[0]) return true;
        if(b[0]>a[0]) return false;
        if(a[1]>b[1]) return true;
        if(b[1]>a[1]) return false;
        return a[2]>b[2];
    };

    sort(v,v+n,f);
    sort(v2,v2+(n-2),f);

    int ans[n];
    ans[n-1] = v[0][0];
    int p=0,i=0;
    for(int j=0;j<n;j++) {
        auto [x,l,r] = v[j];

        while(p<=l) {
            if(p==l and l==r) break;
            int qtd = 2*p+2;
            ans[n-qtd] = x;
            p++;
        }
    }

    for(int j=0;j<n-2;j++) {
        auto [x,l,fds] = v2[j];

        while(i<=l) {
            int qtd = 2*i+3;
            ans[n-qtd] = x;
            i++;
        }
    }

    for(int j=0;j<n;j++) cout << j[ans] << ' ';
    cout << '\n';
    return 0;
}
