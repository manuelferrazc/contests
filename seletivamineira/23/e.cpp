#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
    
}

int main() { _
    map<int,int> m;
    for(int i=0;i<6;i++) {
        int a;
        cin >> a;
        m[a]++;
    }

    bool b=true;
    for(auto it = m.begin();it!=m.end();it++) {
        if(it->ss>=4) {
            b=false;
            it->ss-=4;
            if(it->ss==0) m.erase(it);
            break;
        }
    }

    if(b) cout << "Alien\n";
    else if(m.size()==1) cout << "Elephant\n";
    else cout << "Bear\n";
    
    return 0;
}
