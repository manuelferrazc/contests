#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int main() { _
    int n1,n2,n3,n4;

    cin >> n1;
    vector<int> v1(n1);
    for(auto &i:v1) cin >> i;
    sort(v1.begin(),v1.end());

    cin >> n2;
    vector<int> v2(n2);
    for(auto &i:v2) cin >> i;
    sort(v2.begin(),v2.end());

    cin >> n3;
    vector<int> v3(n3);
    for(auto &i:v3) cin >> i;
    sort(v3.begin(),v3.end());

    cin >> n4;
    vector<int> v4(n4);
    for(auto &i:v4) cin >> i;
    sort(v4.begin(),v4.end());

    int ans[5], a=0,b=0,c=0,d=0;
    ans[0]=INT_MAX;

    while(a<n1 and b<n2 and c<n3 and d<n4) {
        int ma = max({v1[a],v2[b],v3[c],v4[d]});
        int mi = min({v1[a],v2[b],v3[c],v4[d]});

        if(ma-mi<ans[0]) {
            ans[0] = ma-mi;
            ans[1] = v1[a];
            ans[2] = v2[b];
            ans[3] = v3[c];
            ans[4] = v4[d];
        }

        if(v1[a]<min({v2[b],v3[c],v4[d]})) a++;
        else if (v2[b]<min(v3[c],v4[d])) b++;
        else if(v3[c]<v4[d]) c++;
        else d++;
    }

    for(int i=1;i<5;i++) cout << ans[i] << ' ';
    cout << '\n';

    return 0;
}
