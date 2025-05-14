#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int mask=0,ans=0;

vector<vector<bool>> t(8,vector<bool>(8,false));
vector<string> v(8);

void brute(int r) {
    if(r==8) {
        ans++;
        return;
    }

    for(int i=0;i<8;i++) {
        if((mask&(1<<i)) or v[r][i]=='*') continue;
        mask+=1<<i;
        t[r][i] = true;
        bool ok = true;
        for(int j=1;r-j>=0;j++) {
            if(i-j>=0) {
                if(t[r-j][i-j]) {
                    ok = false;
                    break;
                }
            }
            if(i+j<8) {
                if(t[r-j][i+j]) {
                    ok = false;
                    break;
                }
            }
        }

        if(ok) brute(r+1);
        t[r][i] = false;
        mask-=1<<i;
    }
}

int main() { _
    for(string &s:v) cin >> s;

    brute(0);

    cout << ans << '\n';
    
    return 0;
}
