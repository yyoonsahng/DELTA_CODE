//
//  Programmers60060 - 가사검색.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/08/15.
//  Copyright © 2020 김성헌. All rights reserved.
//
#include <cstdio>
#include <cstring>
#include<iostream>
#include <string>
#include <vector>
#include<map>
#include <algorithm>
#define ALPHABETS 27
// Convert char to array index
// All are base on capital
using namespace std;
int char_to_index(char c) {
    return c - 'a';
}
struct Trie {
    bool is_terminal; // this represents end of string
    Trie *children[ALPHABETS];
    map<int, int> cnt;
    // Constructor
    Trie() : is_terminal(false) {
        memset(children, 0, sizeof(children));
    }
    // Delete all children
    ~Trie() {
        for (int i = 0; i < ALPHABETS; ++i) {
            if (children[i])
                delete children[i];
        }
    }
    void insert(const char * key,int size) {
        if (*key == '\0') {
            is_terminal = true;
        }
        else {
            int index = char_to_index(*key);
            if (children[index] == 0) {
                children[index] = new Trie();
                children[index]->cnt.insert({ size,1 });
            }
            else {
                children[index]->cnt[size]++;
            }
            children[index]->insert(key + 1,size);
        }
    }

    Trie* find(const char * key) {
        if (*key == 0) {
            return this;
        }
        int index = char_to_index(*key);
        if (children[index] == 0) {
            return NULL;
        }
        return children[index]->find(key + 1);
    }
};
vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    Trie *root = new Trie();
    Trie *reverse_root = new Trie();
    map<int,int> size;
    for(int i=0;i<words.size();i++) {
        root->insert(words[i].c_str(),int(words[i].length()));
        if(size.find(words[i].size()) != size.end()) size[words[i].size()]++;
        else size.insert({words[i].size(),1});
        reverse(words[i].begin(),words[i].end());
        reverse_root->insert(words[i].c_str(),int(words[i].length()));
    }
    for(int i=0;i<queries.size();i++){
        string current = "";
        for(int j=0;j<queries[i].size();j++){
            if(queries[i][j] != '?') current.push_back(queries[i][j]);
        }
        if(current.length() == 0){
            if(size.find(queries[i].length()) == size.end()) answer.push_back(0);
            else answer.push_back(size[queries[i].length()]);
            continue;
        }
        Trie *origin;
        cout << queries[i][0] << endl;
        if(queries[i][0] != '?'){ //접두사
            origin = root->find(current.c_str());
            if(origin == NULL) answer.push_back(0);
            else answer.push_back(origin->cnt[int(queries[i].length())]);
        }
        else{
            reverse(current.begin(),current.end());
            origin = reverse_root->find(current.c_str());
            if(origin == NULL) answer.push_back(0);
            else answer.push_back(origin->cnt[int(queries[i].length())]);
        }
    }
    return answer;
}
int main(){
    vector<int> b = solution({"frodo", "front", "frost", "frozen", "frame", "kakao"}, {"?????", "????", "r???", "???", "p???","?"});
    for(int i=0;i<b.size();i++) cout << b[i] << " ";
    cout <<endl;
    return 0;
}
