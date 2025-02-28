#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define ff first
#define ss second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef map<int,int> mii;
typedef set<int> si;

int main() { _
    int c,n, lucro = 0;
    cin >> n >> c;

    vi v(n);
    int pagou=INT_MAX,vendeu = 0,min=INT_MAX, max=INT_MIN;

    for(int i=0;i<n;i++) {
        if(v[i]<min) {
            if(pagou!=INT_MAX) lucro+=vendeu-pagou;
            pagou = v[i]+c;
            vendeu = 0;
            min = v[i];
        } else if(v[i]>max and v[i]+c>pagou) {
            vendeu = v[i];
            
        }
    }

    cout << lucro+vendeu-pagou << '\n';
    return 0;
}
