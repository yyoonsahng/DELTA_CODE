
#include <string>
#include <vector>
#include <string>
#include<iostream>
#include <algorithm>
#include <queue>
#include<set>
using namespace std;
bool cmp(const string &s1, const string &s2) {
    if (s1.size() == s2.size()) {
        return s1 < s2;
    } else {
        return s1.size() < s2.size();
    }
}
vector<int> solution(vector<string> words, vector<string> queries) {
vector<int> answer;
    vector<string> front;
    vector<string> back;
    for (int i=0;i<words.size();i++) {
            front.push_back(words[i]);
            reverse(words[i].begin(), words[i].end()); //뒤집어서 저장
            back.push_back(words[i]);
    }
    sort(front.begin(), front.end(), cmp);
    sort(back.begin(), back.end(), cmp);
    for (int i=0;i<queries.size();i++) {
        string f(queries[i]);
        string b(queries[i]);
        replace(f.begin(), f.end(), '?', 'a');
        replace(b.begin(), b.end(), '?', 'z');
        if (queries[i][0] == '?') {//접미사인 경우
            reverse(f.begin(), f.end());
            reverse(b.begin(), b.end());
            long y = lower_bound(back.begin(), back.end(), b, cmp) - back.begin() + 1;
            long x = lower_bound(back.begin(), back.end(), f, cmp) - back.begin() + 1;
            answer.push_back(y - x);
        } else {
            long y = lower_bound(front.begin(), front.end(), b, cmp) - front.begin() + 1;
            long x = lower_bound(front.begin(), front.end(), f, cmp) - front.begin() + 1;
            answer.push_back(y - x);
        }
    }
    return answer;
}
int main(){
    //["frodo", "front", "frost", "frozen", "frame", "kakao"]
    //["fro??", "????o", "fr???", "fro???", "pro?"]
    vector<string> a;
    a.push_back("frodo");
    a.push_back("front");
    a.push_back("frost");
    a.push_back("frozen");
    a.push_back("frame");
    a.push_back("kakao");
    vector<string> b;
    b.push_back("?????");
    b.push_back("???do");
    b.push_back("fr???");
    b.push_back("fro???");
    b.push_back("pro?");
    vector<int> c = solution(a, b);
    for(int i=0;i<c.size();i++){
        cout << c[i] << " ";
    }
    cout << endl;
    return 0;
}
