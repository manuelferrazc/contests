#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int d[100'000];
int s[100'000];

vector<int> adj[100'000];

int main() { _
    int n;
    cin >> n;

    for(int i=1;i<n;i++) {
        int p;
        cin >> p;
        p--;
        adj[p].push_back(i);
    }

    


    return 0;
}
