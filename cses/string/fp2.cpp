#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> get_z(string s) {
    int n = s.size();
    vector<int> z(n,0);

    int l=0,r=0;
    for(int i=1;i<n;i++) {
        if(i<=r) z[i] = min(r-i+1,z[i-l]);
        while(i+z[i]<n and s[z[i]]==s[i+z[i]]) z[i]++;
        if(i+z[i]-1>r) l=i,r=i+z[i]-1;
    }

    return z;
}

int main() { _
    string s;
    cin >> s;
    int n = s.size();

    vector<int> z = get_z(s);
    for(int i=1;i<n;i++) {
        if(z[i]==n-i) cout << i << ' ';
    }

    cout << n << '\n';

    return 0;
}
