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
    string original, anagrama;
    getline(cin,original);
    getline(cin, anagrama);
    
    map<char,int> m;
    for(int i=0;i<original.size();i++) {
        if(m.count(original[i])==0) m.insert({original[i],1});
        else m.at(original[i])++;
    }

    for(int i=0;i<anagrama.size();i++) {
        if(anagrama[i]=='*') continue;
        if(m.count(anagrama[i])==0) {
            cout << "N\n";
            return 0;
        }
        if(m.at(anagrama[i])==0) {
            cout << "N\n";
            return 0;
        } else m.at(anagrama[i])--;
    }
    cout << "S\n";
    return 0;
}