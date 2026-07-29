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

	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	int ans=0;

	for(int i=1;i<n-1;i++) 
		if(v[i]>max(v[i-1],v[i+1])) ans++;

	cout << ans << '\n';

    return 0;
}
