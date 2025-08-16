#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;


int main() { _
    int mx = 1'000'001;
    vector<int> c(mx,0);
    vector<int> v(mx,0);

    for(int i=2;i<mx;i++) {
        if(c[i]) continue;
        for(int j=i;j<mx;j+=i) c[j] = i;
    }

    int n;
    cin >> n;

    while(n--) {
        int x;
        cin >> x;

        map<int,int> fat;
        while(x>1) {
            fat[c[x]]++;
            x/=c[x];
        }

        vector<vector<int>> m(fat.size());
        auto it = fat.begin();

        for(int i=0;i<fat.size();i++) {
            int j=1;
            for(int e=0;e<=it->ss;e++) {
                m[i].push_back(j);
                j*=it->ff;
            }
            it++;
        }

        auto brute = [&](auto&& self, int n,int i) -> void {
            if(i==m.size()) {
                v[n]++;
                return;
            }

            for(int j=0;j<m[i].size();j++) 
                self(self,n*m[i][j],i+1);
        };

        brute(brute,1,0);
    }

    for(int i=mx-1;i;i--) {
        if(v[i]>1) {
            cout << i << '\n';
            return 0;
        }
    }

    return 0;
}
