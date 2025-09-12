#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int uniform(int l, int r){
	uniform_int_distribution<int> uid(l, r);
	return uid(rng);
}

template<typename t>
struct node {
    int prio;
    int ant,l,r;
    int size;
    t key;

    node(): prio(uniform(1,1e9)), ant(-1), l(-1), r(-1), size(0) {}

    node(int _ant, int _l, int _r, t _key): prio(uniform(1,1e9)), ant(_ant), l(_l), r(_r), key(_key) {}
};

template<typename t>
class Treap {
    node<t> *v;

    Treap(int n): v(new node<t>[n]) {}

    ~Treap() {
        delete[] v;
    }

    
};

int main() { _


    return 0;
}
