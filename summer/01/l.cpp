#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

int calc(string *v, int n, int m) {
    int dp[n][m];

    for(int j=n-1;j>=0;j--) 
        dp[j][m-1] = (v[j][m-1]=='.');

    for(int j=m-2;j>=0;j--) 
        dp[n-1][j] = (v[n-1][j]=='.');

    for(int i=n-2;i>=0;i--) {
        for(int j=m-2;j>=0;j--) {
            if(v[i][j]=='X') dp[i][j] = 0;
            else dp[i][j] = 1+min({dp[i+1][j],dp[i][j+1],dp[i+1][j+1]});
        }
    }

    int ans = 0;
    for(int i=0;i<n;i++) 
        for(int j=0;j<m;j++) ans = max(ans,dp[i][j]);

    return ans;
}

int main() { _
    int n,m,k;
    cin >> n >> m >> k;

    stack<int> ans;

    string v[n];
    for(string &s:v) cin >> s;
    
    set<int> aux[m];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) if(v[i][j]=='X') aux[j].insert(i);
    for(int i=0;i<m;i++) {
        aux[i].insert(n);
        aux[i].insert(-1);
    }

    vector<pair<int,int>> cars(k);
    for(int i=0;i<k;i++) {
        int a,b;
        cin >> a >> b;
        a--;
        b--;

        v[a][b] = 'X';
        aux[b].insert(a);
        cars[i] = pair(a,b);
    }


    ans.push(calc(v,n,m));

    while(cars.size()) {
        auto [x,y] = cars.back();
        cars.pop_back();

        aux[y].erase(x);
        v[x][y] = '.';

        int l = y;
        while(l>0 and v[x][l-1]=='.') l--;

        deque<int> top,bot;
        queue<int> taux,baux;
        int r = l;
        int act = ans.top();

        while(r<m and v[x][r]=='.') {
            auto it = aux[r].lower_bound(x);
            int low = *it-x-1;
            // cout <<*it << ' ' << low << ' ';

            while(bot.size() and bot.back()>low) bot.pop_back();
            bot.push_back(low);
            baux.push(low);

            it--;
            low = x-*it-1;
            // cout << low << '\n';

            while(top.size() and top.back()>low) top.pop_back();
            top.push_back(low);
            taux.push(low);

            low = top.front()+bot.front()+1;

            act = max(act,min(low,r-l+1));

            if(low<r-l+1) {
                if(bot.front()==baux.front()) bot.pop_front();
                if(top.front()==taux.front()) top.pop_front();
                taux.pop();
                baux.pop();
                l++;
            }

            r++;
        }

        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) cout << v[i][j];
        //     cout << '\n';
        // }

        // cout << act << '\n';
        ans.push(act);
    }

    ans.pop();

    while(ans.size()) {
        cout << ans.top() << '\n';
        ans.pop();
    }

    return 0;
}
