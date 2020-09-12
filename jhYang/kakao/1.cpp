#include <string>
#include <vector>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

string solution(string new_id) {
    string answer = "";
    
    std::transform(new_id.begin(),new_id.end(),new_id.begin(),::tolower);
    string nid = "";
    for(int i= 0; i<new_id.length(); i++){
        if(isalpha(new_id[i])||isdigit(new_id[i])||new_id[i]=='-'
        ||new_id[i]=='_'||new_id[i]=='.'){
            nid+=new_id[i];
        }
    }
    string nnid = "";
    for(int i = 0; i<nid.length(); i++){
        if(nid[i] =='.'){
            int k = i;
            while(nid[k]=='.'){
                k++;
            }
            nnid+='.';
            i = k-1;
        }
        else{
            nnid+=nid[i];
        }
    }
    if(nnid[0] == '.'){
        nnid = nnid.substr(1,nnid.length());
    }
    if(nnid[nnid.length()-1] == '.'){
        nnid = nnid.substr(0,nnid.length()-1);
    }
    if(nnid.length() == 0){
        nnid+='a';
    }
    if(nnid.length() >= 16){
        nnid = nnid.substr(0,15);
        if(nnid[nnid.length()-1] == '.'){
            nnid = nnid.substr(0,nnid.length()-1);
        }
    }
    if(nnid.length()<=2){
        while(nnid.length()<3){
            nnid+=nnid[nnid.length()-1];
        }
    }
    answer = nnid;
    return answer;

}