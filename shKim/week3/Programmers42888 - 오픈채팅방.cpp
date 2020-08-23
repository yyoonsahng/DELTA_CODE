//
//  Programmers42888 - 오픈채팅방.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/23.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <string>
#include <vector>
#include<map>
#include<iostream>
using namespace std;
vector<string> solution(vector<string> record) {
    vector<string> answer;
    vector<pair<int, string>> in_out;
    map<string, string> id_nick;
    for (int i = 0; i < record.size(); i++) {
        string temp = "";
        int count = 0;
        int state = -1; //string을 보고 상태값을 지정
        string id = "";
        string nick_name = "";
        for (int j = 0; j < record[i].length(); j++) {
            if (record[i][j] != ' ') {
                temp = temp + record[i][j];
            }
            else {
                if (count == 0) {
                    if (temp == "Enter") state = 0;
                    else if (temp == "Leave") state = 1;
                    else if (temp == "Change") state = 2;
                }
                else if (count == 1) id = temp;
                temp = "";
                count++;
            }
            if (j == record[i].length() - 1) {
                nick_name = temp;
            }
        }
        //cout << state << " " << id << " " <<nick_name << endl;
        if (state == 0) {
            if (id_nick.find(id) != id_nick.end()) { //발견했으면
                id_nick.erase(id);
            }
            id_nick.insert(make_pair(id, nick_name));
            in_out.push_back(make_pair(state, id));
        }
        if (state == 1) {
            in_out.push_back(make_pair(state, nick_name));
        }
        else if (state == 2) {
            if (id_nick.find(id) != id_nick.end()) { //발견했으면
                id_nick.erase(id);
            }
            id_nick.insert(make_pair(id, nick_name));
        }
    }
    for (int i = 0; i < in_out.size(); i++) {
        if (in_out[i].first == 0) {
            map<string, string>::iterator iter = id_nick.find(in_out[i].second);
            answer.push_back(iter->second + "님이 들어왔습니다.");
        }
        else if (in_out[i].first == 1) {
            map<string, string>::iterator iter = id_nick.find(in_out[i].second);
            answer.push_back(iter->second + "님이 나갔습니다.");
        }
    }
    return answer;
}
