//캐시
#include <iostream>
#include <string>
#include <vector>
#include <string>
#include <algorithm>
#include <list>

using namespace std;

int solution(int cacheSize, vector<string> cities) {
    
    for(int i = 0; i<cities.size(); i++){
        std::transform(cities[i].begin(),cities[i].end(),cities[i].begin(),::tolower);
    }
    int answer = 0;
    list<string> cache;
    list<string>::iterator iter;
    for(string s : cities){
        if(cacheSize == 0){
            answer+=5;
            continue;
        }
        if(cache.size()==0){
            cache.push_back(s);
            answer+=5;
            continue;
        }
        if(cache.size()<=cacheSize){
            
            bool flag = false;
            for(iter = cache.begin(); iter!=cache.end(); ++iter){
                if(s.compare(*iter)==0){
                    answer+=1;
                    flag = true;
                    cache.erase(iter);
                    cache.push_back(s);
                    break;
                }
            }
            if(flag == false){
                if(cache.size()==cacheSize)
                    cache.pop_front();
                cache.push_back(s);
                answer+=5;
            }
        }
    }
    return answer;
}
int main(){
    int n = 3;
    cout<<int('a')<<" "<<int('A')<<endl;
}