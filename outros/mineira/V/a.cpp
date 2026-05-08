#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { _
    int v[5];

    for(int i=0;i<5;i++) cin >> v[i];

    for(int i=1;i<5;i++) if(v[i-1]>=v[i]) {
        cout << "NAO\n";
        return 0;
    }

    cout << "SIM\n";

    return 0;
}