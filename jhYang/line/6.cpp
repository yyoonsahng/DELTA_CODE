#include <string>
#include <vector>

using namespace std;
struct comp{
    string name;
    string pref;
    vector<string> cap;
    vector<string> res;
    vector<string> ref;
    int num;
};
struct appl{
    string name;
    string pref;
    int num;
};
vector<string> solution(vector<string> companies, vector<string> applicants) {
    vector<string> answer;
    vector<comp> arr;
    arr.resize(companies.size());
    vector<appl> me;
    me.resize(applicants.size());
    int appl_cnt = applicants.size();
    int comp_cnt = companies.size();
    
    for(int i = 0; i<companies.size(); i++){
        arr[i].name = companies[i].substr(0,1);
        arr[i].pref = companies[i].substr(2,appl_cnt);
        arr[i].num = atoi(companies[i].substr(3+appl_cnt,1).c_str());
    }
    for(int i = 0; i<arr.size(); i++){
        printf("%s %s %d\n",arr[i].name.c_str(),arr[i].pref.c_str(),arr[i].num);
    }
    for(int i = 0; i<applicants.size(); i++){
        me[i].name = applicants[i].substr(0,1);
        me[i].num = atoi(applicants[i].substr(3+comp_cnt,1).c_str());
        me[i].pref = applicants[i].substr(2,me[i].num);
    }
    for(int i = 0; i<me.size(); i++){
        printf("%s %s %d\n",me[i].name.c_str(),me[i].pref.c_str(),me[i].num);
    }
    for(int i = 0; i<me.size(); i++){
        for(int k = 0; k<me[i].pref.length(); k++){
            for(int j = 0; j<arr.size(); j++){
                if(me[i].pref.substr(k,1) == arr[j].name){
                    arr[j].cap.push_back(me[i].name);
                }
            }
        }
    }
    for(int i = 0; i<arr.size(); i++){
        for(int k = 0; k<arr[i].pref.length(); k++){
            int chk = 0;
            for(int j = 0; j<arr[i].cap.size()&&chk<arr[i].num; j++){
                if(arr[i].pref.substr(k,1) == arr[i].cap[j]){
                    arr[i].res.push_back(arr[i].cap[j]);
                    chk++;
                }
            }
        }
        for(int k = 0; k<arr[i].cap.size(); k++){
            int flag = 0;
            for(int j = 0; j<arr[i].res.size(); j++){
                if(arr[i].cap[k]==arr[i].res[j]){
                    flag = 1;
                }
            }
            if(flag == 0){
                for(int m = 0; m<appl_cnt; m++){
                    if(me[m].name == arr[i].cap[k]){
                        //delete appl's pref
                    }
                }
            }
        }
    }
    

    return answer;
}