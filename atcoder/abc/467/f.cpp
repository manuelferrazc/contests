#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template <class T>
using ord_set = tree<T, null_type, less<T>, rb_tree_tag,
	tree_order_statistics_node_update>;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int)chrono::steady_clock::now().time_since_epoch().count());

template<typename T> struct treap {
	struct node {
		node *l, *r;
		int p, sz;
		T sub, lazy;
		T val;
		T a;
		node(T _a, T _b): l(nullptr), r(nullptr), p(rng()), sz(1), sub(_a+_b), lazy(0), val(_a+_b), a(_a) {}
		void prop() {
			if(lazy) {
				sub += lazy;
				val += lazy;
				a += lazy;
				if(l) l->lazy += lazy;
				if(r) r->lazy += lazy;
			}
		//cout << t.size() << ' ' << i-1 << '\n'; cout.flush();
			lazy = 0;
		}
		void update() {
			sz = 1;
			sub = val;
			if(l) l->prop(), sz += l->sz, sub = max(sub,l->sub);
			if(r) r->prop(), sz += r->sz, sub = max(sub,r->sub);
		}
	};

	node *root;
	treap() {root = nullptr;}
	~treap() {
		vector<node*> q = {root};
		while(q.size()) {
			node *x = q.back();
			q.pop_back();
			if(!x) continue;
			q.push_back(x->l);
			q.push_back(x->r);
			delete x;
		}
	}

	int size(node *x) {return x ? x->sz : 0;}
	int size() {return size(root);}

	void join(node *l, node *r, node *&i) {
		if(!l or !r) return void(i=l ? l : r);
		l->prop();
		r->prop();
		if(l->p > r->p) join(l->r, r, l->r), i = l;
		else join(l,r->l,r->l), i=r;
		i->update();
	}
	void split(node *i, node *& l, node *& r, int v, int key=0) {
		if(!i) return void(r=l=nullptr);
		i->prop();
		if(key+size(i->l)<v) split(i->r,i->r,r,v,key+size(i->l)+1), l=i;
		else split(i->l,l,i->l,v,key), r=i;
		i->update();
	}

	void push_back(T a, T b) {
		node *i = new node(a,b);
		join(root,i,root);
	}
	T query(int l, int r) {
		node *L, *M, *R;
		split(root,M,R,r+1), split(M,L,M,l);
		T ans = M->sub;
		join(L,M,M), join(M,R,root);
		return ans;
	}
	T query(int i) {
		//cout << "query " << i << '\n'; cout.flush();
		assert(i>=0 and i<size());
		node *L, *M, *R;
		split(root,M,R,i+1),split(M,L,M,i);
		T ans = M->a;
		join(L,M,M);
		join(M,R,root);
		return ans;
	}
	void update(int l, int r, T s) {
		assert(l<=r);
		node *L,*R,*M;
		split(root,M,R,r+1), split(M,L,M,l);
		M->lazy += s;
		join(L,M,M), join(M,R,root);
	}
	void erase(int i) {
		node *l, *m, *r;
		split(root,m,r,i+1), split(m,l,m,i);
		delete m;
		join(l,r,root);
	}
	void insert(T a, T b, int i) {
		node *l, *r;
		split(root,l,r,i);
		node *n = new node(a,b);
		join(l,n,n);
		join(n,r,root);
	}
};

int main() { _
	int n,q;
	cin >> n >> q;

	treap<ll> t;
	ord_set<pair<int,int>> s;
	int a[n+1];
	int b[n+1];
	for(int i=0;i<n;i++) cin >> a[i+1];
	for(int i=0;i<n;i++) cin >> b[i+1];
	for(int i=0;i<n;i++) s.insert(pair(-b[i+1],i+1));

	t.push_back(0,0);
	ll acc = 0;
	for(auto [bb,i]:s) {
		acc += a[i];
		t.push_back(acc,-bb);
	}
	t.push_back(0,0);
	//cout << "size = " << t.size() << '\n';

	//for(int i=1;i<=n;i++) cout << t.query(i) << ' ';
	//cout << "statt query\n";
	while(q--) {
		//cout << "\n\nq\n";
		int op,i,x;
		cin >> op >> i >> x;

		int torem = s.order_of_key(pair(-b[i],i))+1;
		//cout << torem << ' ' << t.size() << '\n';cout.flush();
		t.update(torem,n,-a[i]);
		t.erase(torem);
		//cout << "a intermed\n";
		//for(int i=1;i<n;i++) cout << t.query(i) << ' ';
		//cout << '\n';
		s.erase(pair(-b[i],i));
		assert(s.size()==n-1);

		if(op==1) a[i] = x;
		else b[i] = x;

		s.insert(pair(-b[i],i));
		int toinsert = s.order_of_key(pair(-b[i],i))+1;

		ll toadd = t.query(toinsert-1);
		t.insert(toadd,b[i],toinsert);
		
		//cout << "insert = " << toinsert << ", toadd = " << toadd << '\n';
		t.update(toinsert,n,a[i]);
		
		//cout << a[i] << ", valores de a: ";
		//for(int i=1;i<=n;i++) cout << t.query(i) << ' ';
		//cout << '\n';
		cout << t.query(1,n) << '\n';
	}

    return 0;
}
