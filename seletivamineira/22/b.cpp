#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
pair<int,int> pf;
string f, op;

bool check(string &s) {
    char d='N';
    pair<int,int> p;
    p.ff = p.ss = 0;
    
    for(char c:s) {
        if(c=='F') {
            if(d=='N') p.ss++;
            else if(d=='S') p.ss--;
            else if(d=='W') p.ff--;
            else p.ff++;
        } else if(c=='B') {
            if(d=='N') p.ss--;
            else if(d=='S') p.ss++;
            else if(d=='W') p.ff++;
            else p.ff--;
        } else if(c=='L') {
            if(d=='N') d='W';
            else if(d=='S') d='E';
            else if(d=='W') d='S';
            else d='N';
        } else {
            if(d=='N') d='E';
            else if(d=='S') d='W';
            else if(d=='W') d='N';
            else d='S';
        }
    }

    return d==f[0] and pf==p;
}

int main() { _
    cin >> n >> pf.ff >> pf.ss >> f >> op;

    
    if(check(op)) {
        cout << 0 << '\n';
        return 0;
    }
    else {
        char c[] = {'F','B','R','L'};
        for(int i=0;i<n;i++) {
            char cc = op[i];
            for(char sla:c) {
                if(sla==cc) continue;
                op[i] = sla;
                if(check(op)) {
                    cout << i+1 << ' ' << sla << '\n';
                    return 0;
                }
                op[i] = cc;
            } 
        }
    }

    cout << -1 << '\n';
    return 0;
}
