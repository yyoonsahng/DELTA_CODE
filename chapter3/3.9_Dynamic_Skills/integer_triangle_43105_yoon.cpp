//
//  main.cpp
//  integer_triangle_43105
//
//  Created by 김윤상 on 29/04/2020.
//  Copyright © 2020 김윤상. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>

using namespace std;
int cash[500][500];
int a = 0, b = 0;
int solution(vector<vector<int>> triangle) {
    int answer = 0;
    for (int i =0; i < triangle[triangle.size() - 1].size(); i++)

        cash[triangle.size() - 1][i] = triangle[triangle.size() - 1][i];
    
    for(int i = triangle.size() - 2; i >= 0; i--){
        for (int j =0; j < i + 1; j++) {
            cash[i][j] = max(cash[i + 1][j], cash[i+1][j+1]) + triangle[i][j];
        }
    }
    answer = cash[0][0];
    return answer;
}
int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> triangle (5, vector<int>(5, 0));
    
    triangle[0][0] = 7;
    triangle[1][0] = 3;
    triangle[1][1] = 8;
    triangle[2][0] = 8;
    triangle[2][1] = 1;
    triangle[2][2] = 0;
    triangle[3][0] = 2;
    triangle[3][1] = 7;
    triangle[3][2] = 4;
    triangle[3][3] = 4;
    triangle[4][0] = 4;
    triangle[4][1] = 5;
    triangle[4][2] = 2;
    triangle[4][3] = 6;
    triangle[4][4] = 5;
    
    int i = solution(triangle);
    cout<<i << endl;

}
