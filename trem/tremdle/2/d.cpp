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
    vector<int> v(n);
    for(int &i:v) cin >> i;
    sort(v.begin(),v.end());

    if(v.front()==v.back()) cout << "Bob\n";
    else if(v.front()==v[(n>>1)-1]) {
        if(v.front()==v[n>>1]) cout << "Bob\n";
        else cout << "Alice\n";
    } else cout << "Alice\n";
    return 0;
}
