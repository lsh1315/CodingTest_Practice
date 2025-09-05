#include <iostream>
#include <vector>
#include <queue>

using namespace std;

static vector<vector<int>> map;
static vector<vector<bool>> check;
static vector<int> ans;

int bfs(int n, int m, int y, int x){
    int i,j, nx, ny, ex, ey;
    queue<vector<int>> que;             // 자료구조만 queue -> stack 으로 바꿔주면 DFS
    vector<int> temp;                   // 물론 .front() -> .top()

    int cnt = 1;
    int dx[] = {-1,0,1,0};
    int dy[] = {0,-1,0,1};
    
    que.push({x,y});
    check[y][x] = true;
    while(!que.empty()){                 
        temp = que.front();
        que.pop();
        nx = temp[0];
        ny = temp[1];
        for(i=0; i<4; i++){
            ex = nx+dx[i];
            ey = ny+dy[i];
            if(ex>=0 && ex<m && ey>=0 && ey<n){
                if(map[ey][ex]==1 && !check[ey][ex]){
                    check[ey][ex] = true;
                    que.push({ex,ey});
                    cnt++;
                }
            }
        }
    }
    return cnt;
}

int answer(int n, int m){
    int i, j, cnt;
    int max = 0;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            if(map[i][j]==1 && !check[i][j]){
                cnt = bfs(n,m,i,j);
                ans.push_back(cnt);
                if(cnt>max)
                    max = cnt;
            }
        }
    }
    return max;
}

int main(){
    int n, m;
    cin >> n >> m;

    map.resize(n,vector<int>(m));
    check.resize(n,vector<bool>(m));

    // 입력 mapping
    int i,j;
    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    int max = answer(n,m);
    
    printf("%d\n%d\n", ans.size(), max);

    return 0;
}