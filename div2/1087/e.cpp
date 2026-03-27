#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll get_z(string s) {
	int n = s.size();
	vector<int> z(n, 0);

    ll ans = 1;
    stack<int> st;
    st.push(0);

	int l = 0, r = 0;
	for (int i = 1; i < n; i++) {
		if (i <= r) z[i] = min(r - i + 1, z[i - l]);
		while (i + z[i] < n and s[z[i]] == s[i + z[i]]) z[i]++;
		if (i + z[i] - 1 > r) l = i, r = i + z[i] - 1;

        st.push(i);
        while(st.top()>0) {
            if(z[st.top()]<i-st.top()+1) st.pop();
            else break;
        }

        ans+=st.size();
	}

	return ans;
}

void solve() {
    int n,q;
    cin >> n >> q;

    string s;
    cin >> s;

    while(q--) {
        int l,r;
        cin >> l >> r;

        cout << get_z(s.substr(l-1,r-l+1)) << '\n';
    }
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
