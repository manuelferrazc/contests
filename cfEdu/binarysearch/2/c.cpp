#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second

int count(int n, int x, int y) {
    if(n==0) return 0;
    int l=0,r=n;
    int ans = INT_MAX;

    while(l<=r) {
        int m = (l+r)>>1;
        int t1 = m*x, t2=(n-m)*y;
        ans=min(ans,max(t1,t2));
        if(t1==t2) return ans;
        else if(t1<t2) l=m+1;
        else r=m-1;
    }

    return ans;
}

int main() { _
    int n,x,y;
    cin >> n >> x >> y;

    cout << min(x,y)+count(n-1,x,y) << '\n';

    return 0;
}
