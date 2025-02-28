#include <algorithm>
#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define dbg(a) cout << #a << " = " << a << endl;
#define pb push_back
#define f first
#define s second
typedef unsigned ui;
typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> vi;
typedef vector<bool> vb;
typedef vector<ll> vll;
typedef vector<string> vs;
typedef vector<vector<int>> vvi;
typedef pair<int,int> pii;
typedef map<int,int> mii;
typedef set<int> si;

int main() { _
    int n,x;
    cin >> n;
    
    vi dur(n+1);
    vb apertou(n+1);
    map<int,int> tempo;

    bool b;
    for(int i=1;i<=n;i++) {
        cin >> x >> dur[i] >> b;
        apertou[i] = b;
        tempo.insert({x,i});
    }

    vi sad;
    deque<pii> pl;

    for(int i=1;tempo.size();i++) {
        b=false;
        if(pl.size()) {
            pl.front().f--;
            if(pl.front().f==0) {
                pl.pop_front();
                b = true;
            }
        }

        if(tempo.count(i)) { // alguem entrou na fila
            int id = tempo.at(i);
            if(not b) { // ngm foi removido
                if(pl.size() and apertou[id]) { // se tem alguem na fila e a pessoa furou
                    sad.push_back(pl.front().s); // quem ta na fila fica triste
                    pl.pop_front(); // perde a musica
                    pl.push_front({dur[id],id}); // e a nova pessoa entra na frente
                } else pl.push_back({dur[id],id}); // tá vazia ou não furou (talvez ambos)
            } else { // removeu alguem
                if(apertou[id]) pl.push_front({dur[id],id});
                else pl.push_back({dur[id],id});
            }
            tempo.erase(i);
        }
    }

    cout << sad.size() << '\n';
    for(int i:sad) cout << i   << ' ';
    if(sad.size()) cout << '\n';

    return 0;
}