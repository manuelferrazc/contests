#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int p[1000];
int r[1000];

int get(int a) {
    return p[a] = (p[a]==a?a:get(p[a]));
}

bool unio(int a, int b) {
    a = get(a);
    b = get(b);

    if(a==b) return false;
    if(r[b]>r[a]) swap(a,b);
    if(r[a]==r[b]) r[a]++;
    p[b] = a;
    return true;
}

int main() { _
    int n;
    cin >> n;

    for(int i=0;i<n;i++) p[i] = i;
    for(int i=0;i<n;i++) r[i] = 1;

    vector<pair<int,int>> ex;
    for(int i=1;i<n;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        if(not unio(a,b)) ex.push_back({a,b});
    }

    vector<int> rep;
    for(int i=0;i<n;i++) if(get(i)==i) rep.push_back(i);

    cout << ex.size() << '\n';
    while(ex.size()) {
        cout << ex.back().ff+1 << ' ' << ex.back().ss+1 << ' ' << rep.back()+1 << ' ';
        rep.pop_back();
        cout << rep.back()+1 << '\n';
        ex.pop_back();
    }

    return 0;
}
