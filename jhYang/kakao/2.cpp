#include <string>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

vector<string> solution(vector<string> orders, vector<int> course) {
    
    vector<string> answer;
    vector<string> arr;
    vector<vector<char> > vec;
    vector<pair<int,string> > res;
    map<string,int> mymap;
    int isFull[11]={0};
    for(int i = 0; i<11; i++){
        isFull[i] = -1;
    }
    arr.resize(orders.size());
    for(int i = 0; i<orders.size(); i++){
        for(int j = 0; j<orders[i].length(); j++){
            arr[i].push_back(orders[i][j]-'A');
        }
    }
    for(int i = 0; i<course.size(); i++){
        int n = course[i];
        vector<int> idx;

        for (int j = 1; j <= n; j++)
            idx.push_back(1);
        for (int j = 1; j <= 26-n; j++)
            idx.push_back(0);
        
        sort(idx.begin(), idx.end());

        do{
            vector<int> target;
            for(int k = 0; k<idx.size(); k++){
                if(idx[k] == 1){
                    target.push_back(k);
                }
            }
            int sum = 0;
            for(int k = 0; k<arr.size(); k++){
                int ssum = 0;
                for(int j = 0; j<arr[k].size(); j++){
                    for(int l = 0; l<target.size(); l++){
                        if(arr[k][j] == target[l]){
                            ssum++;
                        }
                    }
                    
                }
                if(ssum == target.size()){
                    sum++;
                }
            }
            if(sum >= 2){
                string temp = "";
                for(int k = 0; k<target.size(); k++){
                    temp+=char(target[k]+'A');
                }
                map<string,int>::iterator iter;
                iter = mymap.find(temp);

                if(iter==mymap.end()){
                    mymap.insert(make_pair(temp,sum));
                    res.push_back(make_pair(sum,temp));
                }
            }
            
        } while (next_permutation(idx.begin(), idx.end()));
    }
    sort(res.begin(),res.end(),greater<pair<int,string> >());
    
    for(int i = 0; i<res.size(); i++){
        for(int j = 0; j<course.size(); j++){
            if(res[i].second.length() == course[j]&&
              isFull[res[i].second.length()]<=res[i].first){
                answer.push_back(res[i].second);
                isFull[res[i].second.length()] = res[i].first;
            }
        }
    }
    
    sort(answer.begin(),answer.end());
    return answer;
}
