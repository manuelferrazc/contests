#include <bits/stdc++.h>
using namespace std;

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 1 + rand()%1500;
    vector<char> v;
    for(char c='a';c<='z';c++) v.push_back(c);

    for(int i=0;i<n;i++) cout << v[rand()%26];
    cout << '\n';
    for(int i=0;i<26;i++) {
        if(rand()&1) cout << '1';
        else cout << '0';
    }
    cout << '\n' << rand()%(n+1) << '\n';
    return 0;
}