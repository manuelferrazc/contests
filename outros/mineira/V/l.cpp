#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

#define sz(x) (int)x.size()

struct matrix {
    int n, m;
    vector<vector<double>> arr;

    matrix(int _n, int _m) {
        this->n = _n;
        this->m = _m;
        arr.assign(_n, vector<double>(_m, 0));
    }

    matrix operator*(matrix& r) {
        matrix res(n, r.m);
        for(int i = 0; i < n ; i ++) {
            for(int k = 0; k < m; k ++) {
                for(int j = 0; j < r.m; j ++) {
                    res.arr[i][j] += this->arr[i][k] * r.arr[k][j];
                }
            }
        }
        return res;
    }

    matrix operator^(int e) {
        matrix res(n, n);
        for(int i = 0; i < n; i ++) res.arr[i][i] = 1;
        auto at = *this;

        while(e) {
            if(e & 1) res = res * at;
            e >>= 1;
            at = at * at; 
        }
        return res;
    }

    vector<double> mul(vector<double>& v) {
        vector<double> res(v.size());
        for(int i = 0; i < v.size(); i ++) {
            res[i] = 0;
            for(int j = 0; j < v.size(); j ++){
                res[i] += v[j] * this->arr[i][j];
            }
        }
        return res;
    }

    void print(){
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < m; j ++) {
                cout << arr[i][j] << " ";
            }
            cout << endl;
        }
    }
};

const double PI = acos(-1);

int main() { _ 

    string trash;
    double deg;
    int uni, times;
    
    double x = 0, y = 0;
    vector<double> v = {0, 1, 0, 1};
    vector<double> pos = {0, 0, 0, 1};
    double cur_rad = PI/2;
    while(cin >> trash >> deg >> trash >> uni >> trash >> times) {
        // cout << deg << " " << trash << " " << uni << " " << times << endl;
        // double vxnew = vx * cos(deg) - vy * sin(deg);
        // double vynew = vx * sin(deg) + vy * cos(deg);
        
        deg = 2*PI - (deg * PI /180);

        matrix transform(4, 4);
        transform.arr[0][0] = cos(deg);
        transform.arr[0][1] = -sin(deg);
        transform.arr[1][0] = sin(deg);
        transform.arr[1][1] = cos(deg);
        transform.arr[2][2] = 1;
        transform.arr[3][3] = 1;
        transform.arr[1][3] = uni;
        
        matrix res = transform^times;

        pos = res.mul(pos);
        cout << "desc " << pos[0] << " " << pos[1] << endl;
        
        // x += desc[0];
        // y += desc[1];
        
        // cur_rad += deg * times;
        // while(cur_rad > 2*PI) {
        //     int vezes = cur_rad/(2*PI);
        //     cur_rad -= vezes * 2 * PI;
        // }

        // v[0] = -sin(cur_rad);
        // v[1] = cos(cur_rad);
        // v[2] = 0;
        // v[3] = 1;

        // cout << "vai para " << x << " " << y << endl;
        // cout << "dire " << v[0] << " " << v[1] << endl;

        cout << endl;
        res.print();
        cout << endl;
    }

    cout << x << " " << y << endl;

    return 0;
}