#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int ask(int i, int j) {
    println("? {} {}",i,j);
    int x;
    cin >> x;
    return x;
}

void ans(int x) {
    println("! {}",x);
}

void solve() {
    int n;
    cin >> n;

    for(int i=3;i<=2*n;i+=2) {
        if(ask(i,i+1)) return ans(i);
    }

    if(ask(1,3)) ans(1);
    else if(ask(1,4)) ans(1);
    else ans(2);
}

int main() {
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
