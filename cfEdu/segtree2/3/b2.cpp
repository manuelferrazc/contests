#include <bits/stdc++.h>

using namespace std;

int main() {
    int n,m,op,a,b;
    cin >> n >> m;

    vector<int> v(n,0);

    while(m--) {
        cin >> op >> a;
        if(op==1) {
            cin >> b;
            for(;a<b;a++) {
                v[a] = 1-v[a];
            }
        } else {
            for(int i=0;i<n;i++) {
                if(v[i]) a--;
                if(a==-1) {
                    cout << i << '\n';
                    break;
                }
            }
        } 
    }

    return 0;
}
