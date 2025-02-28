#include <bits/stdc++.h>
#include <numeric>

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
    int n;
    cin >> n;

    vi v(n);
    for(auto &i:v) cin >> i;

    if(*max_element(v.begin(),v.end())<=0) {
        cout << "0\n";
        return 0;
    }

    int min = INT_MAX, act = 0;
    for(int i=0;i<n;i++) {
        act+=v[i];
        min = ::min(min,act);
        
        if(act>=0) {
            act = 0;
        }
    }
    act = 0;
    int max = INT_MIN;
    for(int i=0;i<n;i++) {
        act+=v[i];
        max = ::max(max,act);
        
        if(act<0) {
            act = 0;
        }
    }
    cout << ::max(accumulate(v.begin(),v.end(),0)-::min(min,0),max) << '\n';

    return 0;
}
