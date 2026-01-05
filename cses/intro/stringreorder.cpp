#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;

bool ok(vector<int> &v, char c='#') {
    auto it = max_element(v.begin(),v.end());
    int mx = *it;
    char id = (char)(it-v.begin())+'A';
    if(n&1){
        if(mx<=n/2) return true;
        if(mx==n/2+1 and id!=c) return true;
    } else if(mx<=n/2) return true;

    return false;
}


void brute(vector<int> &v, char last='#') {
    if(n==0) return;
    n--;

    for(int i=0;i<26;i++) {
        char l = i+'A';

        if(v[i] and l!=last) {
            v[i]--;
            if(ok(v,l)) {
                cout << l;
                return brute(v,l);
            }
            v[i]++;
        }
    }
}

int main() { _
    string s;
    cin >> s;
    n = s.size();

    vector<int> v(26,0);
    for(char c:s) v[c-'A']++;

    if(not ok(v)) {
        cout << -1 << '\n';
        return 0;
    }

    brute(v);
    cout << '\n';
    
    return 0;
}
