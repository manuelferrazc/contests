#include <bits/stdc++.h>
using namespace std;
mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());

int main(int argc, char**argv) {
    srand(atoi(argv[1]));
    int n = 1+ rand()%13;
    cout << n << '\n';
    double m[n][n];
    uniform_real_distribution<double> d(0,1);
    for(int i=0;i<n;i++) {
        m[i][i] = 0;
        for(int j=i+1;j<n;j++) {
            double x = d(rng);
            m[i][j] = x;
            m[j][i] = 1-x;
        }
    }

    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) cout << m[i][j] << ' ';
        cout << '\n';
    }
    // cout << '\n';
    return 0;
}