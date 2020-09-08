#include<iostream>
#include<algorithm>
#include<string>
#include<set>
#include<vector>
using namespace std;

int main() {
    string find;
    int num,element;
    int answer = 987654321;
    set<int> v;
    cin >> find >> num;
    for (int i = 0; i < num; i++) {
        cin >> element;
        v.insert(element);
    }
    int find_int = atoi(find.c_str());
    int cmp = abs(find_int - 100);
    for (int i = 0; i <= 1000000; i++) {
        string cand = to_string(i);
        bool check = false;
        for (int j = 0; j < cand.size(); j++) {
            if (v.find(cand[j] - 48) != v.end()) {
                check = true;
                break;
            }
        }
        answer = min(answer, cmp);
        if (!check) {
            answer = min(answer, abs(i - find_int) + int(cand.size()));
        }
    }
    cout << answer << endl;
    return 0;
}
