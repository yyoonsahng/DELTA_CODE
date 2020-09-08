// 셔틀버스

#include <iostream>
#include <algorithm>
#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
    string answer = "";
    vector<int> v;
    for(auto i : timetable)
        v.push_back(atoi(i.substr(0,2).c_str())*60+atoi(i.substr(3,5).c_str()));
    vector<vector<int> > b(n);
    sort(v.begin(), v.end());
    int bus;
    int idx = 0;
    for(int k = 0; k<n; k++){
        bus=60*9+k*t;
        for(int j = 0; j<m; j++){
            if(idx>=v.size()) break;
            if(v[idx]<=bus){
                b[k].push_back(v[idx]);
                idx++;
            }
        }
    }
    int ans;
    if(b[b.size()-1].size()<m)
        ans = 9*60+(b.size()-1)*t;
    else
        ans = b[b.size()-1][m-1]-1;
    string HH = to_string(ans/60);
    string MM = to_string(ans%60);
    if(HH.length()==1) HH = "0"+HH;
    if(MM.length()==1) MM = "0"+MM;
    return HH+":"+MM;
}

int main(){
    int n,t,m;
    cin>>n>>t>>m;
    vector<string> timetable;
    timetable.push_back("18:00");
    cout<<solution(n,t,m,timetable);
}