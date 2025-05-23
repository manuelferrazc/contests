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

typedef mod_int<(int)1e9+7> mint;

template<typename T> tuple<T, T, T> ext_gcd(T a, T b) {
    if (!a) return {b, 0, 1};
    auto [g, x, y] = ext_gcd(b%a, a);
    return {g, y - b/a*x, x};
}

template<typename T = ll> struct crt {
	T a, m;

	crt() : a(0), m(1) {}
	crt(T a_, T m_) : a(a_), m(m_) {}
	crt operator * (crt C) {
		auto [g, x, y] = ext_gcd(m, C.m);
		if ((a - C.a) % g) a = -1;
		if (a == -1 or C.a == -1) return crt(-1, 0);
		T lcm = m/g*C.m;
		T ans = a + (x*(C.a-a)/g % (C.m/g))*m;
		return crt((ans % lcm + lcm) % lcm, lcm);
	}
};

// FFT
//
// Chamar convolution com vector<complex<double>> para FFT
// Precisa do mint para NTT
//
// O(n log(n))

// Para FFT
void get_roots(bool f, int n, vector<complex<double>>& roots) {
	const static double PI = acosl(-1);
	for (int i = 0; i < n/2; i++) {
		double alpha = i*((2*PI)/n);
		if (f) alpha = -alpha;
		roots[i] = {cos(alpha), sin(alpha)};
	}
}

// Para NTT
template<int p>
void get_roots(bool f, int n, vector<mod_int<p>>& roots) {
	mod_int<p> r;
	int ord;
	if (p == 998244353) {
		r = 102292;
		ord = (1 << 23);
	} else if (p == 754974721) {
		r = 739831874;
		ord = (1 << 24);
	} else if (p == 167772161) {
		r = 243;
		ord = (1 << 25);
	} else assert(false);

	if (f) r = r^(p - 1 -ord/n);
	else r = r^(ord/n);
	roots[0] = 1;
	for (int i = 1; i < n/2; i++) roots[i] = roots[i-1]*r;
}

template<typename T> void fft(vector<T>& a, bool f, int N, vector<int>& rev) {
	for (int i = 0; i < N; i++) if (i < rev[i]) swap(a[i], a[rev[i]]);
	int l, r, m;
	vector<T> roots(N);
	for (int n = 2; n <= N; n *= 2) {
		get_roots(f, n, roots);
		for (int pos = 0; pos < N; pos += n) {
			l = pos + 0, r = pos + n/2, m = 0;
			while (m < n/2) {
				auto t = roots[m] * a[r];
				a[r] = a[l] - t;
				a[l] = a[l] + t;
				l++, r++, m++;
			}
		}
	}
	if (f) {
		auto invN = T(1) / T(N);
		for (int i = 0; i < N; i++) a[i] = a[i] * invN;
	}
}

template<typename T> vector<T> convolution(vector<T>& a, vector<T>& b) {
	vector<T> l(a.begin(), a.end()), r(b.begin(), b.end());
	int N = l.size()+r.size()-1;
	int n = 1, log_n = 0;
	while (n <= N) n *= 2, log_n++;
	vector<int> rev(n);
	for (int i = 0; i < n; i++) {
		rev[i] = 0;
		for (int j = 0; j < log_n; j++) if (i>>j&1)
			rev[i] |= 1 << (log_n-1-j);
	}
	assert(N <= n);
	l.resize(n);
	r.resize(n);
	fft(l, false, n, rev);
	fft(r, false, n, rev);
	for (int i = 0; i < n; i++) l[i] *= r[i];
	fft(l, true, n, rev);
	l.resize(N);
	return l;
}

// NTT
template<int p, typename T> vector<mod_int<p>> ntt(vector<T>& a, vector<T>& b) {
	vector<mod_int<p>> A(a.begin(), a.end()), B(b.begin(), b.end());
	return convolution(A, B);
}

// Convolucao de inteiro
//
// Precisa do CRT
//
// Tabela de valores:
// [0,1]       - <int, 1>
// [-1e5, 1e5] - <ll, 2>
// [-1e9, 1e9] - <__int128, 3>
template<typename T, int mods>
vector<T> int_convolution(vector<int>& a, vector<int>& b) {
	static const int M1 = 998244353, M2 = 754974721, M3 = 167772161;

	auto c1 = ntt<M1>(a, b);
	auto c2 = (mods >= 2 ? ntt<M2>(a, b) : vector<mod_int<M2>>());
	auto c3 = (mods >= 3 ? ntt<M3>(a, b) : vector<mod_int<M3>>());

	vector<T> ans;
	for (int i = 0; i < c1.size(); i++) {
		crt<T> at(c1[i].v, M1);
		if (mods >= 2) at = at * crt<T>(c2[i].v, M2);
		if (mods >= 3) at = at * crt<T>(c3[i].v, M3);
		ans.push_back(at.a);
		if (at.a > at.m/2) ans.back() -= at.m;
	}
	return ans;
}

void solve() {
    int n;
    cin >> n;
    vector<int> v1(n+1),v2(n+1);
    for(int &i:v1) cin >> i;
    for(int &i:v2) cin >> i;

    auto x = int_convolution<ll,2>(v1,v2);

    for(auto i:x) cout << i << ' ';
    cout << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
