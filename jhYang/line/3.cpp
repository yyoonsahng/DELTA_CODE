#include <string>
#include <vector>
#include <queue>
using namespace std;
//1000000000
queue<pair<int,string> > que;
pair<int,int> bfs(){
    int dist = 0;
    while(!que.empty()){
        dist = que.front().first;
        string s = que.front().second;
        que.pop();
        if(s.length() == 1){
            return make_pair(dist,atoi(s.c_str()));
        }
        dist++;
        for(int i = 1; i<s.length(); i++){
            string prev = s.substr(0,i);
            string next = s.substr(i,s.length());
            if(prev[0] == '0' || next[0] == '0')
                continue;
            int nint = atoi(prev.c_str())+atoi(next.c_str());
            //printf("%d : %d\n",nint,dist);
            string nstr = to_string(nint);
            if(nstr.length() == 1){
                return make_pair(dist,atoi(nstr.c_str()));
            }
            que.push(make_pair(dist,nstr));
        }
    }
}

vector<int> solution(int n) {
    vector<int> answer;

    string str = to_string(n);
    que.push(make_pair(0,str));
    pair<int,int> res = bfs();
    answer.push_back(res.first);
    answer.push_back(res.second);
    return answer;
}