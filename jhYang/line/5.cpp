#include <string>
#include <vector>

using namespace std;

int solution(vector<int> cards) {
    for(int i = 0; i<cards.size(); i++){
        if(cards[i] >= 10){
            cards[i] = 10;
        }
    }
    int pcnt = 0;
    int dcnt;
    int answer = -1;
    int idx = 0;
    while(idx<cards.size()){
        
    vector<int> pcards;
    vector<int> dcards;
    
    int s1 = cards[idx];
    int s2 = cards[idx+1];
    int s3 = cards[idx+2];
    int s4 = cards[idx+3];
    idx+=4;
    dcards.push_back(s2);
    dcards.push_back(s4);
    pcards.push_back(s3);
    pcards.push_back(s1);

    int flag = 0;
    int psum = 0;
    
    for(int i = 0; i<pcards.size(); i++){
        if(pcards[i] == 1){
            flag++;
        }
        psum+=pcards[i];
    }
    if(flag >= 1){
        if(abs(psum+10-21)<abs(psum-21)){
            psum = psum+10;
        }
        if(flag >= 2){
            if(abs(psum+10-21)<abs(psum-21)){
                psum = psum+10;
            }
        }
    }
    int dsum = 0;

    if(psum==21){
        //win
        flag = 0;
        for(int i = 0; i<dcards.size(); i++){
            if(dcards[i] == 1){
                flag++;
            }
        }
        if(flag >= 1){
            if(abs(dsum+10-21)<abs(dsum-21)){
                dsum = dsum+10;
            }
            if(flag >= 2){
                if(abs(dsum+10-21)<abs(dsum-21)){
                    dsum = dsum+10;
                }
            }
        }
        if(dsum!=21){
            //player win
            pcnt+=3;
        }
        else{
            //draw
        }
        continue;
    }
    else if(psum<21){
        if(s4 == 1 || s4 >= 7){
            while(psum<17){
                pcards.push_back(cards[idx]);
                psum = 0;
                flag = 0;
                for(int i = 0; i<pcards.size(); i++){
                    if(pcards[i] == 1){
                        flag++;
                    }
                    psum+= pcards[i];
                }
                if(flag >= 1){
                    if(abs(psum+10-17)<abs(psum-17)){
                        psum = psum+10;
                    }
                    if(flag >= 2){
                        if(abs(psum+10-17)<abs(psum-17)){
                            psum = psum+10;
                        }
                    }
                }
                idx++;
            }
        }
        else if(s4 >=4 && s4<=6){

        }
        else if(s4 >=2 && s4<=3){
            while(psum<12){
                pcards.push_back(cards[idx]);
                psum = 0;
                flag = 0;
                for(int i = 0; i<pcards.size(); i++){
                    if(pcards[i] == 1){
                        flag++;
                    }
                    psum+= pcards[i];
                }
                if(flag >= 1){
                    if(abs(psum+10-12)<abs(psum-12)){
                        psum = psum+10;
                    }
                    if(flag >= 2){
                        if(abs(psum+10-12)<abs(psum-12)){
                            psum = psum+10;
                        }
                    }
                }
                idx++;
            }
        }
    }
    else if(psum>21){
        //lose
        pcnt-=2;
        continue;
    }
    dsum = 0;
    flag = 0;
    for(int i = 0; i<dcards.size(); i++){
        if(dcards[i] == 1){
            flag++;
        }
        dsum+=dcards[i];
    }
    if(flag >= 1){
        if(abs(dsum+10-17)<abs(dsum-17)){
            dsum = dsum+10;
        }
        if(flag >= 2){
            if(abs(dsum+10-17)<abs(dsum-17)){
                dsum = dsum+10;
            }
        }
    }
    int gflag = 0;
    while(dsum<17){
        dsum = 0;
        if(idx>=cards.size()){
            gflag = 1;
            break;
        }
        dcards.push_back(cards[idx]);
        idx++;
        for(int i = 0; i<dcards.size(); i++){
            if(dcards[i] == 1){
                flag++;
            }
            dsum+=dcards[i];
        }
        if(flag >= 1){
            if(abs(dsum+10-17)<abs(dsum-17)){
                dsum = dsum+10;
            }
            if(flag >= 2){
                if(abs(dsum+10-17)<abs(dsum-17)){
                    dsum = dsum+10;
                }
            }
        }
    }
    if(gflag == 1){
        break;
    }
    dsum = 0;
    flag = 0;
    for(int i = 0; i<dcards.size(); i++){
        if(dcards[i] == 1){
            flag++;
        }
        dsum+=dcards[i];
    }
    if(flag >= 1){
        if(abs(dsum+10-21)<abs(dsum-21)){
            dsum = dsum+10;
        }
        if(flag >= 2){
            if(abs(dsum+10-21)<abs(dsum-21)){
                dsum = dsum+10;
            }
        }
    }

    if(dsum>21){
        //player win
        pcnt+=2;
        continue;
    }

    if(abs(psum-21)<abs(dsum-21)){
        //player win
        pcnt+=2;
    }
    else if(abs(psum-21)==abs(dsum-21)){
        //draw
    }
    else{
        //player lose
        pcnt-=2;
    }
    
    }
    answer = pcnt;
    return answer;
}