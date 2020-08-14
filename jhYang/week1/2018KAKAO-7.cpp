//추석트래픽

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cmath>
using namespace std;

// (종료시간,시작시간)
pair<int,int> getTime(string str){
    string temp = str.substr(11,30);
    string s1 = temp.substr(0,temp.find(" "));
    string s2 = temp.substr(temp.find(" ")+1,10);
    int time = atoi(s1.substr(0,2).c_str())*60*60+
                atoi(s1.substr(3,2).c_str())*60+
                atoi(s1.substr(6,2).c_str());
    time = time*1000+atoi(s1.substr(9,3).c_str());

    int time2 = atoi(s2.substr(0,1).c_str())*1000
                +atoi(s2.substr(2,s2.find("s")-2).c_str())*pow(10,6-s2.length());
    return make_pair(time,time2);
}

int solution(vector<string> lines) {
    //시작시간 배열
    vector<int> s;
    //시작시간 정렬 배열
    vector<pair<int,int> > v;
    for(int i = 0; i<lines.size(); i++){
        int y,m,d,hh,mm,ss,sss;
        double t;
        sscanf(lines[i].c_str(),"%d-%d-%d %d:%d:%d.%d %lfs",&y,&m,&d,&hh,&mm,&ss,&sss,&t);
        int t1 = (hh*60*60+mm*60+ss)*1000+sss;
        int t2 = t*1000;
        v.push_back(make_pair(t1-t2+1,t1));
        s.push_back(t1-t2+1);
        // pair<int,int> temp = getTime(lines[i]);
        // v.push_back(make_pair(temp.first-temp.second+1,temp.first));
        // s.push_back(temp.first-temp.second+1);
    }
    sort(v.begin(),v.end());
    int mmax = 0;
    for(int i = 0; i<s.size(); i++){
        int cnt = 0;
        for(int j = 0; j<v.size(); j++){
            if(v[j].first<=s[i] && v[j].second>=s[i]-1000+1){
                cnt++;
            }
        }  
        mmax = max(mmax,cnt);
    }
    int answer = mmax;
    return answer;
}
int main(){
    vector<string> lines;
    lines.push_back("2016-09-15 01:00:04.001 2.0s");
    lines.push_back("2016-09-15 01:00:07.000 2s");
    // lines.push_back("2016-09-15 20:59:57.421 0.351s");
    // lines.push_back("2016-09-15 20:59:58.233 1.181s");
    // lines.push_back("2016-09-15 20:59:58.299 0.8s");
    // lines.push_back("2016-09-15 20:59:58.688 1.041s");
    // lines.push_back("2016-09-15 20:59:59.591 1.412s");
    // lines.push_back("2016-09-15 21:00:00.464 1.466s");
    // lines.push_back("2016-09-15 21:00:00.741 1.581s");
    // lines.push_back("2016-09-15 21:00:00.748 2.31s");
    // lines.push_back("2016-09-15 21:00:00.966 0.381s");
    // lines.push_back("2016-09-15 21:00:02.066 2.62s");
    cout<<solution(lines);
}