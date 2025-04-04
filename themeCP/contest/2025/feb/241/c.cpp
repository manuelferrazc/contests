#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int mult(int n) {
    int r=0;
    for(;n%32768;n<<=1) r++;
    return r;
}

int count(int x) {
    int r=INT_MAX;

    for(int i=0;i<15;i++) 
        r=min(r,i+mult(x+i));;

    return r;
}

int main() { _
    int n,x;
    cin >> n;

    for(int i=0;i<n;i++) {
        cin >> x;
        cout << count(x) << ' ';
    }
    cout << '\n';

    return 0;
}
