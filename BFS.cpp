#include <iostream>
#include <queue>
#include <array>

using namespace std;

int bfs(int **map, bool* check, int sx, int sy, int x, int y){
    std::queue<std::array<int,2>> q;
    q.push({y,x});
    check[y*sx+x] = true;

    int nx, ny;
    int dx[] = {-1,0,1,0};
    int dy[] = {0,-1,0,1};

    int cnt = 1;

    while(!q.empty()){
        std::array<int,2> v = q.front();
        q.pop();
        int ex = v[1];
        int ey = v[0];
        
        for(int i=0; i<4; i++){
            nx = ex + dx[i];
            ny = ey + dy[i];

            if(nx<sx && nx>=0 && ny<sy && ny>=0 ){
                if(map[ny][nx]==1 && check[ny*sx+nx]==false){
                    cnt++;
                    q.push({ny,nx});
                    check[ny*sx+nx] = true;
                }
            }
        }
    }
    return cnt;
}

int answer(int **map, int sx, int sy){
    int i, j;
    bool *check = (bool*)calloc(sx*sy, sizeof(bool));    
    int max = 0;
    int temp;

    for(i=0; i<sy; i++){
        for(j=0; j<sx; j++){
            if(check[i*sx+j]== false && map[i][j] == 1){
                temp = bfs(map, check, sx, sy, j, i);
                if (temp > max) max = temp;
            }
        }
    }

   free(check);
   return max;
}

int main () {
    int n, m;
    int i, j;

    cin >> n >> m;

    // vector<vector<int>> map(n, vector<int>(m));
    int **map = (int**)malloc(sizeof(int*)*n);
    for(int i=0; i<n; i++){
        map[i] = (int*)malloc(sizeof(int)*m);
    }

    for(i=0; i<n; i++){
        for(j=0; j<m; j++){
            cin >> map[i][j];
        }
    }

    printf("%d\n", answer(map,5,6));

    for(int i=0; i<n; i++){
        free(map[i]);
    }
    free(map);

    return 0;
}