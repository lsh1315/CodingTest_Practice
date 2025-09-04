/*-----------------
1. 아이디어
- 백트래킹, 재귀함수를 이용. 방문여부를 확인해서 순차적으로 방문( 매 재귀함수를 종료할때 마지막 값 빼주기 )
2. 시간복잡도
- N!
3. 자료구조 
- vector<int> ans : push_back 과 pop 이용
- vectpr<int> check
-------------------*/

#include<iostream>
#include<vector>

using namespace std;

static vector<int> ans;
static vector<bool> check;

void recur(int n, int m){
    int i;
    if (ans.size() == m){
        for(i=0; i<m; i++){
            printf("%d ", ans[i]);
        }
        printf("\n");
        return;
    }
    for(i=1; i<=n; i++){
        if(check[i] == false){
            check[i] = true;
            ans.push_back(i);
            recur(n,m);
            check[i] = false;
            ans.pop_back();
        }
    }
}

int main(){
    int n, m;
    cin >> n >> m;

    check.resize(n+1);

    recur(n,m);

    return 0;
}