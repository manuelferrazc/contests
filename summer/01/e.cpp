#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n;
    cin >> n;

    while(n) {
        stack<int> s;
        int nx = 1;

        for(int i=0;i<n;i++) {
            int x;
            cin >> x;

            if(x==nx) {
                nx++;
                while(s.size() and s.top()==nx) {
                    s.pop();
                    nx++;
                }
            } else s.push(x);
        }

        if(nx==n+1) cout << "yes\n";
        else cout << "no\n";
        
        cin >> n;
    }

    return 0;
}
