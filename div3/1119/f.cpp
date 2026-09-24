#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void solve() {
	int n;
	cin >> n;

	int v[n];
	for(int i=0;i<n;i++) cin >> v[i];
	string s;
	cin >> s;

	ll inv = 0;
	ll q1 = 0;
	for(int i=0;i<n;i++) {
		if(v[i]==0) inv+=q1;
		else q1++;
	}

	cout << inv;

	deque<pair<int,int>> q; // val, qtd
	for(int i=0;i<n;i++) {
		if(q.empty() or q.back().ff!=v[i]) q.push_back(pair(v[i],0));
		q.back().ss++;
	}

	if(q.front().ff==0) q.pop_front();
	if(q.size() and q.back().ff==1) q.pop_back();

	q1=0;
	ll q0=0;
	for(auto [val,qtd]:q) {
		if(val) q1+=qtd;
		else q0+=qtd;
	}

	for(char c:s) {
		if(q.size()) {
			if(c=='1') { // bubble
				inv-=q0;
				q1--;
				q.front().ss--;

				if(q.front().ss==0) {
					q.pop_front();
					q0-=q.front().ss;
					q.pop_front();
				}
			} else { // rev bubble
				inv -= q1;
				q0--;
				q.back().ss--;

				if(q.back().ss==0) {
					q.pop_back();
					q1-=q.back().ss;
					q.pop_back();
				}
			}
		}

		cout << ' ' << inv;
	}

	cout << '\n';
}

int main() { _
	int t;
	cin >> t;
	while(t--) solve();
	return 0;
}
