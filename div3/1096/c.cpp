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
    stack<int> t,d,s,none;

    while(n--) {
        int x;
        cin >> x;
        if(x%6==0) s.push(x);
        else if(x%2==0) d.push(x);
        else if(x%3==0) t.push(x);
        else none.push(x);
    }

    while(d.size()) {
        cout << d.top() << ' ';
        d.pop();
    }

    while(none.size()) {
        cout << none.top() << ' ';
        none.pop();
    }

    while(t.size()) {
        cout << t.top() << ' ';
        t.pop();
    }

    while(s.size()) {
        cout << s.top() << ' ';
        s.pop();
    }

    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
