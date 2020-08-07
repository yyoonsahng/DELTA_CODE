// 다트게임
#include <iostream>

using namespace std;

bool isDigit(int c){
    if(c>='0'&&c<='9')
        return true;
    return false;
}

int solution(string dartResult) {
    int answer = 0;
    bool f = false;
    int temp = -1;
    int ptmp = -100000;
    for(int i = 0; i<dartResult.size(); i++){
        int dr = dartResult[i];
        if(isDigit(dr)){
            temp = int(dr)-'0';
            if(dr=='1'&&isDigit(int(dartResult[i+1]))){
                temp = 10;
                i++;
            }
            continue;
        }
        if(dr == 'S' || dr == 'D' || dr == 'T'){
            if(dr=='S') {}
            if(dr=='D') {temp*=temp;}
            if(dr=='T') {temp*=temp*temp;}
            if(i+1<dartResult.size() && !isDigit(int(dartResult[i+1])))
                dr=dartResult[++i];
        }
        if(dr=='#') {temp*=-1;}
        if(dr=='*') {ptmp*=2; temp*=2;}
        if(ptmp <= -100000){
            ptmp = temp;
            temp = -1;
        }
        else{
            answer+=ptmp;
            ptmp = temp;
            temp = -1;
        }
    }
    answer+=ptmp;
    return answer;
}
int main(){
    string dartResult;
    cin>>dartResult;
    cout<<solution(dartResult);
}