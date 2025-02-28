#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

int main() { 
    int n;

    cin >> n;
    vector<pair<int,string>> v(n);

    for(int i=0;i<n;i++) 
        cin >> v[i].ss >> v[i].ff;
    
    sort(v.begin(),v.end());

    int mind = INT_MAX, maxd = INT_MIN;

    ull u = 0;

    vector<pair<int,string>> out;

    while(u<v.size()-1) {
        mind = min(mind,v.back().ff+v[u].ff);
        maxd = max(maxd,v.back().ff+v[u].ff);
        out.push_back(v[u]);
        out.push_back(v.back());
        v.pop_back();
        u++;
    }

    cout << maxd - mind << '\n';
    for(ull i=0;i<out.size();i+=2) 
        cout << out[i].ss << ' ' << out[i].ff << ' ' << out[i+1].ss << ' ' << out[i+1].ff << '\n';
    

    return 0;
}
