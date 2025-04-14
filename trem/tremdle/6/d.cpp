#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int calc(vector<int> &v) {
    if(v.empty()) return 0;
    if(*max_element(v.begin(),v.end())==0 and *min_element(v.begin(),v.end())==0) return 0;
    if(v.size()==1ULL) return 1;

    
    int r=1,r2=1, m = v[0];
    for(int &i:v) i-=m;
    // for(int i:v) cout << i << ' ';
    // cout << '\n';
    vector<int> aux;
    for(int i:v) {
        if(i) aux.push_back(i);
        else {
            // cout << '\n';
            if(aux.size()) r+=calc(aux);
            aux.clear();
        }
    }
    if(aux.size()) r+=calc(aux);

    for(int &i:v) i+=m;
    m = v.back();
    for(int &i:v) i-=m;

    aux.clear();
    for(int i:v) {
        if(i) aux.push_back(i);
        else {
            // cout << '\n';
            if(aux.size()) r2+=calc(aux);
            aux.clear();
        }
    }

    if(aux.size())r2+=calc(aux);

    return min(r,r2);
}

int main() {
    int n, ans=0;
    cin >> n;
    set<int> s;
    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(s.count(a)) ans++;
        s.insert(a);
    }
    vector<int> v;

    for(int i=0;i<n;i++) {
        int a;
        cin >> a;
        if(a) v.push_back(a);
        else {
            vector<int> v2;
            for(ull j=0;j<v.size();j++) {
                if(j>0 and j<v.size()-1 and v[j]==v[j-1]+v[j+1]) {
                    ans+=calc(v2);
                    v2.clear();
                } else v2.push_back(v[j]);
            }
            ans+=calc(v2);
            v.clear();
        }
    }
    vector<int> v2;
    for(ull i=0;i<v.size();i++) {
        if(i>0 and i<v.size()-1 and v[i]==v[i-1]+v[i+1]) {
            ans+=calc(v2);
            v2.clear();
        } else v2.push_back(v[i]);
    }
    ans+=calc(v2);
    v.clear();

    // só queria ganhar o leite :(
    return 0;
}