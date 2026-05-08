#include <bits/stdc++.h>

using namespace std;

#define _ ios_base::sync_with_stdio(0);cin.tie(0);
#define endl '\n'
#define ff first
#define ss second

typedef long long ll;

const int INF = 0x3f3f3f3f;
const ll LINF = 0x3f3f3f3f3f3f3f3fll;

int main() { 
    int n,m,t;
    cin >> n >> m >> t;

    string v[n];
    for(int i=0;i<n;i++) cin >> v[i];

    int dist[n][m][3][3][3][3][1<<8];
    for(int i=0;i<n;i++) for(int j=0;j<m;j++) for(int k=0;k<3;k++) {
        for(int i2=0;i2<3;i2++) for(int j2=0;j2<3;j2++) for(int k2=0;k2<3;k2++) {
            for(int slaporra = 0;slaporra < (1<<8);slaporra++) dist[i][j][k][i2][j2][k2][slaporra] = INT_MAX;
        }
    }

    queue<array<int,7>> q;
    map<pair<int,int>,int> portas;

    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if('C'==v[i][j] or 'D'==v[i][j] or 'H'==v[i][j] or 'S'==v[i][j]) portas[pair(i,j)] = portas.size();
            else if(v[i][j]=='I') {
                q.push({i,j,0,0,0,0,(1<<8)-1});
                dist[i][j][0][0][0][0][(1<<8)-1]=0;
            }
        }
    }

    pair<int,int> vd[] = {{0,1},{0,-1},{1,0},{-1,0}};

    while(q.size()) {
        auto [x,y,c1,c2,c3,c4,p] = q.front();
        q.pop();

        //println("\npop {} {} {} {} {} {} {}, dist {}",x,y,c1,c2,c3,c4,p,dist[x][y][c1][c2][c3][c4][p]);

        if(v[x][y]=='E') {
            cout << dist[x][y][c1][c2][c3][c4][p] << '\n';
            return 0;
        }


        
        int d = dist[x][y][c1][c2][c3][c4][p];
        
        for(auto [xx,yy]:vd) {
            int x2 = x+xx,y2 = y+yy;
            
            if(x2<0 or x2>=n or y2<0 or y2>=m or v[x2][y2]=='#') continue; // invalido ou obstaculo
            char l = v[x2][y2];
            
            int c[4] = {c1,c2,c3,c4};

            if(l=='.' or l=='I' or l=='E') {
                if(dist[x2][y2][c1][c2][c3][c4][p]>d+1) {
                    dist[x2][y2][c1][c2][c3][c4][p] = d+1;
                    q.push({x2,y2,c1,c2,c3,c4,p});
                    //println("push {} {} {} {} {} {} {}, dist {}",x2,y2,c1,c2,c3,c4,p,dist[x2][y2][c1][c2][c3][c4][p]);
                }
            } else if(l=='c' or l=='d' or l=='h' or l=='s') { // chaves
                int id;
                if(l=='c') id = 0;
                else if(l=='d') id = 1;
                else if(l=='h') id = 2;
                else id = 3;

                if(dist[x2][y2][c1][c2][c3][c4][p]>d+1) { // sem pegar a chave
                    dist[x2][y2][c1][c2][c3][c4][p] = d+1;
                    q.push({x2,y2,c1,c2,c3,c4,p});
                    //println("push {} {} {} {} {} {} {}, dist {}",x2,y2,c1,c2,c3,c4,p,dist[x2][y2][c1][c2][c3][c4][p]);

                }

                if(c[id]==0) {
                    int qtd = 0;
                    for(int i:c) if(i==1) qtd++;
                    if(qtd==t) continue;
                    
                    // pegando a chave
                    // if(id==0) c1 = 1;
                    // else if(id==1) c2 = 1;
                    // else if(id==2) c3 = 1;
                    // else c4 = 1;
                    c[id] = 1;

                    if(dist[x2][y2][c[0]][c[1]][c[2]][c[3]][p]>d+1) {
                        dist[x2][y2][c[0]][c[1]][c[2]][c[3]][p] = d+1;
                        q.push({x2,y2,c[0],c[1],c[2],c[3],p});
                        //println("push {} {} {} {} {} {} {}, dist {}",x2,y2,c[0],c[1],c[2],c[3],p,dist[x2][y2][c[0]][c[1]][c[2]][c[3]][p]);
                    }
                }
            } else if('C'==l or l=='D' or l=='H' or l=='S') { // porta
                int porta = portas.at(pair(x2,y2));

                int id;
                if(l=='C') id = 0;
                else if(l=='D') id = 1;
                else if(l=='H') id = 2;
                else id = 3;

                if(((p&(1<<porta))==0) or c[id]==1) { // já tá aberta ou tenho a chave
                    int mask = p;
                    if(p&(1<<porta)) mask-=1<<porta;

                    if(dist[x2][y2][c1][c2][c3][c4][mask]>d+1) {
                        dist[x2][y2][c1][c2][c3][c4][mask] = d+1;
                        q.push({x2,y2,c1,c2,c3,c4,mask});
                        //println("push {} {} {} {} {} {} {}, dist {}",x2,y2,c1,c2,c3,c4,mask,dist[x2][y2][c1][c2][c3][c4][mask]);
                    }
                } else continue; // tá fechada e não tenho a chabe
            } else if(l=='B') { // baú
                vector<int> to_chest,to_hand;

                int mh=0,mb=0;
                for(int i=0;i<4;i++) {
                    if(c[i]==1) mh+=(1<<i);
                    else if(c[i]==2) mb+=(1<<i);
                }

                for(int mk=mh;;mk = mh&(mk-1)) {
                    to_chest.push_back(mk);
                    if(mk==0) break;
                }

                for(int mk=mb;;mk = mb&(mk-1)) {
                    to_hand.push_back(mk);
                    if(mk==0) break;
                }

                int qhand = 0;
                for(int i=0;i<4;i++) if(c[i]==1) qhand++;

                for(auto a:to_chest) {
                    int qa = 0;
                    for(int i=0;i<4;i++) if(a&(1<<i)) qa++;
                    
                    for(int b:to_hand) {
                        int qb=0;
                        
                        for(int i=0;i<4;i++) if(b&(1<<i)) qb++;

                        if(qhand-qa+qb<=t) {
                            int nc[4];
                            for(int i=0;i<4;i++) {
                                if(c[i]==0) nc[i] = 0;
                                else if(c[i]==1) {
                                    if(a&(1<<i)) nc[i] = 2;
                                    else nc[i] = 1;
                                } else {
                                    if(b&(1<<i)) nc[i] = 1;
                                    else nc[i] = 2;
                                }
                            }

                            int &dn = dist[x2][y2][nc[0]][nc[1]][nc[2]][nc[3]][p];

                            if(dn>d+1) {
                                dn = d+1;
                                q.push({x2,y2,nc[0],nc[1],nc[2],nc[3],p});
                                //println("push {} {} {} {} {} {} {}, dist {}",x2,y2,nc[0],nc[1],nc[2],nc[3],p,dist[x2][y2][nc[0]][nc[1]][nc[2]][nc[3]][p]);

                            }
                        }
                    }
                }
            } else assert(false);
        }
    }

    cout << -1 << '\n';
    return 0;
}