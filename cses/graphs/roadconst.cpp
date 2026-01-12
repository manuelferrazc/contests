#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int p[100'000];
int s[100'000];

int get(int a) {
	return p[a] = (p[a]==a ? a : get(p[a]));
}

int comp;

int unir(int a, int b) {
	a = get(a);
	b = get(b);

	if(a==b) return s[a];

	if(s[a]<s[b]) swap(a,b);
	comp--;

	s[a]+=s[b];
	p[b] = a;

	return s[a];
}

int main() { _
	int n,m;
	cin >> n >> m;

	for(int i=0;i<n;i++) p[i] = i;
	for(int i=0;i<n;i++) s[i] = 1;

	comp = n;
	int mx = 1;

	while(m--) {
		int a,b;
		cin >> a >> b;
		a--;
		b--;

		mx = max(mx,unir(a,b));

		cout << comp << ' ' << mx << '\n';
	}

	return 0;
}
