#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
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

int main() { _
    int n;
    cin >> n;

    while(n--) {
        int su[2],sl[2];
        cin >> su[0] >> su[1] >> sl[0] >> sl[1];

        int r=0;

        for(int i=0;i<2;i++) {
            for(int j=0;j<2;j++) {
                if(su[i]>=sl[j] and su[1-i]>sl[1-j]) r++;
                else if(su[i]>sl[j] and su[1-i]>=sl[1-j]) r++;
            }
        }

        cout << r << '\n';
    }

    return 0;
}