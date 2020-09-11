//
//  백준17471 - 게리멘더링.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/31.
//  Copyright © 2020 김성헌. All rights reserved.
//
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <memory.h>
using namespace std;

int main(){
    int n;
    int answer = 987654321;
    cin >> n;
    vector<int> num;
    vector<int> connect[11];
    vector<int> comb;
    for(int i=0;i<n;i++) comb.push_back(i);
    for(int i=0;i<n;i++){
        int element;
        cin >> element;
        num.push_back(element);
    }
    
    for(int i=0;i<n;i++){
        int connect_num;
        cin >> connect_num;
        int element;
        for(int j=0;j<connect_num;j++){
            cin >> element;
            connect[i].push_back(element-1);
        }
    }
    
    for(int i=1;i<=n/2;i++){
        vector<int> ind;
        int k = i; //이것만큼 뽑겠다.
        for(int i=0;i<k;i++) ind.push_back(1);
        for(int i=0;i<comb.size()-k;i++) ind.push_back(0);
        sort(ind.begin(),ind.end());
        do{
            vector<int> one;
            vector<int> two;
            for(int j=0;j<ind.size();j++){
                if(ind[j] == 1) one.push_back(comb[j]);
                else if(ind[j] == 0) two.push_back(comb[j]);
            }
            
            //연결 되어 있는지 확인
            //두 개에 대해서 bfs
            int candidate = 0;
            
            int check1 = 1;
            queue<int> q1;
            bool visited1[11];
            memset(visited1,false,sizeof(visited1));
            
            visited1[one[0]] = true;
            q1.push(one[0]);
            while(!q1.empty()){
                int top = q1.front(); q1.pop();
                for(int i=0;i<connect[top].size();i++){
                    int next = connect[top][i];
                    for(int i=0;i<one.size();i++){
                        if(one[i] == next && !visited1[next]){
                            q1.push(next);
                            visited1[next] = true;
                            check1++;
                            break;
                        }
                    }
                }
            }

            queue<int> q2;
            bool visited2[11];
            memset(visited2,false,sizeof(visited2));
            int check2 = 1;
            visited2[two[0]] = true;
            q2.push(two[0]);
            while(!q2.empty()){
                int top = q2.front(); q2.pop();
                for(int i=0;i<connect[top].size();i++){
                    int next = connect[top][i];
                    for(int i=0;i<two.size();i++){
                        if(two[i] == next && !visited2[next]){
                            q2.push(next);
                            visited2[next] = true;
                            check2++;
                            break;
                        }
                    }
                }
            }
            
            if(check1 == one.size() && check2 == two.size()){
                int left = 0;
                int right = 0;
                for(int i=0;i<one.size();i++) left += num[one[i]];
                for(int i=0;i<two.size();i++) right += num[two[i]];
                candidate = abs(left - right);
                answer = min(answer,candidate);
            }
            //최솟값 갱신
        }while(next_permutation(ind.begin(), ind.end()));
    }
    if(answer == 987654321) cout << -1 << endl;
    else cout << answer << endl;
    return 0;
}
