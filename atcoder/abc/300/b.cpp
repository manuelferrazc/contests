#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n,m;

bool fun(vector<string> &a, vector<string> &b,int x,int y) {
    for(int i=0;i<n;i++) for(int j=0;j<m;j++)
            if(a[i][j]!=b[(i+x)%n][(j+y)%m]) return false;
    return true;
}

int main() { _
    cin >> n >> m;
    vector<string> a(n),b(n);
    for(auto &i:a) cin >> i;
    for(auto &i:b) cin >> i;
    
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(fun(a,b,i,j)) {
                cout << "Yes\n";
                return 0;
            }
        }
    }
    cout << "No\n";
    return 0;
}
