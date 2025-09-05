#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>

using namespace std;

int main(){

	vector<int> vec = {1,8,3,4,5,7,2,5,8,3,6,10};
    priority_queue<string, vector<string>, greater<>> pq;
    
    pq.push("bqweofin");
    pq.push("cqefing");
    pq.push("awefdva");
    
	while(!pq.empty()){
        cout << pq.top() << endl;
        pq.pop();
    }

	sort(vec.begin(),vec.end(),greater<>());
	for(const auto& n : vec)
		cout << n << ' ';
	cout << '\n';

	return 0;
}