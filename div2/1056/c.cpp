#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int check(vector<int> &v, vector<bool> &dir) {
    int ql=0,qr=0,n=v.size();
    for(int i=1;i<n;i++) if(dir[i]) qr++;

    for(int i=0;i<n;i++) {
        if(v[i]!=ql+1+qr) return 0;

        if(i<n-1 and dir[i+1]) qr--;
        if(not dir[i]) ql++;
    }

    return 1;
}

int solve() {
    int n;
    cin >> n;
    vector<int> v(n);
    for(int &i:v) cin >> i;

    int ans=0;

    vector<bool> dir(n);
    dir[0] = 0;

    for(int i=1;i<n;i++) {
        if(v[i]==v[i-1]) dir[i] = not dir[i-1];
        else if(v[i]==v[i-1]+1) dir[i] = 0;
        else if(v[i]==v[i-1]-1) dir[i] = 1;
        else return 0;
    }

    ans+=check(v,dir);

    dir[0] = 1;
    for(int i=1;i<n;i++) {
        if(v[i]==v[i-1]) dir[i] = not dir[i-1];
        else if(v[i]==v[i-1]+1) dir[i] = 0;
        if(v[i]==v[i-1]-1) dir[i] = 1;
    }

    ans+=check(v,dir);

    return ans;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
