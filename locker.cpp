/*----------------------
1. 아이디어
- N/4번 vector rotate -> N/4개씩 끊어 읽기 ( 4번 )
- 각각을 16진수 -> 10진수 변환 후, 배열에 저장
- sorting 이후 cnt 해가며 출력
2. 시간복잡도
- N^2 << 900 
3. 자료구조
- vector<char> arr : rotate 시킬 배열
- vector<char> side : 끊어 읽을 배열
- vector<int> ans : 10진수 저장
-----------------------*/

#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

static vector<char> arr ;
static vector<char> side;
static vector<int> ans;
static vector<int> cnt;

int x2i (char a){
    int result = 0;
    if(a>='0' && a<='9') result = a-'0';
    else if(a>='A' && a<='F') result = a-'A'+10;
    return result;
}

int func(int r){
    int i, j, x;
    int result = 0;
    for( i=0; i<r; i++){
        x = 1;
        for(j=0; j<i; j++){
            x *= 16;
        }
     	result += x2i(side[r-1-i])*x;
    }
    return result;
}

int main(int argc, char** argv)
{
	int test_case;
	int T;
	
	cin>>T;

	for(test_case = 1; test_case <= T; ++test_case)
	{
		int n,k;
        cin >> n >> k;
        
        arr.clear();
        ans.clear();
        cnt.clear();

        int i,j,p;
        char temp;
        for(i=0; i<n; i++){
            cin >> temp;
            arr.push_back(temp);
        }

        int r = n/4;
        for(i=0; i<r; i++){
            rotate(arr.begin(),arr.begin()+1,arr.end());
        	for(j=0; j<4; j++){
                side.clear();
            	for(p=0; p<r; p++){
                 	side.push_back(arr[j*r+p]);
                }
                ans.push_back(func(r));
            }
       	}
       	sort(ans.begin(), ans.end(), greater<int>());
		ans.erase(unique(ans.begin(), ans.end()), ans.end());

		printf("#%d %d\n", test_case, ans[k-1]);
	}

	return 0;
}