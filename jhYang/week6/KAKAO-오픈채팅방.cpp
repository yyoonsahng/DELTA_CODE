#include <string>
#include <vector>
#include <map>

using namespace std;

vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string, string> mymap;
    vector<pair<int,string> > msg;
    for(int i = 0; i<record.size(); i++){
        if(record[i].substr(0,5) == "Enter"){
            string uid = "";
            int idx = 6;
            while(record[i][idx]!=' '){
                uid+=record[i][idx];
                idx++;
            }
            string nickname = record[i].substr(idx+1,10);
            if(mymap.find(uid) == mymap.end())
                mymap.insert(make_pair(uid,nickname));
            else{
                mymap.find(uid)->second = nickname;
            }
            msg.push_back(make_pair(0,uid));
            //printf("%s %s\n",uid.c_str(),nickname.c_str());
        }
        else if(record[i].substr(0,5) == "Leave"){
            string uid = record[i].substr(6,10);
            msg.push_back(make_pair(1,uid));
        }
        else{
            string uid = "";
            int idx = 7;
            while(record[i][idx]!=' '){
                uid+=record[i][idx];
                idx++;
            }
            string nickname = record[i].substr(idx+1,10);
            mymap.find(uid)->second = nickname;
        }
    }
    for(int i = 0; i<msg.size(); i++){
        if(msg[i].first == 0){
            answer.push_back(mymap.find(msg[i].second)->second+"님이 들어왔습니다.");
        }
        else{
            answer.push_back(mymap.find(msg[i].second)->second+"님이 나갔습니다.");
        }
    }
    
    return answer;
}