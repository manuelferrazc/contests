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
typedef unsigned long long ull;
typedef unsigned long ul;
typedef vector<int> vi;
typedef pair<int,int> pii;

bool palindromo(string &s1, string &s2) {
    for(int i=0;i<s1.size();i++) if(s1[i]!=s2[s2.size()-1-i]) return false;
    return true;
}

bool palindromo(string &s) {
    for(int i=0;i<s.size()/2;i++) if(s[i]!=s[s.size()-1-i]) return false;
    return true;
}

int main() { _
    int n,t;
    cin >> n >> t;
    vector<string> v(n);
    for(int i=0;i<n;i++) cin >> v[i];
    list<string> l;

    vector<bool> usado(n,false);
    int p=-1;

    for(int i=0;i<n;i++) {
        if(usado[i]) continue;

        bool b=false;
        for(int j=i+1;j<n;j++) {
            if(usado[j]) continue;

            if(palindromo(v[i],v[j])) {
                usado[i] = true;
                usado[j] = true;
                l.push_back(v[j]);
                l.push_front(v[i]);
                b=true;
                break;
            }
        }
        if(b) continue;
        if(p==-1) {
            if(palindromo(v[i])) {
                usado[i] = true;
                p = i;
            }
        }
    } 
    cout << t*(l.size()+(p!=-1)) << '\n';
    n=0;
    for(auto &s:l) {
        cout << s;
        if(n == l.size()/2-1 and (p!=-1)) cout << v[p];
        n++;
    }
    if(l.size()==0 and p!=-1) cout <<v[p];
    cout << endl;
    return 0;
}