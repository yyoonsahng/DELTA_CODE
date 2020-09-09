//시작시간 16:54
#include<iostream>
#include <string>
#include <vector>

using namespace std;

vector<vector<int> > board;
vector<vector<int> > b1,b2,b3,b4;

bool smlchk(vector<vector<int> > bb,int m,int n, int i, int j){
    int cnt = 0;
    for(int a = 0; a<n; a++){
        for(int b = 0; b<n; b++){
            if(board[a][b] != bb[i+a][j+b]){
                return false;
            }
        }
    }
    return true;
}

void _rotate(vector<vector<int> > &tb,vector<vector<int> > &b,int m,int n){
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            tb[n+j][n+i] = b[n+m-1-i][n+j];      
        }
    }
}
bool solution(vector<vector<int> > key, vector<vector<int> > lock) {
    int n = lock.size();
    int m = key.size();

    bool answer = false;
    board.resize(100);
    b1.resize(100);
    b2.resize(100);
    b3.resize(100);
    b4.resize(100);

    
    for(int i = 0; i<100; i++){
        b1[i].resize(100);
        b2[i].resize(100);
        b3[i].resize(100);
        b4[i].resize(100);
        board[i].resize(100);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<n; j++){
            board[i][j] = lock[i][j]^1;
        }
    }
    for(int i = 0; i<m; i++){
        for(int j = 0; j<m; j++){
            b2[n+j][n+i] = key[m-1-i][j];      
        }
    }
    _rotate(b3,b2,m,n);
    _rotate(b4,b3,m,n);
    _rotate(b1,b4,m,n);
    
    for(int i = 1; i<n+m; i++){
        for(int j = 1; j<n+m; j++){
            if(smlchk(b1,m,n,i,j)||smlchk(b2,m,n,i,j)||smlchk(b3,m,n,i,j)||smlchk(b4,m,n,i,j))
                return true;
        }
    }
    return answer;
}

int main(){
    vector<vector<int> > v1;
    vector<int> vv1;
    vv1.push_back(0);vv1.push_back(0);vv1.push_back(0);
    v1.push_back(vv1);

    vv1.clear();
    vv1.push_back(1);vv1.push_back(0);vv1.push_back(0);
    v1.push_back(vv1);
    
    vv1.clear();
    vv1.push_back(0);vv1.push_back(1);vv1.push_back(1);
    v1.push_back(vv1);

    vector<vector<int> > v2;
    vector<int> vv2;
    vv2.push_back(1);vv2.push_back(1);vv2.push_back(1);
    v2.push_back(vv2);
    vv2.clear();
    vv2.push_back(1);vv2.push_back(1);vv2.push_back(0);
    v2.push_back(vv2);
    vv2.clear();
    vv2.push_back(1);vv2.push_back(0);vv2.push_back(1);
    v2.push_back(vv2);
    
    cout<<solution(v1,v2)<<endl;
}