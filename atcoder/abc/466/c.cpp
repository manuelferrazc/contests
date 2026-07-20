#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool ask(int i, int j) {
	println("? {} {}",i,j);
	string s;
	cin >> s;
	return s[0]=='Y';
}

int main() {
	int n;
	cin >> n;

	int ans = 0;
	int i=1;
	for(int j=2;j<=n;j++) {
		while(i<j) {
			if(ask(i,j)) {
				ans += j-i;
				break;
			}

			i++;
		}
	}

	println("! {}",ans);

    return 0;
}
