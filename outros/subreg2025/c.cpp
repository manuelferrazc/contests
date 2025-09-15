#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int n,ans=0;
    cin >> n;

    vector<int> v(n+1);
    for(int i=n;i>=0;i--) cin >> v[i];

    while(v.size()!=1) {
        if(v[0]) {
            vector<int> v2(v.size()+1,0);
            for(int i=0;i<v.size();i++) v2[i+1] = v[i];
            for(int i=0;i<v.size();i++) v2[i] += v[i];
            v2[0]+=1;
            
            for(int &i:v2) i&=1;
    
    
            while(v2.back()==0) v2.pop_back();
            v = v2;
        } else {
            for(int i=1;i<v.size();i++) v[i-1] = v[i];
            v.pop_back();
        }

        ans++;
    }

    cout << ans << '\n';

    return 0;
}
