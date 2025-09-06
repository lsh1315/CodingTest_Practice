/*------------------------------
1. 아이디어
- 백트래킹, 재귀함수
- 배열의 마지막 수보다 큰 수만 넣기 ( index 0 에 0 값 )
- M개일때 출력, 배열의 마지막 수가 N일때 return -> 돌아와서 마지막 값 빼주기
2. 시간복잡도
- N! 
3. 자료구조
- vector<int> ans(n) : 조합을 담을 배열
-------------------------------*/

#include<iostream>
#include<vector>

using namespace std;

vector<int> ans;

void recur(int n, int m, int idx){
    int i;
    if(ans.size() == m){
        for(i=0;i<m;i++){
            printf("%d ",ans[i]);
        }
        printf("\n");
        return;
    }

    for(i=idx; i<=n; i++){
        ans.push_back(i);
        recur(n,m,i+1);
        ans.pop_back();
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    recur(n,m,1);

    return 0;
}