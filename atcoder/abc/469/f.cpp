#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

#define MAX 1'000'001
#define MAXN 200'000

int p[MAXN];
int r[MAXN];

int get(int a) {
	return p[a] = (p[a]==a ? a : get(p[a]));
}

bool unir(int a, int b) {
	a = get(a);
	b = get(b);

	if(a==b) return false;
	if(r[b]>r[a]) swap(a,b);
	if(r[a]==r[b]) r[a]++;
	p[b] = a;
	return true;
}

int main() { _
	int n;
	cin >> n;
	iota(p,p+MAXN,0);

	vector<int> *oc = new vector<int>[MAX];
	for(int i=0;i<n;i++) {
		int x;
		cin >> x;

		for(int j=1;j*j<=x;j++) {
			if(x%j==0) {
				oc[j].push_back(i);
				if(j*j!=x) oc[x/j].push_back(i);
			}
		}
	}

	ll ans=0;
	for(int i = MAX-1;i;i--) {
		for(int j = 1;j<oc[i].size();j++)
			if(unir(oc[i][0],oc[i][j])) ans+=i;
	}

	cout << ans << '\n';
	delete[] oc;

    return 0;
}
