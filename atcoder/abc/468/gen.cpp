#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 1+ rand()%10;
    cout << n << '\n';
	int v[n];
	iota(v,v+n,1);
	while(n>0) {
		int x = rand()%n;
		cout << v[x] << ' ';
		swap(v[x],v[n-1]);
		n--;
	}
    cout << '\n';
    return 0;
}
