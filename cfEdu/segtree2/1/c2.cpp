#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m,op,a,b,c;
    cin >> n >> m;

    vector<int> v(n,0);
    while(m--) {
        cin >> op >> a;
        if(op==1) {
            cin >> b >> c;
            for(int i=a;i<b;i++) v[i] = c;
        } else cout << v[a] << '\n';
    }
    return 0;
}