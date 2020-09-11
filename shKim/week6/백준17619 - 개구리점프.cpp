//
//  백준17619 - 개구리점프.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/09/09.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

struct coord{
    int x1;
    int x2;
    int y;
    int index;
    bool operator <(coord const &rhs) const{
        if(rhs.y == y) return rhs.x1 > x1;
        else return x1>rhs.x1;
    }
};

vector<coord> v;
int main(){
    int n,Q,start,dest;
    cin >> n >> Q;
    
    for(int i=0;i<n;i++){
        int x1,x2,y;
        cin >> x1 >> x2 >> y;
        v.push_back({x1,x2,y,i});
    }
    
    
    return 0;
}
