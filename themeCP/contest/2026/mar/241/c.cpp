#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

void yes() {
    cout << "YES\n";
}

void no() {
    cout << "NO\n";
}

void test() {
    cout << "TEST\n";
}

void solve() {
    int n;
    string s;
    cin >> n >> s;

    int pos[n];
    fill(pos,pos+n,-1);
    set<int> miss;
    for(int i=0;i<n;i++) miss.insert(i);

    for(int i=0;i<n;i++) {
        if(s[i]=='p') {
            int p = i;
            for(int j=i;j>=0;j--) {
                if(pos[j]!=-1) break;
                pos[p] = *miss.begin();
                miss.erase(*miss.begin());
                p--;
            }
        }
    }

    for(int i=n-1;i>=0;i--) {
        if(pos[i]==-1) {
            pos[i] = *miss.begin();
            miss.erase(miss.begin());
        }
    }

    // for(int i=0;i<n;i++) cout << pos[i] << ' ';
    // cout << '\n';

    for(int i=n-1;i>=0;i--) {
        if(s[i]=='s') {
            int qtd = n-i;
            vector<bool> seen(qtd,0);

            for(int j=i;j<n;j++) {
                if(pos[j]<qtd) seen[pos[j]] = true;
            }

            for(int j=0;j<qtd;j++) if(seen[j]==false) {
                return no();
            }
        }
    }

    yes();
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
