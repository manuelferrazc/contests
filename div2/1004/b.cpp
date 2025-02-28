#include <bits/stdc++.h>


using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    int n;
    cin >> n;
    map<int,int> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(not m.count(a)) m.insert({a,1});
        else m.at(a)++;
    }

    for(auto i:m) {
        if(i.ss==1) {
            cout << "No\n";
            return;
        } else if(i.ss>2) {
            if(m.count(i.ff+1)) m.at(i.ff+1)+=i.ss-2;
            else m.insert(make_pair(i.ff+1,i.ss-2));
            m.at(i.ff)=2;
        }
    }
    if(m.rend()->ss&1) cout << "No\n";
    cout << "YeS\n";

}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
