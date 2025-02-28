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


int main() { _
    string s; cin >> s;
    ull soma,c1,c2;
    ull total=0;
    
    for(ull i=0;i<s.size();i++) {
        if((s[i]-'0')%3==0) {
            total++;
            continue;
        }
        soma=(s[i]-'0')%3;
        if(soma%3==1) {c1=1,c2=0;}
        else {c1=0,c2=1;}
        
        for(i++;i<s.size();i++) {
            soma+=((s[i]-'0')%3);
            if(soma%3==0 || s[i]=='0') {
                total++;
                break;
            }
            
            if(c1) {
                if((soma-1)%3==0) {
                    total++;
                    break;
                }
            }
            if(c2) {
                if((soma-2)%3==0) {
                    total++;
                    break;
                }
            }
            if(soma%3==1) c1 = 1;
            if(soma%3==2) c2 = 1; 
        }
    }



    cout << total << '\n';
    return 0;
}