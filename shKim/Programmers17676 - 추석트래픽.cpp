//
//  Programmers17676 - 추석트래픽.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/08.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<string> split(string &str){
    string temp = "";
    vector<string> v;
    for(int i=0;i<str.length()-1;i++){
        if(str[i] == ' '){
            v.push_back(temp);
            temp = "";
            continue;
        }
        temp += str[i];
    }
    v.push_back(temp);
    return v;
}
vector<string> split_time(string &str){
    string temp = "";
    vector<string> v;
    for(int i=0;i<str.length();i++){
        if(str[i] == ':'){
            v.push_back(temp);
            temp = "";
            continue;
        }
        temp += str[i];
    }
    v.push_back(temp);
    return v;
}
int solution(vector<string> lines) {
    int answer = 0;
    vector<pair<double,double>> info;
    for(int i=0;i<lines.size();i++){
        vector<string> all = split(lines[i]);
        vector<string> arrive = split_time(all[1]);
        double arrive_time = stoi(arrive[0]) * 3600.0 + stoi(arrive[1]) * 60.0 + stod(arrive[2]);
        double time = stod(all[2]);
        info.push_back({arrive_time-time+0.001,arrive_time});
        cout << arrive_time << endl;
        cout << stod(arrive[2]) << endl;
        printf("%.6f", stof(arrive[2]));
    }
    for(int i=0;i<info.size();i++){
        int temp = 0;
        double start = info[i].second;
        double dest = info[i].second + 1.0;
        cout << "===========" << endl;
        printf("%.6f\n",start);
        printf("%.6f\n",dest);
        cout << "===========" << endl;
        for(int j=0;j<info.size();j++){
            double c_start = info[j].first;
            double c_dest = info[j].second;
            printf("%.6f\n",c_start);
            printf("%.6f\n",c_dest);
            if(start >= c_start && dest <= c_dest)temp += 1;
            else if(c_dest > start && c_dest <= dest) temp += 1;
            else if(c_start >= start && c_start <= dest) temp+=1;
        }
        answer = max(answer,temp);
    }
    return answer;
}

int main(){
    cout << solution({"2016-09-15 01:00:04.001 2.0s", "2016-09-15 01:00:07.000 2s"}) << endl;
    return 0;
}
