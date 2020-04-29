#include <string>
#include <vector>
#include <algorithm>
#include <memory.h>
#include<iostream>
using namespace std;
int cache[2001][2001];
int cal(int left,int right,vector<int> &l,vector<int> &r){
    if(left >= l.size() || right >=r.size()) return 0;
    int &ret = cache[left][right];
    if(ret != -1) return ret;
    if(l[left]>r[right]){
        ret = r[right]+ cal(left,right+1,l,r);
        return ret;
    }
    else{
        ret = max(cal(left+1,right+1,l,r),cal(left+1,right,l,r));
        return ret;
    }
    return ret;
}
int solution(vector<int> left, vector<int> right) {
    int answer = 0;
    memset(cache,-1,sizeof(cache));
    answer = cal(0,0,left,right);
    return answer;
}