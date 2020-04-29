//
//  PG - 43104 - ㅌㅏㅇㅣㄹ ㅈㅏㅇㅅㅣㄱㅁㅜㄹ.cpp
//  ㅂㅐㄱㅈㅜㄴㅁㅜㄴㅈㅔㅍㅜㄹㅇㅣ
//
//  Created by 김성헌 on 2020/04/10.
//  Copyright ⓒ 2020 김성헌. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include <string>
#include <vector>
#include <memory.h>
using namespace std;
long long cache[81]; //n 번째 직사각형의 한변의 길이
long long cal(int n){
    if(n<0) return 0;
    long long &ret = cache[n];
    if(ret != -1) return ret;
    ret = cal(n-2)+cal(n-1);
    return ret;
}
long long solution(int N) {
    memset(cache,-1,sizeof(cache));
    cache[1] = 1; cache[2] = 1;
    return cal(N)*4+cal(N-1)*2;
}