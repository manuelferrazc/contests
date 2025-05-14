#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<pair<int,int>> ans;

void move(int n, int d, int p) {
    if(n==1) {
        ans.push_back(make_pair(d,p));
        return;
    }

    if(d==1) move(n-1,1,p==2?3:2);
    else if(d==2) move(n-1,2,p==1?3:1);
    else move(n-1,3,p==1?2:1);

    ans.push_back(make_pair(d,p));

    if(d==1) move(n-1,p==2?3:2,p);
    else if(d==2) move(n-1,p==1?3:1,p);
    else move(n-1,p==1?2:1,p);
}

int main() { _
    int n;
    cin >> n;

    move(n,1,3);
    cout << ans.size() << '\n';
    for(auto &i:ans) cout << i.ff << ' ' << i.ss << '\n';

    return 0;
}
