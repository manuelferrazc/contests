#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

bool prime(int n) {
    if(n==2) return true;
    if(n%2==0) return false;
    for(int i=3;i*i<=n;i+=2) if(n%i==0) return false;
    return true;
}

int main() { _
    string s;
    cin >> s;
    int n = s.size();

    if(n<4) {
        cout << "YES\n" << s << '\n';
        return 0;
    }
    string ans(n,'.');
    
    map<char,int> m;
    multimap<int,char> m2;
    for(char c:s) m[c]++;
    for(auto [a,b]:m) m2.insert({b,a});

    vector<int> primes;
    for(int i=2;i<=n;i++) if(prime(i)) primes.push_back(i);
    
    vector<bool> vis(n+1,false);
    int qtd=0;

    auto maior = m2.rbegin();

    auto f = [&](auto self,int i) -> void {
        if(i>n or vis[i] or i<2) return;
        vis[i] = true;
        qtd++;

        for(int j = i;j<=n;j+=i) self(self,j);
        for(int p:primes) if(i%p==0) self(self,i/p);
    };
    f(f,2);

    if(qtd>maior->ff) {
        cout << "NO\n";
        return 0;
    }
    for(int i=2;i<=n;i++) if(vis[i]) ans[i-1] = maior->ss;
    if(maior->ff>qtd) 
        m[maior->ss]-=qtd;
    else m.erase(maior->ss);

    for(char &c:ans) {
        if(c=='.') {
            c=m.begin()->ff;
            m.begin()->ss--;
            if(m.begin()->ss==0) m.erase(m.begin());
        }
    }

    cout << "YES\n" << ans << '\n';

    return 0;
}
