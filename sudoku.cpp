#include <iostream>
#include <vector>

using namespace std;

static vector<vector<int>> map(9,vector<int>(9));

void backTracking(){
    
}

int main(){

    int i,j;
    for(i=0; i<9; i++){
        for(j=0; j<10; j++){
            cin >> map[i][j];
        }
    }

    backTracking();

    for(i=0; i<9; i++){
        for(j=0; j<9; j++){
            printf("%d ", map[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}