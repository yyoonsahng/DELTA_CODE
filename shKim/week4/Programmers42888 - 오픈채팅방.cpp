//
//  Programmers42888 - 오픈채팅방.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/30.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<string> answer_id;
    vector<string> answer_state;
    map<string,string> id_nickname;
    for(int i=0;i<record.size();i++){
        // MARK:- 문자열 처리 부분. 상태/uuid/닉네임을 구분
        vector<string> info;
        string temp = "";
        for(int j=0;j<record[i].size();j++){
            if(record[i][j] == ' '){
                info.push_back(temp);
                temp = "";
                continue;
            }
            temp += record[i][j];
        }
        info.push_back(temp);
        
        // MARK:- Record 처리. enter와 change,leave를 구별
        string state = info[0];
        if(state == "Enter"){
            string uuid = info[1];
            string nickname = info[2];
            if(id_nickname.find(uuid) == id_nickname.end()) id_nickname.insert({uuid,nickname});
            else id_nickname[uuid] = nickname;
            answer_id.push_back(uuid);
            answer_state.push_back("님이 들어왔습니다.");
        }
        else if(state == "Leave"){
            string uuid = info[1];
            answer_id.push_back(uuid);
            answer_state.push_back("님이 나갔습니다.");
        }
        else if(state == "Change"){
            string uuid = info[1];
            string nickname = info[2];
            id_nickname[uuid] = nickname;
        }
        
    }
    
    for(int i=0;i<answer_state.size();i++) answer.push_back(id_nickname[answer_id[i]] + answer_state[i]);
    return answer;
}

int main(){

    vector<string> a = solution({"Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan"});
    for(int i=0;i<a.size();i++){
        cout << a[i] << endl;
    }
}
