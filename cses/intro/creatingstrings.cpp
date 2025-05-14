#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    string s;
    cin >> s;
    int n = s.size();

    vector<int> v;
    for(int i=0;i<n;i++) v.push_back(i);

    set<string> st;

    do {
        string cu;
        for(auto i:v) cu.push_back(s[i]);
        st.insert(cu);
    } while (next_permutation(v.begin(),v.end()));

    cout << st.size() << '\n';
    for(string const &sss:st) cout << sss << '\n';

    
    return 0;
}
