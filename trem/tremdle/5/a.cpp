#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int get(char a, char b) {
    int r=0;
    for(char c=a;c!=b;) {
        if(c=='9') c='0';
        else c++;
        r++;
    }
    int r2=0;
    for(char c=a;c!=b;) {
        if(c=='0') c='9';
        else c--;
        r2++;
    }
    return min(r,r2);
}

int main() { _
    int n;
    cin >> n;
    string a,b;
    cin >> a >> b;
    int ans=0;
    for(int i=0;i<n;i++) ans+=get(a[i],b[i]);
    cout << ans << '\n';
    return 0;
}
