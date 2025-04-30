#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
string tr;

void solve() {
    cin >> n >> tr;
    int q=0;
    vector<string> v(2*n);
    for(string &ss:v) {
        cin >> ss;
        swap(ss[0],ss[1]);
    }
    
    sort(v.begin(),v.end());
    vector<string> a,b(n);
    for(auto it = v.end()-1;;) {
        if((*it)[0]==tr[0]) {
            auto aux = it;
            if(a.size()<n) a.push_back(*aux);
            else b[q++] = *aux;
            it = v.erase(aux);
            if(it==v.begin()) break;
            else it--;
        } else {
            if(it==v.begin()) break;
            it--;
        }
    }

    while(a.size()<n) {
        if(v.back()[0]==v[v.size()-2][0]) {
            b[a.size()] = v[v.size()-2];
            a.push_back(v.back());
            v.pop_back();
            v.pop_back();
        } else {
            if(q<a.size() and a[q][0]==tr[0]) {
                if(not b[q].empty()) {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
                b[q] = v.back();
                v.pop_back();
                q++;
            } else {
                cout << "IMPOSSIBLE\n";
                return;
            }
        }
    }

    for(string s:v) {
        for(int i=0;i<n;i++) {
            if(b[i].empty()) {
                if(s[0]==a[i][0] and s[1]<a[i][1] or a[i][0]==tr[0]) {
                    b[i] = s;
                } else {
                    cout << "IMPOSSIBLE\n";
                    return;
                }
                break;
            }
        }
    }

    if(a.size()==n) {
        for(auto it = a.rbegin();it!=a.rend();it++) {
            string s = *it;
            swap(s[0],s[1]);
            if(b.size()) {
                swap(b.back()[0],b.back()[1]);
                cout << b.back() << ' ' << s << '\n';
                b.pop_back();
            } else {
                swap(v.back()[0],v.back()[1]);
                cout << v.back() << ' ' << s << '\n';
                v.pop_back();
            }
        }
    } else cout << "IMPOSSIBLE\n";
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
