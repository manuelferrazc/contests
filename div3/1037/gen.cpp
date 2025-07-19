#include <bits/stdc++.h>

using namespace std;
#define ll long long
int main(int argc, char** argv) {
    cout << "1\n";
    int s = atoi(argv[1]);
    srand(s);
    ll n = rand()%10+1;
    n++;
    ll a = rand()+2,b=rand()+2;
    a%=(ll)10;
    b%=(ll)10;
    while(b>=a) {a=rand();b=rand(); a%=(ll)10;
    b%=(ll)10;}
    cout << n << ' ' << a << ' ' << b << '\n';
    for(int i=0;i<n;i++) cout << rand()%n+1 << ' ';
    cout << endl;
    return 0;
}