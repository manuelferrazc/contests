#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool ok(int *v, int n, int k, int ans) {
    int status = 0;

    for(int i=n-1;i>=0;i--) {
        if(status==0) {
            if(v[i]>=ans) continue;
            if(v[i]+k<ans) return false;
            k--;
            status = 1;
        } else if(status==1) {
            if(v[i]+k<ans) return false;
            k--;
            if(k==0) status = 2;
        } else if(v[i]<ans) return false;
    }

    return true;
}

int main() { _
    int n,k;
    cin >> n >> k;
    
    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    int ans=1,a=1,b=1'000'000'001;

    while(a<=b) {
        int m = (a+b)/2;

        if(ok(v,n,k,m)) {
            ans = m;
            a = m+1;
        } else b= m-1;
    }

    cout << ans << '\n';

    return 0;
}
