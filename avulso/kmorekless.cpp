#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

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

map<int,vector<mint>> m;

typedef unsigned long long ull;

vector<mint> calc(vector<mint> p) {
    if(p.size()==1ULL) return p;

    int i=p.size()-1;

    for(int j=0;(i>>j);j++) {
        i>>=j;
        i<<=j;
    }
    
    vector<mint> a(i), b(p.size()-i);
    for(ull j=0;j<i;j++) a[j] = p[j];
    for(ull j=i;j<p.size();j++) b[j-i] = p[j];

    auto v1 = calc(a), v2 = calc(b);
    v2 = convolution(v2,m.at(i));

    for(ull j=0;j<v1.size();j++) v2[j]+=v1[j];
    return v2;
}

void print(vector<mint> &v) {
    for(auto &i:v) {
        i = i+998244353;
        cout << i << ' ';
    }
    cout << '\n';
}

int main() { _
    int n,k;
    cin >> n >> k;
    
    vector<mint> t(n+1),p(n+1);
    for(mint &i:t) cin >> i;
    for(mint &i:p) cin >> i;

    m[1] = vector<mint>(2);
    m[1][0] = (998244353+k)%998244353;
    m[1][1] = 1;
    for(int i=2;i<=n;i<<=1) m[i] = convolution(m[i/2],m[i/2]);
    t = calc(t);

    m.clear();

    m[1] = vector<mint>(2);
    m[1][0] = (998244353-k)%998244353;
    m[1][1] = 1;
    for(ll i=2;i<=n;i<<=1) m[i] = convolution(m[i/2],m[i/2]);
    p = calc(p);


    // print(t);
    // print(p);
    for(ull i=0;i<p.size();i++) {
        p[i]+=t[i];
        cout << p[i] << ' ';
    }
    
    cout << '\n';
    return 0;
}
