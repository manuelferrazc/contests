#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define ff first
#define ss second
typedef long long ll;
typedef unsigned long long ull;

string solve() {
    int n;
    string s;
    cin >> n >> s;

    for(int i=0;i<n;) {
        // cout << i << '\n';
        if(s[i]=='1' or (i and s[i-1]=='0') or (i<n-1 and s[i+1]=='0')) {
            i++;
            continue;
        }

        int start = i,end=i+1;
        while(end<n and s[end]!=s[end-1]) end++;
        
        // end é o ultimo 0 da sequencia alternante
        end--;
        if(s[end]=='1') end--;

        if(end==start and start and end<n-1) {
            if(start>1 and s[start-2]=='0') {
                i++;
                continue;
            }
            return "NO";
        }
        if(start and end<n-1) {
            if((s[start-1]=='1' and s[end+1]=='1')) {
                if(start>1 and s[start-2]=='0') {
                    i=end+1;
                    continue;
                }
                // cout << "start end : " << i << ' ' << start << ' ' << end << '\n';
                if(((end-start)/2)%2==0) return "NO";
            }
        }

        i = end+1;
        while(i<n and s[i]==s[i-1]) i++;
        // if(i<n and)
    }

    return "YES";
}

int main() { _
    int t;
    cin >> t;
    while(t--) cout << solve() << '\n';
    return 0;
}
