/*-------------------------
1. 아이디어
- 벽 3개 조합(백트래킹), DFS 오염
2. 시간복잡도
- (N*M)^2 < 2^12 = 4096 -> 가능
3. 자료구조
- vector<int> map : 연구실
- vector<vector<int>> wall_set : 4*3*64C3 < 2^19 (byte) < 2MB
- vector<int> wall : 벽 buffer
--------------------------*/
#include<iostream>
#include<vector>

using namespace std;

static vector<vector<int>> map;
static vector<vector<int>> map_copy;
static vector<vector<int>> wall_set;
static vector<vector<int>> check;
static vector<int> wall;

void make_wall(int n, int m, int k){
    int i,j;
    int x,y;
    if(wall.size()==3){
        wall_set.push_back(wall);
        return;
    }
    for(i=k+1; i<n*m; i++){
        y = i/m;
        x = i%m;
        if(map[y][x]==0){
            wall.push_back(i);
            make_wall(n,m,i);
            wall.pop_back();
        }
    }
    return;
}

void spread(int n, int m, int x, int y){
    int i,j;
    int dx[] = {-1,0,1,0};
    int dy[] = {0,-1,0,1};
    int ex, ey;
    for(i=0; i<4; i++){
        ex = x + dx[i];
        ey = y + dy[i];
        if(ex>=0 && ex<m && ey>=0 && ey<n){
            if(map_copy[ey][ex]==0){
                map_copy[ey][ex]=2;
                check[ey][ex]=1;
                spread(n,m,ex,ey);
            }
        }
    }
    return;
}

int answer(int n, int m){
    int i,j,x,y;
    int max = 0;

    while(!wall_set.empty()){
        map_copy = map;
        wall = wall_set.back();
        wall_set.pop_back();

        for(i=0; i<3; i++){
            y = wall[i]/m;
            x = wall[i]%m;
            map_copy[y][x]=1;
        }

        check.clear();
        check.resize(n,vector<int>(m));
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(map_copy[i][j]==2 && check[i][j] == 0){
                    check[i][j] = 1;
                    spread(n,m,j,i);
                }
            }
        }
       
        int cnt=0;
        for(i=0; i<n; i++){
            for(j=0; j<m; j++){
                if(map_copy[i][j]==0){
                    cnt++;
                }
            }
        }
        if(cnt>max){
            max = cnt;
        }
    }

    return max;
}

int main(){
    int n, m;
    cin >> n >> m;

    map.resize(n,vector<int>(m));
    
    int i, j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    make_wall(n, m, -1);

    printf("%d\n", answer(n,m));

    return 0;
}