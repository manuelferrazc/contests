#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int cnt=0;

int ask(int v, int c) {
	assert(cnt<1000);
	cnt++;
	println("? {} {}",c,v);
	int ret;
	cin >> ret;
	return ret;
}

int say(int v, int c) {
	println("! {} {}", c, v);
	exit(0);
	return 0;
}

int main() {
	int n;
	cin >> n;

	int v = ask(1,n);

	const int magic = sqrt(n)+2;

	vector<int> path(magic);
	vector<int> w(n+1,-1);
	path[0] = v;
	w[v] = 0;
	for(int i=1;i<magic;i++) {
		int x = ask(v,i);
		path[i] = x;
		w[x] = i;
		if(x==v) {
			int len = i;
			int r = v%len;
			
			int u = v;
			if(r) u = ask(v,len-r);
			return say(u,v);
		}
	}

	int skip = magic;
	for(int j=1;;j++) {
		int j2 = min(n,j*skip);
		int x = ask(v,j2);
		
		if(w[x]!=-1) {
			int len = j2-w[x];
			int r = v%len;

			int u = v;
			if(r) u = ask(v,len-r);
			say(u,v);
			break;
		}
	}

	return 0;
}
