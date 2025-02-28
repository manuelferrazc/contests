#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

struct P {
	ll t,z,y;
};

ll conta(ll t, ll z, ll y, ll m) {
	ll r=(m/(z*t+y))*z;
	m = m%(z*t+y);

	m = min(m,t*z);
	r+=m/t;

	return r;
}

ll total(vector<P> &v, ll m) {
	ll ret = 0;
	for(auto i:v) ret+=conta(i.t,i.z,i.y,m);
	return ret;
}

ll bb(vector<P> &v, ll a, ll b, ll quero) {
	if(a==b) return total(v,a)>=quero? a:a+1;

	ll m=(a+b)/2LL	;

	if(total(v,m)>=quero) return bb(v,a,m,quero);
	else return bb(v,m+1,b,quero);
}

int main() { _
	ll m,n;
	cin >> m >> n;

	vector<P> v(n);
	for(ll i=0;i<n;i++) cin >> v[i].t >> v[i].z >> v[i].y;

	ll t = bb(v,0,2000*15000,m);
	cout << t << '\n';
	ll i;
	for(i=0;i<n;i++) {
		auto act = conta(v[i].t,v[i].z,v[i].y,t);
		cout << min(act,m) << ' ';
		m-=act;
		if(m<=0LL) break;
	}
	for(i++;i<n;i++) cout << "0 ";
	cout << '\n';
    return 0;
}
