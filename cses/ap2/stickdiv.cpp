#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int x,n;
    cin >> x >> n;

    ll ans = 0;

    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        pq.push(a);
    }

    for(int i=1;i<n;i++) {
        int a = pq.top();
        pq.pop();
        int b = pq.top();
        pq.pop();

        pq.push(a+b);
        ans+=a+b;
    }

    cout << ans << '\n';

    return 0;
}
