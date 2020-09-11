#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;
    int mmin = 10000000;
    for(int i = 1; i<=s.length(); i++){
        int templen = 0;
        int j = 0;
        string res = "";
        string str = "";
        int sum = 0;
        while(j<=s.length()){
            if(str.length() == 0){
                str = s.substr(j,i);
                sum = 1;
                j+=i;
            }
            else{
                string temp = s.substr(j,i);
                if(str == temp){
                    sum++;
                    j+=i;
                }   
                else{
                    if(sum != 1){
                        templen += (to_string(sum).length()+str.length());
                        res += (to_string(sum)+str);
                    }
                    else{
                        templen += str.length();
                        res += str;
                    
                    }
                    str = temp;
                    sum = 1;
                    j+=i;
                }
            }
        }
        if(sum!=1){
            templen += (to_string(sum).length()+str.length());
            res += (to_string(sum)+str);
        }
        else{
            templen += str.length();
            res += str;
        }
        
        //printf("%s\n",res.c_str());
        mmin = min(templen,mmin);
    }
    answer = mmin;
    return answer;
}