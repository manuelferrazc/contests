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
    int n;
    cin >> n;
    set<int> m;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(a) m.insert(a);
    }

    cout << m.size() << '\n';
    return 0;
}
