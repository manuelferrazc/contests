#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

string s;

void solve(vector<int> &v) {
    for(ull i=0;i<s.size();i++) {
        if(s[i]=='0') continue;
        ll j=i;
        if(i!=s.size()-1 and s[i+1]=='1') for(;j<s.size();j++) {
            if(s[j]=='0' and s[j-1]=='0') {
                j-=2;
                break;
            }
        }
        if(j==s.size()) j--;
        if(j-i<=1) {
            v.push_back(i+1);
            if(j!=i) {
                v.push_back(i+2);
                i++;
            }
        } else if(j-i==2 and s[i+1]=='0') {
            v.push_back(i+1);
            v.push_back(j+1);
            i=j;
        } else {
            v.push_back(j+2);
            v.push_back(-i-1);
            for(ll sla = i;sla<=j;sla++) {
                if(s[sla]=='0') v.push_back(-sla-1);
            }
            i=j;
        }
    }
}

int main() { _
    cin >> s;
    reverse(s.begin(),s.end());
    vector<int> v;
    solve(v);

    cout << v.size() << '\n';
    for(int i:v) {
        if(i>=0) cout << "+2^" << i-1 << '\n';
        else cout << "-2^" << abs(i+1) << '\n';
    }

    return 0;
}
