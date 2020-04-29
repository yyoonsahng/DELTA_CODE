//
//  main.cpp
//  tile_deco
//
//  Created by 김윤상 on 29/04/2020.
//  Copyright © 2020 김윤상. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;

long long cash[81] = {0, };

long long solution(int N) {
    long long answer = 0;
    if (N <= 0) {
        return 2;
    }
    long long &ret = cash[N];
    if (ret != 0)
        return ret;
    ret = solution(N - 1) + solution(N - 2);
    answer = ret;
    return answer;
}

int main(){
    cout << solution(8) << endl;
}
