//뉴스 클러스터링

#include<iostream>
#include <string>
#include <map>
#include <algorithm>

using namespace std;

void insertMap(map<string,int>& m,string& str){
    for(int i = 0; i<str.length()-1; i++){
        string s = str.substr(i,2);
        if(s[0]>='a'&&s[0]<='z' && s[1]>='a'&&s[1]<='z'){
            if(m.find(s) == m.end())
                m.insert(make_pair(s,1));
            else
                m[s]++;
        }
    }
}
int solution(string str1, string str2) {
    int answer = 0;
    transform(str1.begin(),str1.end(),str1.begin(),::tolower);
    transform(str2.begin(),str2.end(),str2.begin(),::tolower);
    map<string,int> m1;
    map<string,int> m2;
    insertMap(m1,str1);
    insertMap(m2,str2);
    map<string,int>::iterator iter1;
    map<string,int>::iterator iter2;
    
    double h = 0;
    double t = 0;
    for(iter1 = m1.begin(); iter1!=m1.end(); ++iter1){
        iter2 = m2.find(iter1->first);
        //교집합이 있음
        if(iter2!=m2.end()){
            t+=max(iter2->second,iter1->second);
            h+=min(iter2->second,iter1->second);
        }
        else{
            t+=iter1->second;
        }
    }
    for(iter2 = m2.begin(); iter2!=m2.end(); ++iter2){
        iter1 = m1.find(iter2->first);
        if(iter1==m1.end())
            t+=iter2->second;
    }
    return t == 0? 65536:h/t*65536;
}
int main(){
    string str1 = "E=M*C^2";
    string str2 = "e=m*c^2";
    cout<<solution(str1,str2);
}