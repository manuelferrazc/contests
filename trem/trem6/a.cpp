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
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> pii;


int main() { _
    int n; cin >> n;

    vi v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sort(v.begin(),v.end(),greater<int>());
    
    int total=0,i=0;
    for(;i<n-2;i+=3) total += v[i]+v[i+1];    

    if(i<n) total+=v[i];

    cout << total << endl;

    return 0;
}