#include<iostream>
#include<algorithm>
#include<queue>
#include<vector>

using namespace std;

static vector<vector<int>> map;
static vector<vector<int>> energy;
static vector<vector<bool>> check;
static priority_queue<vector<int>> group;
static vector<priority_queue<vector<int>>> att;
static int dx[] = {0,0,-1,1};
static int dy[] = {-1,1,0,0};

int R21(char c){
    if(c == 'R') return 1;
    else if(c == 'G') return 2;
    else if(c == 'B') return 3;
    return 0;
}

void dfs(int n, int color, int y, int x){
    int ex, ey;

    check[y][x] = true;
    group.push({energy[y][x], -y, -x});

    for(int i=0; i<4; i++){
        ex = x+dx[i];
        ey = y+dy[i];
        if(ex>=0 && ex<n && ey>=0 && ey<n){
            if(map[ey][ex]==color && !check[ey][ex]){
                dfs(n, color, ey, ex);
            }
        }
    }

}

int chclr(int a, int b){
    if(a==7 || b==7) return 7;
    int g = max(a,b);
    int l = min(a,b);
    if(g==6){
        if(l==1 || l==2) return 6;
        else return 7;
    }else if(g==5){
        if(l==1 || l==3) return 5;
        else return 7;
    }else if(g=4){
        if(l==2 || l==3) return 4;
        else return 7;
    }else if(g=3){
        if(l=2) return 3;
        else return 4;
    }else return 5;
}

void razer(int n, int e, int x, int y){
    int ex = x;
    int ey = y;
    int power = e-1;
    int dir = e%4;
    energy[y][x] = 1;       // 공격하고 나서의 에너지가 기억이 안나네네
    while(power!=0){
        ex += dx[dir];
        ey += dy[dir];
        if(ex<0 || ex>=n || ey<0 || ey>=n) break;

        if(map[ey][ex] == map[y][x]) continue;
        else{
            if(power>energy[ey][ex]){
                power -= ++energy[ey][ex];
                map[ey][ex]=map[y][x];
            }
            else{
                energy[ey][ex] += power;
                map[ey][ex] = chclr(map[y][x],map[ey][ex]);
                power = 0;
            }
        }
    }
}

int main(){
    int test_case, T;

    cin >> T;
    for (test_case=1; test_case<=T; test_case++){
        int i,j,clr,s,x,y,e;
        char c;
        vector<int> temp;
        vector<int> RGB;

        int n, k;
        cin >> n >> k;

        // clear and resize
        map.clear();
        map.resize(n,vector<int>(n));
        energy.clear();
        energy.resize(n,vector<int>(n));

        // 입력
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cin >> c;
                map[i][j] = R21(c);
            }
        }
        for(i=0; i<n; i++){
            for(j=0; j<n; j++){
                cin >> energy[i][j];
            }
        }

        // k턴 반복
        for (int t=0; t<k; t++){
            // 매 턴 초기화
            check.clear();
            check.resize(n,vector<bool>(n));
            att.clear();
            att.resize(3);
            RGB.clear();
            RGB.resize(8);

            // 1. 전체 +1
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    energy[i][j]++;
                }
            }

            // 2. 공격군 선정
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    if(!check[i][j]){
                        clr = map[i][j];
                        dfs(n,clr,i,j);
                        s = group.size();
                        temp = group.top();
                        group.pop();
                        e = temp[0];
                        y = -temp[1];
                        x = -temp[2];
                        energy[y][x] += s-1;
                        e = energy[y][x];
                        if(clr<4){
                            att[0].push({e,-y,-x});
                        }else if(clr>=4 && clr<7){
                            att[1].push({e,-y,-x});
                        }else if(clr==7){
                            att[2].push({e,-y,-x});
                        }
                        while(!group.empty()){
                            temp = group.top();
                            group.pop();
                            y = -temp[1];
                            x = -temp[2];
                            energy[y][x]--;
                        }
                    }
                }
            }

            // 3. 레이저 발사
            for(i=0; i<3; i++){
                while(!att[i].empty()){
                    temp = att[i].top();
                    att[i].pop();
                    e = temp[0];
                    y = -temp[1];
                    x = -temp[2];
                    if (energy[y][x] != e) continue;        // 여기서 틀린거 같네

                    razer(n, e, x, y);
                }
            }

            // 4. 관찰
            for(i=0; i<n; i++){
                for(j=0; j<n; j++){
                    
                    clr = map[i][j];
                    RGB[clr]++;
                }
            }
            printf("T%d %d %d %d %d %d %d %d ", t+1, RGB[7],RGB[4],RGB[5],RGB[6],RGB[1],RGB[2],RGB[3]);
        }
        printf("\n");
    }

    return 0;
}