#include <bits/stdc++.h>

#pragma GCC optimize("Ofast")
// Auto explicativo
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

typedef pair<priority_queue<int,vector<int>,greater<int>>,priority_queue<int>> ppp;

struct pt { // ponto
	ll x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
};

struct line { // reta
	pt p, q;
	line() {}
	line(pt p_, pt q_) : p(p_), q(q_) {}
};

int compress(vector<line> &v) {
	vector<ll> s2;
	for(int i=0;i<(int)v.size();i++) {
		s2.push_back(v[i].p.x);
		s2.push_back(v[i].p.y);
		s2.push_back(v[i].q.x);
		s2.push_back(v[i].q.y);
	}

	sort(s2.begin(),s2.end());
	vector<ll> s(1,s2[0]);
	for(ll i:s2) if(i!=s.back()) s.push_back(i);

	pair<ll,int> m[s.size()];
	int val = 0;
	for(auto i:s) {
		m[val] = pair(i,val);
		val++;
	}

	for(int i=0;i<(int)v.size();i++) {
		auto it = lower_bound(m,m+val,pair(v[i].p.x,-1));
		v[i].p.x = it->ss;
		it = lower_bound(m,m+val,pair(v[i].p.y,-1));
		v[i].p.y = it->ss;
		it = lower_bound(m,m+val,pair(v[i].q.x,-1));
		v[i].q.x = it->ss;
		it = lower_bound(m,m+val,pair(v[i].q.y,-1));
		v[i].q.y = it->ss;
	}

	return val;
}

bool vert(line &l) {
	return l.q.x==l.p.x;
}

array<int,4> combine(array<int,4> const &a1, array<int,4> const &a2) {
	vector<int> v;
	for(int i=0;i<4;i++) if(a1[i]!=-1) v.push_back(a1[i]);
	for(int i=0;i<4;i++) if(a2[i]!=-1) v.push_back(a2[i]);

	if(v.size()==0) return {-1,-1,-1,-1};
	sort(v.begin(),v.end());
	if(v.size()==1) return {v[0],-1,v[0],-1};
	else return {v[0],v[1],*v.rbegin(),*next(v.rbegin())};
}

