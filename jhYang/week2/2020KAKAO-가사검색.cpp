#include<iostream>
#include<string>
#include<algorithm>
#include<vector>
#include<set>

using namespace std;
const int TrieNode = 10000; // 트라이 노드마다 포인터 개수
 
struct Trie 
{
    Trie *next[TrieNode]; // 다음 노드를 가리키는 포인터 배열
    bool finish; // 이 노드에서 끝나는 전화번호가 있는가?
    bool nextChild; // 이 노드의 자식이 있는가?
 
    // 생성자
    Trie() 
    {
        fill(next, next + TrieNode, nullptr);
        finish = nextChild = false;
    }
 
    // 소멸자
    ~Trie() 
    {
        for (int i = 0; i < TrieNode; i++)
            if (next[i])
                delete next[i];
    }
 
    // 문자열 key를 현재 노드부터 삽입. 삽입 후 일관성이 있는지를 리턴
    bool insert(const char *key) 
    {
        // 문자열의 끝이라면
        if (*key == '\0') 
        {
            finish = true;
 
            // 문자열이 끝났는데도
            // 자식이 있다면 일관성이 없다.
            if (nextChild)
                return 0;
            else
                return 1;
        }
 
        int nextKey = *key - '0';
 
        // 다음으로 가는 트라이가 없다면
        if (!next[nextKey])
            next[nextKey] = new Trie;
 
        nextChild = true;
 
        // 여기까지 왔다는 의미는 트라이의 자식이 분명히 있다는것.
        // 이때 자식에서 일관성이 없던게 밝혀지거나
        // finish가 true라면 일관성이 없다는 의미.
        bool get = next[nextKey]->insert(key + 1);
 
        return !finish && get;
    }
};
vector<int> solution(vector<string> words, vector<string> queries){
    
    for (auto i : queries){

    }
}

// struct mycmp{
//     bool operator() (const string &s1, const string&s2){
//         if(s1.length()<s2.length())
//             return true;
//         if(s1.length()==s2.length()) 
//             return s1<s2?true:false;
//         return false;
//     }
// };
// int foo(int len,string s1,string s2,multiset<string,mycmp> v){
//     auto it1 = v.upper_bound(s2);
//     auto it2 = v.lower_bound(s1);
//     int d1 = distance(v.begin(),it1);
//     int d2 = distance(v.begin(),it2);
//     int ans =  d1-d2;
//     cout<<d1<<" "<<d2<<endl;
//     return ans;
// }
// vector<int> solution(vector<string> words, vector<string> queries){
//     vector<int> answer;
//     multiset<string,mycmp> vv;
//     multiset<string,mycmp> rvv;
//     vector<string> rqueries;
//     vector<string> rpqueries;
//     vector<string> pq;
//     string temp;
//     for(auto i : words){
//         temp = i;
//         reverse(temp.begin(),temp.end());
//         vv.insert(i);
//         rvv.insert(temp);
//     }
//     for(auto i : queries){
//         string temp = i;
//         string temp2 = i;
//         replace(temp.begin(),temp.end(),'?','~');
//         pq.push_back(temp);//대체 쿼리 
//         reverse(temp2.begin(),temp2.end());
//         rqueries.push_back(temp2);//반전 쿼리
//         replace(temp2.begin(),temp2.end(),'?','~');
//         rpqueries.push_back(temp2);//반전+대체 쿼리
//     }
//     for(int i = 0; i<queries.size(); i++){
//         string s1 = queries[i];
//         string s2 = pq[i];
//         string rs1 = rqueries[i];
//         string rs2 = rpqueries[i];
//         int len = s1.length();
//         if(s1[0] == '?'){
//             answer.push_back(foo(len,rs1,rs2,rvv));
//         }
//         else{
//             answer.push_back(foo(len,s1,s2,vv));
//         }   
//     }
//     return answer;
// }
int main(){
    vector<string> words;
    words.push_back("frodo");
    words.push_back("front");
    words.push_back("frost");
    words.push_back("frozen");
    words.push_back("frame");
    words.push_back("kakao");

    vector<string> queries;
    queries.push_back("fro??");
    queries.push_back("????o");
    queries.push_back("fr???");
    queries.push_back("fro???");
    queries.push_back("pro?");
    vector<int> ans = solution(words,queries);
    for(int i : ans)
        cout<<i<<endl;
}
