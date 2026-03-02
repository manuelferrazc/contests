#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char * first  = "Ashish\n";
const char * second = "Utkarsh\n";

const char * solve() {
    ll d,k;
    cin >> d >> k;

    ll i=0;
    while(i*i*2<=d*d) i+=k;
    i-=k;

    if(i*i+(i+k)*(i+k)<=d*d) return first;
    else return second;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
