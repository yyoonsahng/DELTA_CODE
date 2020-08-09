//
//  Programmers17678 - 셔틀버스.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/09.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int cal_total(string str){
    vector<string> v;
    string temp = "";
    for(int i=0;i<str.length();i++){
        if(str[i] ==':'){
            v.push_back(temp);
            temp = "";
        }else{
            temp += str[i];
        }
    }
    v.push_back(temp);
    return 60 * stoi(v[0]) + stoi(v[1]);
}
string convert(int n){
    string hour = to_string(n/60);
    string min = to_string(n%60);
    if(hour.size() == 1) hour = "0"+hour;
    if(min.size() == 1) min = "0"+min;
    return hour+":"+min;
}
string solution(int n, int t, int m, vector<string> timetable){
    string answer = "";
    int hour = 9;
    int min = 0;
    int last_time = -1;
    int last_shuttle = 0;
    int seat = 0;
    sort(timetable.begin(),timetable.end());
    for(int i=0;i<n;i++){
        int total = hour * 60 + min;
        seat = 0;
        for(int j=0;j<timetable.size();j++){
            if(timetable[j] == "*") continue;
            if(seat == m) break;
            if(total >= cal_total(timetable[j])){
                seat++;
                last_time = max(last_time,cal_total(timetable[j]));
                timetable[j] = "*";
            }
        }
        min += t;
        if(min >= 60){
            min -= 60;
            hour += 1;
        }
        last_shuttle = max(last_shuttle,total);
    }
    int ans = 0;
    if(last_time == -1 || seat < m){
        ans = last_shuttle;
    }else{
        ans = last_time - 1;
    }
    return convert(ans);
}
int main(){
    cout << solution(2, 10, 2, {"09:10", "09:09", "08:00"});
    return 0;
}
