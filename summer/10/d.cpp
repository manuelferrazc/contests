#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { 
    int n,w,h,s2;
    cin >> n >> w >> h >> s2;

    int ans=1;
    char c = -1;
    while(n--) {
        string l, s;
        cin >> s;

        for(int cu=0;cu<h;cu++) {
            cin >> l;

            int sw = 0;
            if(l[0]=='#') sw++;
            for(int i=1;i<w;i++) if(l[i]!=l[i-1]) sw++;

            if(l.back()=='#') sw++;

            if(sw>ans) {
                ans = sw;
                c = s[0];
            }
        }
    }

    int qtd = s2/ans;
    if(s2%ans) qtd++;

    for(int i=0;i<qtd;i++) cout << c;
    cout << '\n';

    return 0;
}
