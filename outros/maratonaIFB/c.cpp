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

int g;

class Compare {
    public:
        bool operator()(int a, int b){
            if(abs(a-g)>abs(b-g)) return true;
            return false;
        }
};

int main() { _
    int r,s;
    cin >> r >> s;

    priority_queue<int,vector<int>,Compare> j1,j2;

    vi v1(r),v2(s);
    for(int i=0;i<r;i++) cin >> v1[i];
    for(int i=0;i<s;i++) cin >> v2[i];

    int b;
    cin >> b >> g;
    for(auto i:v1) j1.push(i);
    for(auto i:v2) j2.push(i);

    for(int i=0;i<b;i++) {cout << j1.top() << ' ';j1.pop();}
    cout << '\n';
    for(int i=0;i<b;i++) {cout << j2.top() << ' '; j2.pop();}
    cout << '\n';

    return 0;
}
