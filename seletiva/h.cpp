#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
#define INF INT_MAX
#define LINF LONG_MAX
#define LLINF LONG_LONG_MAX
typedef long long ll;
typedef long l;
typedef pair<int,int> pii;

void troca(vector<int> &v, set<int> &m) {
    auto it = m.rbegin();
    for(unsigned long long i=0;i<v.size();i++) {
        v[i] = *it;
        it++;
    }
}

int main() { _
    int n; cin >> n;
    set<int> si;
    vector<int> v;
    string s;
    
    int remover = 1, trocas = 0, x;

    for(int i=0;i<(n<<1);i++) {
        cin >> s;
        if(s.compare("add")==0) {
            cin >> x;
            v.push_back(x);
            si.insert(x);
        } else {
            if(v.size() and v.back()!=remover) {
                trocas++;
                v.clear();
                si.clear();
            } else if(v.size()) {
                si.erase(si.begin());
                v.pop_back();
            }
            remover++;
        }
    }
    
    cout << trocas << endl;

    return 0;
}