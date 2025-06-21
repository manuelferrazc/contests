#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

struct ball {
    int x,y;
    int dx,dy;

    void walk() {
        x+=dx;
        y+=dy;
    }

    void inv_all(){
        dx*=-1;
        dy*=-1;
    }

    void invx(){
        dx*=-1;
    }

    void invy() {
        dy*=-1;
    }

    bool pool(int s) {
        if((x==0 or x==s) and (y==0 or y==s)) return true;
        return false;
    }

    void colision(int s) {
        if(x==0 or x==s) invy();
        if(y==0 or y==s) invx();
    }
};

void solve() {
    int n,ans=0,s;
    cin >> n >> s;

    vector<ball> v(n);
    for(ball &b:v) cin >> b.dx >> b.dy >> b.x >> b.y;

    for(int i=0;i<n;i++) {
        if(v[i].x==v[i].y and v[i].dx==v[i].dy) ans++;
        else if(v[i].x==s-v[i].y and v[i].dx!=v[i].dy) ans++;
        else if(v[i].y==s-v[i].x and v[i].dx!=v[i].dy) ans++;

    }

    cout << ans << '\n';
}

int main() { _
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
