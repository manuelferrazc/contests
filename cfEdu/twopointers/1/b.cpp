#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,m;
    cin >> n >> m;
    vector<int> v(n);
    for(auto &i:v) cin >> i;

    int qtd=0,b;
    for(int i=0;i<m;i++) {
        cin >> b;
        while(qtd!=n and v[qtd]<b) qtd++;
        cout << qtd << ' ';
    }
    cout << '\n';

    return 0;
}
