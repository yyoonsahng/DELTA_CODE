//
//  Programmers42890 후보키.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/30.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

int n;
vector<vector<string>> relate;
vector<vector<int>> candidate;
void pick(int n,vector<int> &comb,int toPick){
    if(toPick == 0){
        // MARK:-유일성 검사
        bool unique = true;
        set<string> check;
        for(int i=0;i<relate.size();i++){
            string element = "";
            for(int j=0;j<comb.size();j++) element += "-" + relate[i][comb[j]];
            if(check.find(element) != check.end()) {
                unique = false;
                break;
            }
            check.insert(element);
        }
        
        // MARK:-최소성 검사
        bool minimality = true;
        for(int i=0;i<candidate.size();i++){
            vector<int> cmp = candidate[i];
            if(cmp.size() < comb.size()){
                int check = 0;
                for(int j=0;j<cmp.size();j++){
                    for(int k=0;k<comb.size();k++){
                        if(cmp[j] == comb[k]) check++;
                    }
                }
                if(check == cmp.size()) minimality = false;
            }
        }
        
        if(unique && minimality) candidate.push_back(comb);
    }
    
    
    int smallest = comb.empty() ? 0 : comb.back() + 1;
    for(int i = smallest;i<n;i++){
        comb.push_back(i);
        pick(n, comb, toPick-1);
        comb.pop_back();
    }
}
int solution(vector<vector<string>> relation) {
    relate = relation;
    n = int(relation[0].size());
    for(int i=1;i<=n;i++){
        vector<int> comb;
        pick(n,comb,i);
    }
    return candidate.size();
}

int main(){
    cout << solution({{"100", "ryan", "music", "2"}, {"200", "apeach", "math", "2"}, {"300", "tube", "computer", "3"},{"400", "con", "computer", "4"}, {"500", "muzi", "music", "3"}, {"600", "apeach", "music", "2"}});
    return 0;
}
