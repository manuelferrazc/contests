#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const int MAX = 100001;
bool prime[100001];

int count(int n) {
    int r=0;
    for(int i=2;i<=n;i++) {
        while(n%i==0) {
            r++;
            n/=i;
        }

        if(prime[n]) {
            r++;
            break;
        }
    }

    return r;
}

int main() { _
    prime[1] = false;
    for(int i=2;i<MAX;i++) prime[i] = true;
    for(int i=2;i<MAX;i++) {
        if(prime[i]==false) continue;
        for(int j=2*i;j<MAX;j+=i) prime[j] = false;
    }

    int n;
    cin >> n;

    int ans=0;
    while(n--) {
        int x;
        cin >> x;
        ans^=count(x);
    }

    if(ans) cout << "Anna\n";
    else cout << "Bruno\n";

    return 0;
}
