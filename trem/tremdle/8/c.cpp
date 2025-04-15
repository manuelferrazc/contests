#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

ll count(ll n) {
    ll r=0;
    for(ll i=0;i<63;i++) if(n&(1LL<<i)) r++;
    return r;
}

int main() {
    
    cout << "? 0\n";
    cout.flush();
    ll qtd, ans=0;
    cin >> qtd;
    srand(qtd);
    qtd = count(qtd);

    vector<ll> erro;
    for(ll i=0;i<59;i+=2) {
        ll q=0, x;
        q|=1LL<<i;
        q|=1LL<<(i+1);
        cout << "? " << q << '\n';
        cout.flush();
        cin >> x;
        x = count(x);
        if(x==qtd+2) continue; // os bits q perguntei são 0
        else if(x==qtd-2) { // os bits q perguntei são 1
            ans|=1LL<<i;
            ans|=1LL<<(i+1);
        } else erro.push_back(i); // os bits q perguntei são 01 ou 10
    }

    while(erro.size()) {
        if(erro.size()==1) {
            ll q=1LL<<erro.front();
            cout << "? " << q << '\n';
            cout.flush();
            cin >> q;
            if(q==-1LL) return 0;
            if(count(q)==qtd+1) ans|=1LL<<(erro.front()+1);
            else ans|=1LL<<(erro.front());
            erro.pop_back();
            continue;
        }

        ll b1 = erro.back();
        erro.pop_back();
        ll b2 = erro.back(),r1=rand()&1,r2=rand()&1;
        erro.pop_back();

    
        ll q = 1LL<<(b1+r1);
        q |= 1LL<<(b2+r2);

        cout << "? " << q << '\n';
        cout.flush();

        ll res, qq;
        cin >> res;
        if(res==-1LL) return 0;
        qq = count(res);
        if(qq==qtd+2) {
            ans|=1LL<<(b1+(r1==0LL));
            ans|=1LL<<(b2+(r2==0LL));
        } else if(qq==qtd-2) {
            ans|=1LL<<(b1+r1);
            ans|=1LL<<(b2+r2);
        } else { // acertei só 1, tem q perguntar dnv :(
            q = 1LL<<(b1+r1);
            cout << "? " << q << '\n';
            cout.flush();
            cin >> q;
            if(q==-1LL) return 0;
            q = count(q);
            if(q==qtd+1) { // acertei um 0 no primeiro par, logo o do segundo par ta 1
                ans|=1LL<<(b1+(r1==0LL));
                ans|=1LL<<(b2+r2);
            } else { // cc
                ans|=1LL<<(b1+r1);
                ans|=1LL<<(b2+(r2==0LL));
            }
        }
    }

    cout << "! " << ans << '\n';
    cout.flush();

    return 0;
}
