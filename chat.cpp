#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
#include<sstream>

using namespace std;

vector<string> solution (vector<string> record){
    vector<string> answer;
    unordered_map<string, string> idmap;

    for(vector<string>::iterator it = record.begin(); it != record.end(); it++){
        stringstream ss(*it);
        string cmd, id, name;
        ss >> cmd;
        if (cmd.compare("Enter") == 0){
            ss >> id >> name;
            idmap[id] = name;
        }else if(cmd.compare("Change") == 0 ){
            ss >> id >> name;
            idmap[id] = name;
        }
    }
    
    for(vector<string>::iterator it = record.begin(); it != record.end(); it++){
        stringstream ss(*it);
        string cmd, id, name;
        ss >> cmd;
        if (cmd.compare("Enter") == 0){
            ss >> id;
            answer.push_back(idmap[id]+"님이 들어왔습니다.");
        }else if(cmd.compare("Leave") == 0 ){
            ss >> id;
            answer.push_back(idmap[id]+"님이 나갔습니다.");
        }
    }

    return answer;
}

int main(){
    vector<string> str  = {"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"};
    vector<string> ans = solution(str);
    for(vector<string>::iterator it = ans.begin(); it != ans.end(); it++ ){
        cout << *it << endl;
    }
}