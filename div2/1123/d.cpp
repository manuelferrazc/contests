#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void no() {
	cout << "NO\n";
}

void solve() {
	int n;
	cin >> n;

	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];

	map<int,int> cnt;
	for(int i=0;i<n;i++) {
		cnt[v[i]]++;
		if(cnt[v[i]]==3) return no();
	}

	{
	auto [mx,q] = *cnt.rbegin();
	if(q>1) return no();
	}

	multiset<int> pa,im;
	for(int i=0;i<n;i+=2) {
		if(n%2==1 and im.count(v[i])) return no();
		im.insert(v[i]);
	}
	for(int i=1;i<n;i+=2) {
		if((n%2==1) and pa.count(v[i])) return no();
		pa.insert(v[i]);
	}

	int st = 1; // comeca em posicao impar
	int en = n%2; // depende de n
	// 1 -> impar

	int tr=0,tl=0;

	while(pa.size() and im.size()) {
		if(st==1 and en==1) { // ambos pedem um impar
			auto it = im.begin();
			int e = *it;
			if(tl<=tr) { // bota na esq
				if(tl>=e) return no();
				tl = e;
				st = 1 - st;
			} else {
				if(tr>=e) return no();
				tr = e;
				en = 1-en;
			}
			im.erase(it);
		} else if(st==0 and en==0) { // par
			auto it = pa.begin();
			int e = *it;
			if(tl<=tr) {
				if(tl>=e) return no();
				tl = e;
				st = 1-st;
			} else {
				if(tr>=e) return no();
				tr = e;
				en = 1-en;
			}
			pa.erase(pa.begin());
		} else {
			int mi = *im.begin();
			int mp = *pa.begin();

			if(mi<mp) {
				if(st==1) {
					if(tl>=mi) return no();
					tl = mi;
					st = 0;
				} else {
					if(tr>=mi) return no();
					tr = mi;
					en = 0;
				}

				im.erase(im.begin());
			} else { // vou botar na q pede par
				if(st==0) {
					if(tl>=mp) return no();
					tl = mp;
					st = 1;
				} else {
					if(tr>=mp) return no();
					tr = mp;
					en = 1;
				}
				pa.erase(pa.begin());
			}
		}
	}

	cout << "YES\n";
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
