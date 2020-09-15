#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<int> ball, vector<int> order) {
    vector<int> answer;
    deque<int> stk;
    deque<int> b;
    deque<int> o;
    o.resize(order.size());
    b.resize(ball.size());
    for(int i = 0; i<ball.size(); i++){
        b[i] = ball[i];
    }
    for(int i = 0; i<order.size(); i++){
        o[i] = order[i];
    }
    int n = order.size();
    stk.push_back(o.front());
    o.pop_front();
    while((!stk.empty()||o.size()>0)){
        if(!stk.empty()){
            if(stk.back() == b.back()){
                answer.push_back(b.back());
                b.pop_back();
                stk.pop_back();
                continue;
            }
            else if(stk.back() == b.front()){
                answer.push_back(b.front());
                b.pop_front();
                stk.pop_back();
                continue;
            }
            else if(stk.front() == b.back()){
                answer.push_back(b.back());
                b.pop_back();
                stk.pop_front();
                continue;
            }
            else if(stk.front() == b.front()){
                answer.push_back(b.front());
                b.pop_front();
                stk.pop_front();
                continue;
            }   
        }
        if(o.size()>=1){    
            stk.push_back(o.front());
            o.pop_front();
        }
    }
    
    return answer;
}