#include<iostream>
#include<vector>

using namespace std;

typedef struct _sel{
    bool act = false;
    int life = 0;
    int cnt = 0;
}sel;

static vector<vector<sel>> map;

int ans(int k, int n, int m){
    int i,j,d;
    int aliv = 0;

    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};
    int x,y;

    for(int s=0; s<k; s++){
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if(map[i][j].life != 0){
                    if(--map[i][j].cnt == 0 && !map[i][j].act){     // 모든 세포 cnt--; 
                        map[i][j].cnt = map[i][j].life;
                        map[i][j].act = true;
                    }     
                }       
            }
        }
        for(i=0;i<n;i++){
            for(j=0;j<m;j++){
                if (map[i][j].life != 0){
                    if(map[i][j].act && map[i][j].cnt == map[i][j].life -1){      // 한시간 전에 활성화된 세포
                        for(d=0;d<4;d++){
                            x = j+dx[d];
                            y = i+dy[d];
                            if(x>=0 && x<n && y>=0 && y<m){
                                if(map[y][x].cnt == map[y][x].life && !map[y][x].act){      // 비활성화 and cnt = life : 새친구 or 빈공간
                                    map[y][x].life = max(map[y][x].life, map[i][j].life);
                                    map[y][x].cnt = map[y][x].life;
                                }
                            }
                        }
                    }
                } 
            }
        }
    }
    
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            if(map[i][j].life>0 && map[i][j].cnt>0) aliv++;
        }
    }
    return aliv;
}

int main(){
    int i,j;
    int t, n, m, k;
    int ns, ms;
    cin >> t;
    for(int s=0; s<t; s++){
        cin >> n >> m >> k;
        ns = n+k+k/2;
        ms = m+k+k/2;
        map.clear();
        map.resize(ns,vector<sel>(ms));
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                cin >> map[k/2+k/4+i][k/2+k/4+j].life;
                map[k/2+k/4+i][k/2+k/4+j].cnt = map[k/2+k/4+i][k/2+k/4+j].life;
            }
        }
        printf("#%d %d\n", s+1, ans(k,ns,ms));
    }

   return 0;
}