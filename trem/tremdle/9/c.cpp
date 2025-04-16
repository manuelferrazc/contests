#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() {
    int n;
    cin >> n;
    string s;
    int um=1;
    for(int i=2;i<=n;i++) {
        cout << "? " << um << ' ' << um << ' ' << i << '\n';
        cout.flush();
        cin >> s;
        if(s[0]=='Y') um = i;
    }

    vector<int> v;
    v.push_back(1);

    for(int i=2;i<=n;i++) {
        int l = 0, r = v.size();

        while(l<r) {
            int m = (l+r)>>1;
            cout << "? " << um << ' ' << i << ' ' << v[m] << '\n';
            cout.flush();
            cin >> s;
            if(s[0]=='-') return 0;
            else if(s[0]=='Y') l=m+1;
            else r=m;
        }

        v.insert(v.begin()+r,i);
    }

    cout << "! ";
    for(int i=1;i<=n;i++) {
        for(ull j=0;j<v.size();j++) {
            if(v[j]==i) {
                cout << j+1 << ' ';
                break;
            }
        }
    }
    cout << '\n';
    return 0;
}
