#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static vector<vector<int>> map;
static vector<vector<bool>> check;
static vector<int> ans;
static int cnt;

void dfs(int n, int y, int x){
	int i,j,ex,ey;
	
	int dx[] = {-1, 0, 1, 0};
	int dy[] = {0, -1, 0, 1};

	for(i=0; i<4; i++){
		ex = x + dx[i];
		ey = y + dy[i];
		if(ex>=0 && ex<n && ey>=0 && ey<n){
			if(map[ey][ex]==1 && !check[ey][ex]){
				check[ey][ex]=true;						// 매 check를 언제 할건지 정해야된다
				cnt++;
				dfs(n,ey,ex);
			}
		}
	}
}

void answer(int n){
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			if(map[i][j]==1 && !check[i][j]){
				cnt = 1;
				check[i][j] = true;					// 매 check를 언제 할건지 정해야된다
				dfs(n,i,j);							// 재귀함수 호출 직전 or 재귀함수 시작 하면서
				ans.push_back(cnt);
			}
		}
	}
}

int main(){
	int n;
	char temp;

	cin >> n;
	map.resize(n, vector<int>(n));
	check.resize(n, vector<bool>(n));

	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			cin >> temp;					// 공백 없이 들어오는 정수 끊어 읽기
			map[i][j] = temp - '0';
		}
	}

	answer(n);
	
	sort(ans.begin(),ans.end());

	int s = ans.size();
	printf("%d\n", s);
	for(int i=0; i<s; i++){
		printf("%d\n",ans[i]);
	}
	
	return 0;
}