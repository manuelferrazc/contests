#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main(int argc, char**argv) { _
    srand(atoi(argv[1]));
    
	int n = 1+rand()%8;
	int k = n*(n+1)/2;
	cout << "1\n" << n << ' ' << k << '\n';

	for(int i=1;i<=n;i++) for(int j=i;j<=n;j++) {
		int o = 1+rand()%2;
		cout << o << ' ' << i << ' ' << j << '\n';
	}

    return 0;
}
