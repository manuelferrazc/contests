#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

vector<int> st;
int q;

int sett(int pos, int l, int r, int i, int v) {
    if(i<l or r<i) return st[pos];
    if(l==r) return st[pos] = v;

    int m = (l+r)>>1,ls = 2*pos+1;
    return st[pos] = sett(ls,l,m,i,v)|sett(ls+1,m+1,r,i,v);
}

int get(int pos, int l, int r, int lq, int rq) {
    if(rq<l or r<lq) return 0;
    if(lq<=l and r<=rq) return st[pos];

    int m = (l+r)>>1,ls = 2*pos+1;
    return get(ls,l,m,lq,rq)|get(ls+1,m+1,r,lq,rq);
}

int find(int v, int l=0) {
    int r=q-1;
    if((get(0,0,q-1,l,q-1)&v)==0) return -1;

    int ans=q-1;

    while(l<=r) {
        int m = (l+r)>>1;
        int x = get(0,0,q-1,l,m);
        if(x&v) {
            ans = m;
            r=m-1;
        } else l=m+1;
    }

    return ans;
}

void solve() {
    int n;
    cin >> n >> q;
    string s;
    cin >> s;

    st.assign(q<<2,0);

    for(int i=0;i<q;i++) {
        string a,b;
        cin >> a >> b;
        if(a[0]=='a' or a[0]==b[0]) continue;
        else if(a[0]=='b' and b[0]=='a') sett(0,0,q-1,i,1);
        else if(a[0]=='b' and b[0]=='c') sett(0,0,q-1,i,2);
        else if(a[0]=='c' and b[0]=='a') sett(0,0,q-1,i,4);
        else sett(0,0,q-1,i,8);
    }

    // for(int i=0;i<q;i++) cout << get(0,0,q-1,i,i) << ' ';
    // cout << '\n';
    // return ;
    
    for(int i=0;i<n;i++) {
        if(s[i]=='b') {
            int x = find(1);
            if(x!=-1) {
                s[i] = 'a';
                sett(0,0,q-1,x,0);
            } else {
                x = find(2);
                if(x==-1 or x==q-1) continue;
                int y = find(4,x+1);
                if(y!=-1) {
                    sett(0,0,q-1,x,0);
                    sett(0,0,q-1,y,0);
                    s[i] = 'a';
                }
            }
        } else if(s[i]=='c') {
            int x = find(4);
            if(x!=-1) {
                sett(0,0,q-1,x,0);
                s[i] = 'a';
            } else {
                x = find(8); // c b
                if(x==q-1) {
                    s[i] = 'b';
                    sett(0,0,q-1,x,0);
                } else if(x!=-1) {
                    int y = find(1,x);
                    if(y!=-1) {
                        s[i] = 'a';
                        sett(0,0,q-1,x,0);
                        sett(0,0,q-1,y,0);
                    } else {
                        s[i] = 'b';
                        sett(0,0,q-1,x,0);
                    }
                }
            }
        }
    }
    cout << s << '\n';
}

int main() { 
    int t;
    cin >> t;
    while(t--) solve();
    return 0;
}
