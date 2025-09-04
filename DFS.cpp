#include<iostream>
#include<vector>
#include<string>
#include<algorithm>

using namespace std;

static int n;
static vector<vector<int>> map;
static vector<vector<int>> check;

void dfs(int x, int y, int* cnt){
    int dx[] = {-1, 0, 1, 0};
    int dy[] = {0, -1, 0, 1};

    check[y][x] = 1;
    (*cnt)++;

    int ex, ey;
    for(int i=0; i<4; i++){
        ex = x+dx[i];
        ey = y+dy[i];
        if(ex>=0 && ex<n && ey>=0 && ey<n){
            if(map[ey][ex]==1 && check[ey][ex]==0){
                dfs(ex,ey,cnt);
            }
        }
    }
}

void answer(){
    vector<int> arr;
    int i, j, cnt=0;
    
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            if(map[i][j]==1 && check[i][j]==0){
                dfs(j,i,&cnt);
                arr.push_back(cnt);
                cnt = 0;
            }
        }
    }

    sort(arr.begin(), arr.end());

    printf("%ld\n", arr.size());
    for(i=0; i<arr.size(); i++){
        printf("%d\n", arr[i]);
    }
}

int main(){
    int i, j;

    cin >> n;
    string str;

    map.resize(n,vector<int>(n));
    check.resize(n,vector<int>(n));

    for(i=0;i<n;i++){
        cin >> str;
        for(j=0;j<str.size();j++){
            map[i][j] = str[j]-'0';
        }
    }

    // printf("\n\n<<<< answer >>>>\n");
    answer();
    
    // printf("\n\n<<<< map >>>>\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<n;j++){
    //         printf("%d ",map[i][j]);
    //     }
    //     printf("\n");
    // }

    // printf("\n\n<<<< check >>>>\n");
    // for(i=0;i<n;i++){
    //     for(j=0;j<n;j++){
    //         printf("%d ",check[i][j]);
    //     }
    //     printf("\n");
    // }

    return 0;
}