#include <string>
#include <vector>
#include <deque>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> info, vector<string> query) {
    vector<int> answer;
    vector<long long> myuser;
    for(int i = 0; i<info.size(); i++){
        int flag = 0;
        long long uid = 0;
        long long uval = 0;
        string lang="";
        string bf="";
        string js="";
        string cp="";
        string val="";
        int j = 0;
        char temp = info[i][j];
        while(j<=info[i].length()){ 
            temp = info[i][j];
            if(temp == ' '){
                flag++;
                j++;
                continue;
            }
            if(flag == 0){
                lang+=temp;
            }
            else if(flag == 1){
                bf+=temp;
            }
            else if(flag ==2){
                js+=temp;
            }
            else if(flag == 3){
                cp+=temp;
            }
            else if(flag == 4){
                val+=temp;
            }
            j++;
        }
        //printf("%s %s %s %s %s\n",lang.c_str(),bf.c_str(),js.c_str(),cp.c_str(),val.c_str());
        if(lang == "cpp"){
            uid+=1000;
        }
        else if(lang == "java"){
            uid+=2000;
        }
        else{
            uid+=3000;
        }
        if(bf == "backend"){
            uid+=100;
        }
        else{
            uid+=200;
        }
        if(js == "junior"){
            uid+=10;
        }
        else{
            uid+=20;
        }
        if(cp =="chicken"){
            uid+=1;
        }
        if(cp == "pizza"){
            uid+=2;
        }
        uval = atoi(val.c_str());
        long long ukey = uid*1000000+uval;
        //printf("%d %d\n",uid,uval);
        myuser.push_back(ukey);
    }
    sort(myuser.begin(),myuser.end());
    for(int i = 0; i<query.size(); i++){
        deque<long long> q;   
        int flag = 0;
        
        long long uid = 0;
        long long uval = 0;
        string lang="";
        string bf="";
        string js="";
        string cp="";
        string val="";
        int j = 0;
        char temp = query[i][j];
        while(j<=query[i].length()){ 
            temp = query[i][j];
            if(temp == ' '){
                if(j+1<query[i].length()){
                    if(query[i][j+1]=='a'){
                        flag++;
                        j+=5;
                        continue;
                    }
                    else{
                        flag++;
                        j++;
                        continue;
                    }
                }
            }
            if(flag == 0){
                lang+=temp;
            }
            else if(flag == 1){
                bf+=temp;
            }
            else if(flag ==2){
                js+=temp;
            }
            else if(flag == 3){
                cp+=temp;
            }
            else if(flag == 4){
                val+=temp;
            }
            j++;
        }
        //printf("%s %s %s %s %s\n",lang.c_str(),bf.c_str(),js.c_str(),cp.c_str(),val.c_str());
        if(lang == "cpp"){
            q.push_back(1000);
        }
        else if(lang == "java"){
            q.push_back(2000);
        }
        else if(lang == "python"){
            q.push_back(3000);
        }
        else{
            q.push_back(1000);
            q.push_back(2000);
            q.push_back(3000);
        }
        if(bf == "backend"){
            int qs = q.size();
            for(int k = 0; k<qs; k++){
                int idx = q.front();
                q.pop_front();
                q.push_back(idx+100);
            }
        }
        else if(bf == "frontend"){
            int qs = q.size();
            for(int k = 0; k<qs; k++){
                int idx = q.front();
                q.pop_front();
                q.push_back(idx+200);
            }
        }
        else{
            int qs = q.size();
            for(int k = 0; k<qs; k++){
                int idx = q.front();
                q.pop_front();
                q.push_back(idx+100);
                q.push_back(idx+200);
            }
        }
        if(js == "junior"){
            int qs = q.size();
            for(int k = 0; k<qs; k++){
                int idx = q.front();
                q.pop_front();
                q.push_back(idx+10);
            }
        }
        else if(js == "senior"){
            int qs = q.size();
            for(int k = 0; k<qs; k++){
                int idx = q.front();
                q.pop_front();
                q.push_back(idx+20);
            }
        }
        else{
            int qs = q.size();
            for(int k = 0; k<qs; k++){
                int idx = q.front();
                q.pop_front();
                q.push_back(idx+10);
                q.push_back(idx+20);
            }
        }
        if(cp =="chicken"){
            int qs = q.size();
            for(int k = 0; k<qs; k++){
                int idx = q.front();
                q.pop_front();
                q.push_back(idx+1);
            }
        }
        else if(cp == "pizza"){
            int qs = q.size();
            for(int k = 0; k<qs; k++){
                int idx = q.front();
                q.pop_front();
                q.push_back(idx+2);
            }
        }
        else{
            int qs = q.size();
            for(int k = 0; k<qs; k++){
                int idx = q.front();
                q.pop_front();
                q.push_back(idx+1);
                q.push_back(idx+2);
            }
        }
        uval = atoi(val.c_str());

        for(int k = 0; k<q.size(); k++){
            q[k] = uval+q[k]*1000000;
            
        }
        int sum = 0;
        for(int k = 0; k<q.size(); k++){
            vector<long long>::iterator lb;
            vector<long long>::iterator ub;
            
            long long temp = q[k]/1000000*1000000+100000;
            //printf("%ld %ld\n",q[k],temp);
            lb = lower_bound(myuser.begin(),myuser.end(),q[k]);
            ub = lower_bound(myuser.begin(),myuser.end(),temp);
            sum+= (ub-lb);
        }
        //printf("%d\n",sum);
        answer.push_back(sum);
    }

    return answer;
}