#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;


int main() { _
    string v[10];
    for(int i=0;i<10;i++) cin >> v[i];

    vector<char> c;
    for(string &s:v) for(char l:s) c.push_back(l);

    int p = 0;
    int i = 0;

    for(int t=0;t<10;t++) {
        if(c[i]=='X') {
            p+=10;
            if(c[i+1]=='X') {
                p+=10;
                if(c[i+2]=='X') p+=10;
                else p+=c[i+2]-'0';
            } else {
                if(c[i+2]=='/') {
                    p+=10;
                } else {
                    p+=c[i+1]-'0';
                    p+=c[i+2]-'0';
                }
                // p+=c[i+1]-'0';
            }
            i+=1;
        } else if(c[i+1]=='/') {
            p+=10;
            if(c[i+2]=='X') p+=10;
            else p+=c[i+2]-'0';
            i+=2;
        } else {
            p+=c[i]-'0';
            p+=c[i+1]-'0';
            i+=2;
        }
    }

    cout << p << '\n';

    return 0;
}