#include <bits/stdc++.h>

#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> v,stv,dp;

#define MAX 200001
#define MAX2 18

namespace sparse {
	int m[MAX2][MAX], n;
	void build(int n2, vector<int> &v) {
		n = n2;
		for (int i = 0; i < n; i++) m[0][i] = v[i];
		for (int j = 1; (1<<j) <= n; j++) for (int i = 0; i+(1<<j) <= n; i++)
			m[j][i] = max(m[j-1][i], m[j-1][i+(1<<(j-1))]);
	}
	int query(int a, int b) {
		int j = __builtin_clz(1) - __builtin_clz(b-a+1);
		return max(m[j][a], m[j][b-(1<<j)+1]);
	}
}

int sett(int pos, int l, int r, int i, int v) {
    if(i<l or r<i) return dp[pos];
    if(l==r) return dp[pos] = v;
    int m = (l+r)>>1,ls = 2*pos+1;
    return dp[pos] = max(sett(ls,l,m,i,v),sett(ls+1,m+1,r,i,v));
}

int get(vector<int> &st, int pos, int l, int r, int lq, int rq) {
    if(r<lq or rq<l) return 0;
    if(lq<=l and r<=rq) return st[pos];
    int m = (l+r)>>1,ls = 2*pos+1;
    return max(get(st,ls,l,m,lq,rq),get(st,ls+1,m+1,r,lq,rq));
}

int n;

int const findleft(vector<int> &sp, int r, int x) {
    int l=0,ans=r;

    while(l<=r) {
        int m = (l+r)>>1;
        if(sparse::query(m,r)<x) {
            ans = m;
            r=m-1;
        } else l = m+1;
    }

    return ans;
}

int findright(vector<int> &sp, int l, int x) {
    int r=n-1,ans=l;

    while(l<=r) {
        int m = (l+r)>>1;
        if(sparse::query(l,m)<x) {
            ans = m;
            l=m+1;
        } else r=m-1;
    }

    return ans;
}

int main() { 
    cin >> n;
    dp.assign(n<<2,0);
    v.resize(n);
    for(int i=0;i<n;i++) cin >> v[i];
    sparse::build(n,v);
    // build(0,0,n-1);

    vector<pair<int,int>> aux(n);
    for(int i=0;i<n;i++) {
        aux[i].ff = v[i];
        aux[i].ss = i;
    }

    sort(aux.begin(),aux.end());
    for(auto [x, i]:aux) {
        int r=0;
        if(i and v[i-1]<v[i]) r = get(dp,0,0,n-1,findleft(stv,i-1,x),i-1);
        if(i!=n-1 and v[i]>v[i+1]) r = max(r,get(dp,0,0,n-1,i+1,findright(stv,i+1,x)));

        r++;
        sett(0,0,n-1,i,r);
    }

    cout << get(dp,0,0,n-1,0,n-1) << '\n';

    return 0;
}
