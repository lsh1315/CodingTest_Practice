#include<iostream>
#include<string>
#include<vector>
#include<queue>

using namespace std;

static vector<priority_queue<vector<int>>> att;

int main(int argc, char** argv)
{
	string str = "45673";
    printf("%d\n",stoi(str));
	return 0;
}