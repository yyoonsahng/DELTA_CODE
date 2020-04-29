//
//  PG - 43105 - ¤¸¤Ã¤·¤µ¤Ì¤µ¤¿¤±¤¡¤¿¤¡¤¾¤Å¤·.cpp
//  ¤²¤À¤¡¤¸¤Ì¤¤¤±¤Ì¤¤¤¸¤Ä¤½¤Ì¤©¤·¤Ó
//
//  Created by ±è¼ºÇå on 2020/04/10.
//  Copyright ¨Ï 2020 ±è¼ºÇå. All rights reserved.
//

#include<iostream>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
int cache[501][501];//x,y¿¡¼­ ´õÇØÁø °ª
int cal(int x,int y,vector<vector<int>> &triangle){
    int &ret = cache[x][y];
    if(ret != -1) return ret;
    if(y!=0 && y!=x) ret = max(cal(x-1,y-1,triangle) + triangle[x][y],cal(x-1,y,triangle) + triangle[x][y]);
    else if(y==0) ret = cal(x-1,y,triangle) + triangle[x][y];
    else if(y==x) ret = cal(x-1,y-1,triangle) + triangle[x][y];
    return ret;
}
int solution(vector<vector<int>> triangle) {
    memset(cache,-1,sizeof(cache));
    int answer = -1;
    cache[0][0] = triangle[0][0];
    for(int i=0;i<triangle.size();i++){
        answer = max(answer,cal((int)triangle.size()-1,i,triangle));
    }   
    return answer;
}