#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> pot2;

pair<int,int> op(int x) {
    int ans=0;
    int cnt=0;
    if((x&1) and (not (x&2)) and (x&4)) cnt=1;
    while(x>1) {
        x/=2;
        if(x>1) x++;
        ans++;
    }
    return {ans,cnt};
}

void make_sp(int* v, int *sp, int n) {
    sp[0] = v[0];
    for(int i=1;i<n;i++) sp[i] = sp[i-1]+v[i];
}

int inline get(int *sp, int l, int r) {
    if(l==0) return sp[r];
    return sp[r]-sp[l-1];
}

void solve() {
    int n,q;
    cin >> n >> q;

    int v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    int qt[n];
    int q5[n];// ?????????????????????????????????????
    for(int i=0;i<n;i++) {
        auto [a,b] = op(v[i]);

        qt[i] = a;
        q5[i] = (i?q5[i-1]:0)+b;
    }
    
    int qt3[n]
    // ,qt2[n]
    ;
    
    // for(int i=0;i<n;i++) qt2[i] = (i?qt2[i-1]:0) + (v[i]==2);
    for(int i=0;i<n;i++) qt3[i] = (i?qt3[i-1]:0) + (v[i]==3);
    
    int spqt[n];
    
    make_sp(qt,spqt,n);

    while(q--) {
        int l,r;
        cin >> l >> r;
        r--;
        l--;

        // int qtd3 = get(sp3,0,0,n-1,l,r);
        int qtd3 = get(qt3,l,r);
        // int qtd2 = get(qt2,l,r);
        int qtdop = get(spqt,l,r);
        int qsla = get(q5,l,r);
        if(qtd3>1 or (qtd3 and qsla)) 
            cout << qtdop + qtd3/2+(qtd3&1) << '\n';// << ' ' << qtd3 << '\n';
        else if(qtd3==0 and qsla>=3) 
            cout << qtdop + qsla/3 << '\n';
        // else if(qt3==1)
        else cout << qtdop << '\n';
    }
}

int main() { _
    for(ll i=4;i<INT_MAX;i<<=1) pot2.push_back(i-2);

    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
