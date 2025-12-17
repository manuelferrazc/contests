#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

const char *yes = "Yes\n";
const char *no = "No\n";
const char *en = ""; // ????

int mi[800'000],ma[800'000];

void build(int pos, int l, int r, int *v) {
    if(l==r) mi[pos] = ma[pos] = v[l];
    else {
        int m = (l+r)>>1;
        int ls = 2*pos+1;

        build(ls,l,m,v);
        build(ls+1,m+1,r,v);

        mi[pos] = min(mi[ls],mi[ls+1]);
        ma[pos] = max(ma[ls],ma[ls+1]);
    }
}

void change(int pos, int l, int r, int i) {
    if(i<l or r<i) return;
    else if(l==r) {
        mi[pos] = INT_MAX;
        ma[pos] = INT_MIN;
    } else {
        int m = (l+r)>>1;
        int ls = 2*pos+1;

        change(ls,l,m,i);
        change(ls+1,m+1,r,i);

        mi[pos] = min(mi[ls],mi[ls+1]);
        ma[pos] = max(ma[ls],ma[ls+1]);

    }
}

int getmi(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return INT_MAX;
    if(lq<=l and r<=rq) return mi[pos];

    int m = (l+r)>>1;
    int ls = 2*pos+1;

    return min(getmi(ls,l,m,lq,rq),getmi(ls+1,m+1,r,lq,rq));
}

int getma(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return INT_MIN;
    if(lq<=l and r<=rq) return ma[pos];

    int m = (l+r)>>1;
    int ls = 2*pos+1;

    return max(getma(ls,l,m,lq,rq),getma(ls+1,m+1,r,lq,rq));
}

const char * solve() {
    int n;
    cin >> n;

    int v[n],pref[n],suf[n];
    cin >> v[0];
    pref[0] = v[0];
    for(int i=1;i<n;i++) {
        cin >> v[i];
        pref[i] = min(pref[i-1],i[v]);
    }

    build(0,0,n-1,v);

    suf[n-1] = v[n-1];
    for(int i=n-2;i>=0;i--) suf[i] = max(suf[i+1],i[v]);

    for(int i=1;i<n;i++) {
        if(pref[i-1]>suf[i]) return no;
    }

    cout << yes;

    int pos[n+1];
    for(int i=0;i<n;i++) pos[v[i]] = i;

    queue<int> q;
    q.push(1);

    change(0,0,n-1,pos[1]);
    int cnt = 1;

    while(cnt<n) {
        int a = q.front();
        q.pop();

        while(pos[a]<n-1) {
            int x = getma(0,0,n-1,pos[a]+1,n-1);
            if(x==INT_MIN or x<a) break;
            change(0,0,n-1,pos[x]);
            cout << a << ' ' << x  << '\n';
            q.push(x);
            cnt++;
        }

        while(pos[a]) {
            int x = getmi(0,0,n-1,0,pos[a]-1);
            if(x>a) break;
            change(0,0,n-1,pos[x]);
            cout << a << ' ' << x << '\n';
            q.push(x);
            cnt++;
        }
    }

    return en;
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve();
    return 0;
}
