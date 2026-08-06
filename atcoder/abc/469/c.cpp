#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
	int n;
	string s;
	cin >> n >> s;

	int l = 0;
	int h = 0;
	//if(s[0]=='o') h++;
	for(int i=0;i<n;i++) {
		if(l<n and s[l]=='o') h++; 
		l = min(l+1,n);
		
		while(l<n and h) {
			if(s[l]=='x') h--;
			l++;
		}

		cout << l << '\n';
	}

    return 0;
}
