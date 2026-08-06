#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;

#define MAX 100'001

ll qtd[MAX];
ll st[MAX*4];

void lim(ll &val) {
	if(val>40) val = 40;
}

void propag(int pos, int l, int r) {
	if(l!=r) {
		int ls = 2*pos+1;
		st[ls] *= st[pos];
		st[ls+1] *= st[pos];
		lim(st[ls]);
		lim(st[ls+1]);
		st[pos] = 1;
	}
	else {
		qtd[l]*=st[pos];
		lim(qtd[l]);
	}
	st[pos] = 1;
}

ll get(int pos, int l, int r, int k) {
	propag(pos,l,r);
	if(l==r) return qtd[l]*st[pos];

	int m = (l+r)/2;
	if(k<=m) return get(2*pos+1,l,m,k);
	else return get(2*pos+2,m+1,r,k);
}

void mul(int pos, int l, int r, int lq, int rq, int x) {
	propag(pos,l,r);
	if(rq<l or r<lq) return;
	if(lq<=l and r<=rq) {
		st[pos] *= x;
		//cout << "X ====== " << x << ' ' << st[pos] << '\n';
		lim(st[pos]);
		
		return;
	}

	int m = (l+r)/2;
	int ls = 2*pos+1;
	mul(ls,l,m,lq,rq,x);
	mul(ls+1,m+1,r,lq,rq,x);
}

int main() { 
	fill(qtd,qtd+MAX,0);
	fill(st,st+MAX*4,1);

	int q;
	cin >> q;
	int c[MAX];
	iota(c,c+MAX,0);
	for(int i=2;i<MAX;i++) {
		if(c[i]!=i) continue;
		for(int j=i+i;j<MAX;j+=i) c[j] = i;
	}
	//cout << "sla\n";
	while(q--) {
		int t,x;
		cin >> t >> x;
		int pqp = x;
	
		map<int,int> fat;
		while(x>1) {
			fat[c[x]]++;
			x/=c[x];
		}
		//cout << "test\n";
		if(t==1) {
			//cout << "case1\n";
			for(auto [p,e]:fat) {
				//cout << p << ' ' << e << '\n';
				get(0,0,MAX-1,p);
				qtd[p] += e;
				lim(qtd[p]);
			}
		} else if(t==2)  mul(0,0,MAX-1,1,MAX-1,pqp);
		else {
			bool ok = true;

			for(auto [p,e]:fat) {
				ll qt = get(0,0,MAX-1,p);
				if(qt<e) {
					ok = false;
					break;
				}
			}
			if(ok) cout << "Yes\n";
			else cout << "No\n";
		}

		//for(int i=2;i<10;i++) cout << get(0,0,MAX-1,i) << ' ';
		//cout << '\n';
	}

	return 0;
}