int fast[100'001];

void add(array<int,4> *st, ppp *s, int pos, int l, int r, int x, int i) {
	if(l==r) {
		s[l].ff.push(i);
		s[l].ss.push(i);

		st[pos][0] = s[l].ff.top();
		st[pos][1] = st[pos][2] = -1;
		st[pos][2] = s[l].ss.top();

		if(s[l].ff.size()>1) {
			int m1 = s[l].ff.top(),m2 = s[l].ss.top();
			s[l].ff.pop();
			s[l].ss.pop();

			st[pos][1] = s[l].ff.top();
			st[pos][3] = s[l].ss.top();

			s[l].ff.push(m1);
			s[l].ss.push(m2);
		}
		return;
	}

	int ls = 2*pos+1, m = (l+r)>>1;
	if(x<=m) add(st,s,ls,l,m,x,i);
	else add(st,s,ls+1,m+1,r,x,i);

	st[pos] = combine(st[ls],st[ls+1]);
}

vector<bool> lz;

void rem(array<int,4> *st, ppp *s, int pos, int l, int r, int x) {
	if(l==r) {
		// s[l].erase(i);
		int ma1=-1,ma2=-1,mi1=-1,mi2=-1;
		
		while(s[l].ff.size() and lz[s[l].ff.top()]) s[l].ff.pop();
		if(s[l].ff.size()) {
			mi1 = s[l].ff.top();
			s[l].ff.pop();

			while(s[l].ff.size() and lz[s[l].ff.top()]) s[l].ff.pop();
			if(s[l].ff.size()) mi2 = s[l].ff.top();

			s[l].ff.push(mi1);
		}

		while(s[l].ss.size() and lz[s[l].ss.top()]) s[l].ss.pop();
		if(s[l].ss.size()) {
			ma1 = s[l].ss.top();
			s[l].ss.pop();

			while(s[l].ss.size() and lz[s[l].ss.top()]) s[l].ss.pop();
			if(s[l].ss.size()) ma2 = s[l].ss.top();

			s[l].ss.push(ma1);
		}

		st[pos] = {mi1,mi2,ma1,ma2};
		return;
	}

	int ls = 2*pos+1, m = (l+r)>>1;
	if(x<=m) rem(st,s,ls,l,m,x);
	else rem(st,s,ls+1,m+1,r,x);

	st[pos] = combine(st[ls],st[ls+1]);
}

void Set(int pos, int l, int r) {
	if(l==r) fast[l] = pos;
	else {
		int m = (l+r)>>1,ls =2*pos+1;
		Set(ls,l,m);
		Set(ls+1,m+1,r);
	}
}

array<int,4> get(array<int,4> *st, int pos, int l, int r, int lq, int rq) {
	if(rq<l or r<lq) return {-1,-1,-1,-1};
	if(lq<=l and r<=rq) return st[pos];

	int ls = 2*pos+1, m = (l+r)>>1;
	array<int,4> a1 = get(st,ls,l,m,lq,rq),
				 a2 = get(st,ls+1,m+1,r,lq,rq);

	return combine(a1,a2);
}


int find_err(vector<line> v) {
	int r = v.size();

	int mx = compress(v);
	Set(0,0,mx-1);

	vector<array<int,3>> ev;
	for(int i=0;i<r;i++) {
		if(vert(v[i])) ev.push_back({(int)v[i].p.x,2,i});
		else {
			ev.push_back({(int)min(v[i].p.x,v[i].q.x),1,i});
			ev.push_back({(int)max(v[i].p.x,v[i].q.x),3,i});
		}
	}
	
	sort(ev.begin(),ev.end());
	
	ppp *leaves = new ppp[mx];

	array<int,4> *st = new array<int,4>[4*mx];
	for(int i=0;i<4*mx;i++) st[i][0] = st[i][1] = st[i][2] = st[i][3] = -1;

	for(ull i=0;i<ev.size();i++) {
		auto [val,tp,id] = ev[i];

		if(tp==1) {
			array<int,4> ret = st[fast[v[id].p.y]];

			if(ret[0]!=-1 and abs(id-ret[0])>1) r = min(r,max(id,ret[0]));
			if(ret[1]!=-1 and abs(id-ret[1])>1) r = min(r,max(id,ret[1]));
			if(ret[2]!=-1 and abs(id-ret[2])>1) r = min(r,max(id,ret[2]));
			if(ret[3]!=-1 and abs(id-ret[3])>1) r = min(r,max(id,ret[3]));

			add(st,leaves,0,0,mx-1,v[id].p.y,id);
		} else if(tp==2) {
			int y1 = v[id].p.y, y2 = v[id].q.y;
			if(y1>y2) swap(y1,y2);

			array<int,4> ret = get(st,0,0,mx-1,y1,y2);

			if(ret[0]!=-1 and abs(id-ret[0])>1) r = min(r,max(id,ret[0]));
			if(ret[1]!=-1 and abs(id-ret[1])>1) r = min(r,max(id,ret[1]));
			if(ret[2]!=-1 and abs(id-ret[2])>1) r = min(r,max(id,ret[2]));
			if(ret[3]!=-1 and abs(id-ret[3])>1) r = min(r,max(id,ret[3]));
		} else {
			lz[id] = true;
			rem(st,leaves,0,0,mx-1,v[id].p.y);

			array<int,4> ret = st[fast[v[id].p.y]];

			if(ret[0]!=-1 and abs(id-ret[0])>1) r = min(r,max(id,ret[0]));
			if(ret[1]!=-1 and abs(id-ret[1])>1) r = min(r,max(id,ret[1]));
			if(ret[2]!=-1 and abs(id-ret[2])>1) r = min(r,max(id,ret[2]));
			if(ret[3]!=-1 and abs(id-ret[3])>1) r = min(r,max(id,ret[3]));
		}
	}

	ev.clear();
	for(ull i=0;i<v.size();i++) {
		if(vert(v[i])) {
			ev.push_back({(int)min(v[i].p.y,v[i].q.y),1,(int)i});
			ev.push_back({(int)max(v[i].p.y,v[i].q.y),2,(int)i});
		}
	}

	sort(ev.begin(),ev.end());

	for(ull i=0;i<ev.size();i++) {
		auto [val,tp,id] = ev[i];

		if(tp==1) {
			array<int,4> ret = st[fast[v[id].p.x]];

			if(ret[0]!=-1 and abs(id-ret[0])>1) r = min(r,max(id,ret[0]));
			if(ret[1]!=-1 and abs(id-ret[1])>1) r = min(r,max(id,ret[1]));
			if(ret[2]!=-1 and abs(id-ret[2])>1) r = min(r,max(id,ret[2]));
			if(ret[3]!=-1 and abs(id-ret[3])>1) r = min(r,max(id,ret[3]));

			add(st,leaves,0,0,mx-1,v[id].p.x,id);
		} else {
			lz[id] = true;
			rem(st,leaves,0,0,mx-1,v[id].p.x);

			array<int,4> ret = st[fast[v[id].p.x]];

			if(ret[0]!=-1 and abs(id-ret[0])>1) r = min(r,max(id,ret[0]));
			if(ret[1]!=-1 and abs(id-ret[1])>1) r = min(r,max(id,ret[1]));
			if(ret[2]!=-1 and abs(id-ret[2])>1) r = min(r,max(id,ret[2]));
			if(ret[3]!=-1 and abs(id-ret[3])>1) r = min(r,max(id,ret[3]));
		}
	}

	delete[] leaves;
	delete[] st;
	return r;
}

int main() { _
	int n;
	cin >> n;
	lz = vector<bool>(n,false);

	ll s=0;
	pair<char,int> v[n];

	for(int i=0;i<n;i++) {
		string st;
		cin >> st >> v[i].ss;
		v[i].ff = st[0];
		s+=v[i].ss;
		bool err = false;
		if(i) {
			if(v[i].ff=='U' and v[i-1].ff=='D') err = true;
			else if(v[i].ff=='D' and v[i-1].ff=='U') err = true;
			else if(v[i].ff=='L' and v[i-1].ff=='R') err = true;
			else if(v[i].ff=='R' and v[i-1].ff=='L') err = true;
			if(err) {
				n = i;
				s-=v[i].ss;
				break;
			}			
		}
	}

	vector<line> v2;
	{pt bef;
	for(int i=0;i<n;i++) {
		pt act = bef;
		if(v[i].ff=='U') act.y+=v[i].ss;
		else if(v[i].ff=='D') act.y-=v[i].ss;
		else if(v[i].ff=='R') act.x+=v[i].ss;
		else act.x-=v[i].ss;
		v2.push_back(line(bef,act));
		bef = act;
	}}

	int steps=find_err(v2);
	pt last = v2[steps-1].q;

	if(steps==n) cout << s << '\n';
	else {
		s = 0;
		for(int i=0;i<steps;i++) s+=v[i].ss;
		bool vert = v[steps].ff=='U' or v[steps].ff=='D';
		
		line err(last,last);
		
		if(v[steps].ff=='U') err.q.y+=v[steps].ss;
		else if(v[steps].ff=='D') err.q.y-=v[steps].ss;
		else if(v[steps].ff=='R') err.q.x+=v[steps].ss;
		else err.q.x-=v[steps].ss;
		
		pt last2 = err.q;

		if(err.p.x>err.q.x or err.p.y>err.q.y) swap(err.p,err.q);
		
		pt act;

		ll d = 1e6;

		for(int i=0;i<steps-1;i++) {
			bool vert2 = false;
			pt bef = act;

			if(v[i].ff=='U') {
				act.y+=v[i].ss;
				vert2 = true;
			}
			else if(v[i].ff=='D') {
				act.y-=v[i].ss;
				vert2 = true;
			}
			else if(v[i].ff=='R') act.x+=v[i].ss;
			else act.x-=v[i].ss;

			line l(act,bef);
			if(l.p.x>l.q.x or l.p.y>l.q.y) swap(l.p,l.q);

			if(vert == vert2) {
				ll a1,a2,b1,b2;

				if(err.q.x==err.p.x) {
					if(err.q.x!=l.p.x) continue;
					a1 = l.p.y,a2 = l.q.y;
					b1 = last.y, b2 = last2.y;
				} else {
					if(err.q.y!=l.p.y) continue;
					a1 = l.p.x, a2 = l.q.x;
					b1 = last.x, b2 =last2.x;
				}

				if(a1<=b1 and b1<=a2) {
					d = 0;
					break;
				} else if(a1<=b2 and b2<=a2) {
					if(b1<a1) d = min(d,a1-b1);
					else d = min(d,a2-b1);
				} else if(min(b1,b2)<=a1 and max(b1,b2)>=a2) {
					d = min(d,min(abs(a1-b1),abs(a2-b1)));
				}
			} else if(vert) {
				if(l.p.x<=last.x and last.x<=l.q.x and err.p.y<=l.p.y and l.p.y<=err.q.y) {
					d = min(d,abs(last.y-l.p.y));
				}
			} else if(vert2) {
				if(err.p.x<=l.p.x and l.p.x<=err.q.x and l.p.y<=err.p.y and err.p.y<=l.q.y) {
					d = min(d,abs(last.x-l.p.x));
				}
			}
		}
		
		
		cout << s+d << '\n';
	}

	return 0;
}
