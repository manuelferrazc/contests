#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
typedef long long ll;
#define pref first
#define sum second
#define MAX 30000

pair<int,int> pr(int a, int b) {
	pair<int,int> r;
	r.first = a;
	r.second = b;
	return r;
}

pair<int,int>  st[4*MAX];

pair<int,int> build(int pos, int l, int r, int *v) {
	if(l==r) return st[pos] = pr(v[l],v[l]);

	int m = (l+r)>>1,ls=2*pos+1;
	auto [p1,s1] = build(ls,l,m,v);
	auto [p2,s2] = build(ls+1,m+1,r,v);

	st[pos].pref = min(p1,s1+p2);
	st[pos].sum = s1+s2;

	return st[pos];
}

pair<int,int> get(int pos, int l, int r, int lq, int rq) {
	if(rq<l or r<lq) return {INT_MAX,0};
	if(lq<=l and r<=rq) return st[pos];

	int m = (l+r)>>1,ls=2*pos+1;
	auto [p1,s1] = get(ls,l,m,lq,rq);
	auto [p2,s2] = get(ls+1,m+1,r,lq,rq);

	return pr(min(p1,s1+p2),s1+s2);
}

pair<int,int> change(int pos, int l, int r, int i) {
	if(i<l or r<i) return st[pos];
	if(l==r) {
		st[pos].sum*=(-1);
		st[pos].pref = st[pos].sum;
		return st[pos];
	}

	int m = (l+r)>>1,ls=2*pos+1;
	auto [p1,s1] = change(ls,l,m,i);
	auto [p2,s2] = change(ls+1,m+1,r,i);

	return st[pos] = pr(min(p1,s1+p2),s1+s2);

}

void solve() {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int v[n];
    if(s[0]=='(') v[0] = 1;
    else v[0] = -1;
    for(int i=1;i<n;i++) {
        if(s[i]=='(') v[i] = 1;
        else v[i] = -1;
    }

	build(0,0,n-1,v);

    int q;
    cin >> q;

    while(q--) {
        int x;
        cin >> x;

        if(x==0) {
            if(get(0,0,n-1,0,n-1)==pr(0,0)) cout << "YES\n";
            else cout << "NO\n";
        } else {
            x--;
			change(0,0,n-1,x);
            if(s[x]=='(') s[x] = ')';
            else s[x] = '(';
        }
    }
}

int main() { _
    for(int i=0;i<10;i++) {
        cout << "Test " << i+1 << ":\n";
        solve();
    }

	return 0;
}