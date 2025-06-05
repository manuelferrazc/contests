#include <bits/stdc++.h>
using namespace std;
#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
typedef long long ll;
#define ff first
#define ss second
const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;
#define sz(x) (int)x.size()

// Aritmetica Modular
//
// O mod tem q ser primo

template<int p> struct mod_int {
	ll expo(ll b, ll e) {
		ll ret = 1;
		while (e) {
			if (e % 2) ret = ret * b % p;
			e /= 2, b = b * b % p;
		}
		return ret;
	}
	ll inv(ll b) { return expo(b, p-2); }

	using m = mod_int;
	int v;
	mod_int() : v(0) {}
	mod_int(ll v_) {
		if (v_ >= p or v_ <= -p) v_ %= p;
		if (v_ < 0) v_ += p;
		v = v_;
	}
	m& operator +=(const m& a) {
		v += a.v;
		if (v >= p) v -= p;
		return *this;
	}
	m& operator -=(const m& a) {
		v -= a.v;
		if (v < 0) v += p;
		return *this;
	}
	m& operator *=(const m& a) {
		v = v * ll(a.v) % p;
		return *this;
	}
	m& operator /=(const m& a) {
		v = v * inv(a.v) % p;
		return *this;
	}
	m operator -(){ return m(-v); }
	m& operator ^=(ll e) {
		if (e < 0) {
			v = inv(v);
			e = -e;
		}
		v = expo(v, e);
		// possivel otimizacao:
		// cuidado com 0^0
		// v = expo(v, e%(p-1)); 
		return *this;
	}
	bool operator ==(const m& a) { return v == a.v; }
	bool operator !=(const m& a) { return v != a.v; }

	friend istream& operator >>(istream& in, m& a) {
		ll val; in >> val;
		a = m(val);
		return in;
	}
	friend ostream& operator <<(ostream& out, m a) {
		return out << a.v;
	}
	friend m operator +(m a, m b) { return a += b; }
	friend m operator -(m a, m b) { return a -= b; }
	friend m operator *(m a, m b) { return a *= b; }
	friend m operator /(m a, m b) { return a /= b; }
	friend m operator ^(m a, ll e) { return a ^= e; }
};


// NTT
//
// Precisa do mint (primitivas de aritmetica modular)
//
// O(n log (n))

const int MOD = 998244353;
typedef mod_int<MOD> mint;

void ntt(vector<mint>& a, bool rev) {
	int n = a.size(); auto b = a;
	assert(!(n&(n-1)));
	mint g = 1; 
	while ((g^(MOD / 2)) == 1) g += 1;
	if (rev) g = 1 / g;

	for (int step = n / 2; step; step /= 2) {
		mint w = g^(MOD / (n / step)), wn = 1;
		for (int i = 0; i < n/2; i += step) {
			for (int j = 0; j < step; j++) {
				auto u = a[2 * i + j], v = wn * a[2 * i + j + step];
				b[i+j] = u + v; b[i + n/2 + j] = u - v;
			}
			wn = wn * w;
		}
		swap(a, b);
	}
	if (rev) {
		auto n1 = mint(1) / n;
		for (auto& x : a) x *= n1;
	}
}

vector<mint> convolution(const vector<mint>& a, const vector<mint>& b) {
	vector<mint> l(a.begin(), a.end()), r(b.begin(), b.end());
	int N = l.size()+r.size()-1, n = 1;
	while (n <= N) n *= 2;
	l.resize(n);
	r.resize(n);
	ntt(l, false);
	ntt(r, false);
	for (int i = 0; i < n; i++) l[i] *= r[i];
	ntt(l, true);
	l.resize(N);
	return l;
}

map<int,vector<mint>> pot;
vector<mint> fexp(int x) {
    int i=1;
    vector<mint> v;
    while(not (i&x)) i<<=1;
    v = pot[i];
    i<<=1;
    while(i<301) {
        if(i&x) v = convolution(v,pot[i]);
        i<<=1;
    }
    return v;
}

typedef unsigned long long ull;

vector<mint> calc(vector<mint> p) {
    if(p.size()==1) return p;

    int i=p.size()-1;

    for(int j=0;(i>>j);j++) {
        i>>=j;
        i<<=j;
    }

    
    vector<mint> a(p.size()-i), b(i);
    for(ull j=0;j<a.size();j++) a[j] = p[j];
    for(ull j=p.size()-i;j<p.size();j++) b[j-a.size()] = p[j];

    auto v1 = calc(a), v2 = calc(b);
    v2 = convolution(v2,fexp(a.size()));

    for(ull j=0;j<v1.size();j++) v2[j]=v2[j]+v1[j];
    return v2;
}

int main() { _
	int n1,n2;
	cin >> n1;
	vector<mint> p(n1+1);
	for(mint &i:p) cin >> i;
	cin >> n2;
	vector<mint> q(n2+1);
	for(mint &i:q) cin >> i;

    
    pot[1] = q;
    for(int i=2;i<301;i*=2) pot[i] = convolution(pot[i/2],pot[i/2]);
    
	vector<mint> ans = calc(p);


	// ans[0] = p[0];
	// for(int i=0;i<=n2;i++) ans[i] += p[1]*q[i];
	// auto qo = q;
	// for(int i=2;i<=n1;i++) {
	// 	q = convolution(qo,q);

	// 	for(int j=0;j<q.size();j++) {
	// 		ans[j] += (p[i]*q[j]);
	// 	}
	// }

	for(mint i:ans) cout << i << ' ';
	cout << '\n';
	exit(0);
}