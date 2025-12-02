#include <bits/stdc++.h>
#include <random>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int getMax(int &rem) {
    int l = 0, r=1e9;
    int ans=0;
    
    while(l<=r) {
        int m = (l+r)/2,q;

        rem--;
        cout << "> " << m << '\n';
        cin >> q;

        if(q) l=m+1;
        else {
            r=m-1;
            ans = m;
        }
    }
    
    return ans;
}


int main() {
    mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
    int n,a;
    cin >> n;
    
    int rem = 60;
    int mx = getMax(rem);

    vector<int> q;
    vector<int> perm(n);
    iota(perm.begin(),perm.end(),1);
    shuffle(perm.begin(),perm.end(),rng);

    for(int i=0;i<n and rem;i++,rem--) {
        cout << "? " << perm[i] << '\n';
        cin >> a;

        q.push_back(a);
    }

    sort(q.begin(),q.end());
    int d = q[1]-q[0];
    int n2 = q.size();

    for(int i=0;i<n2-1;i++) {
        for(int j=i+1;j<n2;j++) {
            d = gcd(d,q[j]-q[i]);
        }
    }

    // an = a1+ (n-1)d
    // a1 = an - (n-1)d

    int a1 = mx - (n-1)*d;
    cout << "! " << a1 << ' ' << d << '\n';

    return 0;
}
