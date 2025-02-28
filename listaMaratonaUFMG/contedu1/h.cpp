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
    int n,x;
    cin >> n;

    list<int> l;
    while(n--) {
        cin >> x;
        l.push_back(x);
    }

    int a[] = {0,0};
    int j=1;
    while(l.size()) {
        if(l.front()>l.back()) {
            a[j=!j]+=l.front();
            l.pop_front();
        } else {
            a[j=!j]+=l.back();
            l.pop_back();
        }
    }

    cout << a[0] << ' ' << a[1] << '\n';

    return 0;
}
