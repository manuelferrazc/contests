#pragma GCC target ("avx2") 
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")

#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int n;
double prob[18][18], ans = 0;

double mx(vector<int> &v, vector<bool> &us) {
    vector<double> dp(n,0);
    dp[v[0]] = prob[v[0]][v[1]];
    dp[v[1]] = prob[v[1]][v[0]];
    for(int i=2;i<v.size();i++) {
        for(int j=0;j<i;j++) dp[v[i]]+=dp[v[j]]*prob[v[i]][v[j]];
        for(int j=0;j<i;j++) dp[v[j]]*=prob[v[j]][v[i]];
    }
    
    for(int i=1;i<n;i++) {
        if(not us[i]) {
            for(int j=0;j<v.size();j++) dp[i]+=dp[v[j]]*prob[i][v[j]];
        }
    }

    for(int i=1;i<n;i++) dp[0]+=dp[i]*prob[0][i];
    return dp[0];
}

void calc(vector<int> &v, vector<bool> &us) {
    if(v.size()==n-1) {
        ans = max(ans,mx(v,us));
        return;
    }
    if(mx(v,us)<=ans) return;

    for(int i=1;i<n;i++) {
        if(us[i]==false) {
            us[i] = true;
            v.push_back(i);
            calc(v,us);
            us[i] = false;
            v.pop_back();
        }
    }
}

int main() { _
    cin >> n;
    
    if(n==1) {
        cout << "1\n";
        return 0;
    }
    
    for(int i=0;i<n;i++) for(int j=0;j<n;j++) cin >> prob[i][j];

    if(n<=10) {
        int v[n];
        iota(v,v+n-1,1);
        v[n-1] = 0;
        double dp[n];
        do {
            dp[v[0]] = prob[v[0]][v[1]];
            dp[v[1]] = prob[v[1]][v[0]];
            for(int i=2;i<n;i++) {
                dp[v[i]] = 0;
                for(int j=0;j<i;j++) dp[v[i]]+=dp[v[j]]*prob[v[i]][v[j]];
                for(int j=0;j<i;j++) dp[v[j]]*=prob[v[j]][v[i]];
            }
            ans = max(ans,dp[0]);
        } while(next_permutation(v,v+n-1));
    } else {
        for(int i=1;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                vector<int> v;
                v.push_back(i);
                v.push_back(j);
                vector<bool> us(n,false);
                us[i] = us[j] = true;
                calc(v,us);
            }
        }
    }
    cout << fixed << setprecision(10) << ans << '\n';

    return 0;
}

