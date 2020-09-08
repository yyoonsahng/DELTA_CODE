#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
#include <string>
#include <cstdlib>
using namespace std;

vector<char> compression(vector<vector<int>> tree){
    int black = 0;
    int white = 0;
    vector<char> result;
    vector<char> result1;
    vector<char> result2;
    vector<char> result3;
    vector<char> result4;
    
    for (int i =0; i < tree.size(); i++) {
        for (int j = 0; j < tree.size(); j++) {
            if(tree[i][j] == 1)
                black++;
            else
                white++;
        }
    }
    if (white == (tree.size() * tree.size()))
        result.push_back('0');
    else if(black == (tree.size() * tree.size()))
        result.push_back('1');
    else if (tree.size() == 1){
        if (tree[0][0] == 0)
            result.push_back('0');
        else
            result.push_back('1');
    }
    else{
        vector<vector<int>> tree1(tree.size() / 2);
        vector<vector<int>> tree2(tree.size() / 2);
        vector<vector<int>> tree3(tree.size() / 2);
        vector<vector<int>> tree4(tree.size() / 2);
        for (int i = 0; i < tree.size(); i++)
        {
            for (int j = 0; j < tree.size(); j++)
            {
                if (i < tree.size() / 2 && j < tree.size() / 2)
                    tree1[i].push_back(tree[i][j]);
                else if (i < tree.size() / 2 && j >= tree.size() / 2)
                    tree2[i].push_back(tree[i][j]);
                else if (i >= tree.size() / 2 && j < tree.size() / 2)
                    tree3[i - tree.size() / 2].push_back(tree[i][j]);
                else if (i >= tree.size() / 2 && j >= tree.size() / 2)
                    tree4[i - tree.size() / 2].push_back(tree[i][j]);
            }
        }
        result1 = compression(tree1);
        result2 = compression(tree2);
        result3 = compression(tree3);
        result4 = compression(tree4);
        int total = result1.size() + result2.size() + result3.size() + result4.size();
        for (int i =0; i < total; i++) {
            if (i < result1.size())
                result.push_back(result1[i]);
            else if(i >= result1.size() && i < result2.size() + result1.size())
                result.push_back(result2[i - result1.size()]);
            else if (i >= result2.size() && i< total - result4.size())
                result.push_back(result3[i - (result2.size() + result1.size())]);
            else
                result.push_back(result4[i - (total - result4.size())]);
        }
        result.insert(result.begin(), '(');
        result.push_back(')');
    }
    return result;
}

int main(){
    int n = 0;
    cin>>n;//언제나 2의 제곱수
    vector<vector<int>> tree(n);
    //cout<<tree.size()<<endl;
    vector<char> result;
    string k = "";
    for (int i =0; i < n; i++) {
        cin >> k;
        for (int j = 0;j<n; j++){
            int stoint = k.at(j) - 48;
            tree[i].push_back(stoint);
        }
    }
    
    result = compression(tree);
    for (int i =0; i < result.size(); i++) {
        cout << result[i];
    }
}
