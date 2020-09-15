#include <string>
#include <vector>

using namespace std;

int isFull[1000001] = {0,};
int solution(vector<vector<int>> boxes) {
    int answer = -1;

    for(int i = 0; i<boxes.size(); i++){
        for(int j = 0; j<boxes[i].size(); j++){
            isFull[boxes[i][j]]++;
        }
    }
    int cnt = 0;
    for(int i = 0; i<1000001; i++){
        if(isFull[i]%2 == 1){
            cnt++;
        }
    }
    answer = min(cnt,abs((int)boxes.size()-cnt));

    return answer;
}