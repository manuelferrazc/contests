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

    vector<pair<int,int>> v(n);
    for(auto &i:v) cin >> i.ff >> i.ss;

    int qtd = 0;
    int t=0;
    for(auto i:v) {
        qtd = max(0,qtd-(i.ff-t));
        t=i.ff;
        qtd+=i.ss;
    }
    cout << qtd << '\n';

    return 0;
}
