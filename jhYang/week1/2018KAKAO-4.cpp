//프렌즈4블록
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int dx[4] = {0,1,0,1};
int dy[4] = {0,0,1,1};

int solution(int m, int n, vector<string> board) {
    int answer = 0;
    int cnt = 1;

    while(cnt != 0){
    
    vector<pair<int,int> > v;
    cnt = 0;
    for(int i = 0; i<m; i++){
        for(int j = 0; j<n; j++){
            char c = board[i][j];
            bool flag = false;

            if(c == '#') 
                continue;
            
            for(int k = 0; k<4; k++){

                if(i+dx[k]>=m || j+dy[k]>=n) {
                    flag = false;
                    break;
                }
                if(c != board[i+dx[k]][j+dy[k]]) {
                    flag = false;
                    break;
                }

                flag = true;
            }
            if(flag){
                cnt++;
                for(int k = 0; k<4; k++){
                    v.push_back(make_pair(i+dx[k],j+dy[k]));
                }
            }
        }
    }
    for(pair<int,int> p : v){
        if(board[p.first][p.second] == '#') continue;
        board[p.first][p.second] = '#';
        answer++;
    }
    for(int j = 0; j<n; j++){
        for(int i = m-1; i>=0; i--){
            if(board[i][j] == '#'){
                int k = i;
                while(k>=0){
                    if(board[k][j] != '#'){
                        board[i][j] = board[k][j];
                        board[k][j] = '#';
                        break;
                    }
                    k--;
                }
            }
        }
    }
    }
    return answer;
}
int main(){
    int m = 6;
    int n = 6;
    vector<string> a;
    a.push_back("TTTANT");
    a.push_back("RRFACC");
    a.push_back("RRRFCC");
    a.push_back("TRRRAA");
    a.push_back("TTMMMF");
    a.push_back("TMMTTJ");
    cout<<solution(m,n,a)<<endl;
}