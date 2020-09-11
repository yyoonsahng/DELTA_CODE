//
//  백준2473 세 용액.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/28.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(){
    int n;
    int minimum = 987654321;
    vector<int> answer;
    vector<int> positive;
    vector<int> negative;
    cin >> n;
    int element;
    for(int i=0;i<n;i++){
        cin >> element;
        if(element >= 0) positive.push_back(element);
        else negative.push_back(-1 * element);
    }
    //sort를 통해 이분탐색 가능하게
    sort(positive.begin(), positive.end());
    sort(negative.begin(),negative.end());
    //모두 알칼리성 용액 or 모두 산성 용액 일 경우
    if(negative.size() == 0){
        for(int i=0;i<3;i++) cout << positive[i] << " ";
        return 0;
    }
    if(positive.size() == 0){
        for(int i=2;i>=0;i--) cout << -1 * negative[i] << " ";
        return 0;
    }
    
    for(int i=0;i<negative.size()-1;i++){
        for(int j=i+1;j<negative.size();j++){
            int two = negative[i] + negative[j];
            int prev_minimum = minimum;
            long index = lower_bound(positive.begin(), positive.end(), two) - positive.begin();
            if(index >= positive.size()) minimum = min(minimum, abs(-1 * two + positive[index-1]));
            else minimum = min(minimum,abs(-1 * two + positive[index]));
            
            if(prev_minimum != minimum){
                answer.clear();
                if(index >= positive.size()) answer = {-1 * negative[j],-1 * negative[i], positive[index-1]};
                else answer = {-1 * negative[j],-1 * negative[i], positive[index]};
            }
        }
    }
    
    for(int i=0;i<positive.size()-1;i++){
        for(int j=i+1;j<positive.size();j++){
            int two = positive[i] + positive[j];
            int prev_minimum = minimum;
            long index = lower_bound(negative.begin(), negative.end(), two) - negative.begin();
            if(index >= negative.size()) minimum = min(minimum, abs(-1 * two + negative[index-1]));
            else minimum = min(minimum,abs(-1 * two + negative[index]));
            
            if(prev_minimum != minimum){
                answer.clear();
                if(index >= positive.size()) answer = {-1 * negative[index-1], positive[i], positive[j]};
                else answer = {-1 * negative[index],positive[i], positive[j]};
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    for(int i=0;i<answer.size();i++) cout << answer[i] << " ";
    
    
    
    return 0;
}
