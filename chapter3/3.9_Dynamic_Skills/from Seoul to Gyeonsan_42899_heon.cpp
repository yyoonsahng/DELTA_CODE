#include <string>
#include <vector>
#include <memory.h>
using namespace std;
int k = 0;
int cache[101][100001];
int cal(vector<vector<int>> &travel,int city,int time){
    if(time > k) return -987654321;
    if(city == travel.size()) return 0;
    int &ret = cache[city][time];
    if(ret != -1) return ret;
    ret = max(travel[city][1]+cal(travel,city+1,time+travel[city][0]),
             travel[city][3]+cal(travel,city+1,time+travel[city][2]));
    return ret;
}
int solution(int K, vector<vector<int>> travel) {
    int answer = 0;
    k = K;
    memset(cache,-1,sizeof(cache));
    answer = cal(travel,0,0);
    return answer;
}