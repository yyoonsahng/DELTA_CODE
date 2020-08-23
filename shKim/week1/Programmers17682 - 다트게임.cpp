//
//  Programmers17682 - 다트게임.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/06.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include<iostream>
#include<algorithm>
#include<string>
#include<math.h>
using namespace std;

int solution(string dartResult) {
    string str = "";
    int arr[4] = {0,0,0};
    int index = -1;
    for(int i=0;i<dartResult.size();i++){
        if(dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T'){
            if(str.size() == 2) arr[--index] = 10;
            else arr[index] = int(str[0]) - 48;
            //cout << str << endl;
            switch (dartResult[i]) {
                case 'S':
                    arr[index] = pow(double(arr[index]),1.0);
                    break;
                case 'D':
                    arr[index] = pow(double(arr[index]),2.0);
                    break;
                case 'T':
                    arr[index] = pow(double(arr[index]),3.0);
                    break;
            }
            str = "";
        }else if(dartResult[i] == '#' || dartResult[i] == '*'){
            switch (dartResult[i]) {
                case '*':
                    if(index != 0){
                        arr[index-1] *= 2;
                        arr[index] *= 2;
                    }else arr[index] *= 2;
                    break;
                case '#':
                    arr[index] *= -1;
                    break;
            }
        }
        else{
            index++;
            str.push_back(dartResult[i]);
        }
        cout << index << endl;
        cout << arr[index] << endl;
        cout << " ----- " << endl;
    }
    return arr[0] + arr[1] + arr[2];
}

int main(){
    cout << solution("1D2S#10S") << endl;
}
