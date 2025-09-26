#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 1'000'000
const ll mod = 998'244'353;



int main() { _
    vector<int> fat(MAX+1,1);
    vector<int> primes_fat(MAX+1,1);

    for(int i=2;i<=MAX;i++) {
        if(fat[i]!=1) continue;
        fat[i] = i;
        primes_fat[i] = i;
        for(int j=i+i;j<MAX;j+=i) {
            fat[j] *= i;
            primes_fat[j] = i;
        }
    }

    int n;
    cin >> n;

    vector<int> dp(MAX+1,0);
    int x;
    cin >> x;
    x = fat[x];

    dp[x] = 1;
    for(int i=1;i<n;i++) {
        cin >> x;
        x = fat[x];

        // vector<int> 
    }

    cout << dp[x] << '\n';

    return 0;
}
