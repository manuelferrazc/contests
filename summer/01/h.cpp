#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct bit {
    int *v;
    int n;
    
    bit(int n2,int *v2=nullptr) {
        n = n2;
        v = new int[n+1];
        for(int i=1;i<=n;i++) v[i] = 0;

        if(v2!=nullptr) {
            for(int i=1;i<=n;i++) {
                v[i]+=v2[i];
                int j = i+(i&(-i));
                if(j<=n) v[j]+=v[i];
            }
        }
    }
    
    ~bit() {
        delete[] v;
    }
    
    void update(int i, int x) {
        for(i+=1;i<=n;i+=(i&(-i))) v[i]+=x;
    }

    int pref(int i) {
        int r = 0;
        for(i++;i;i-=(i&(-i))) r+=v[i];
        return r;
    }

    int query(int l, int r) {
        return pref(r)-pref(l-1);
    }
};


int main() { _
	int n,m;
	cin >> n >> m;

	int ans[m];
	for(int i=0;i<m;i++) ans[i] = n;

	bit bt(1'000'002);

	
	/*
	0 -> l, deve ser decrescente
	1 -> tipo de evento
	2 -> talvez r?
	3 -> id da consulta
	
	dado um mesmo x, quero:
	- fazer as consultas
	- adicionar os novos intervalos
	*/

	vector<array<int,4>> ev;
	for(int i=0;i<n;i++) {
		int l,r;
		cin >> l >> r;

		ev.push_back({l,1,r,-1});
	}

	for(int i=0;i<m;i++) {
		int qtd;
		cin >> qtd;

		int x;
		cin >> x;
		ev.push_back({0,0,x,i});
		for(int j=1;j<qtd;j++) {
			int x2;
			cin >> x2;
			ev.push_back({x,0,x2,i});
			x = x2;
		}

		ev.push_back({x,0,1'000'001,i});
	}

	sort(ev.begin(),ev.end(),
		[&](array<int,4> const &a, const array<int,4> &b) -> bool {
			if(a[0]>b[0]) return true;
			if(a[0]==b[0]) return a[1]<b[1];
			return false;
		}
	);

	for(auto [l,op,r,id]:ev) {
		if(op) bt.update(r,1); // adicionar intervalo
		else {
			int q = bt.query(l,r-1);
			ans[id]-=q;
		}
	}

	for(int i=0;i<m;i++) cout << ans[i] << '\n';

    return 0;
}
