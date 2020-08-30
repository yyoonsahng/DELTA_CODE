#include<iostream>
#include <string>
#include <vector>
#include<algorithm>

using namespace std;

string METATAG="<meta property=\"og:url\" content=\"";
string LINKTAG="<a href=\"";

int solution(string word, vector<string> pages) {
    int n = pages.size();
    for(int i = 0; i<n; i++){
        transform(pages[i].begin(),pages[i].end(),pages[i].begin(),::tolower);
    }
    transform(word.begin(),word.end(),word.begin(),::tolower);
    int answer = 0;
    vector<int> bscore(n);
    vector<double> exlscore(n);
    vector<double> inlscore(n);
    vector<double> lnkscore(n);
    vector<string> url(n);
    vector<vector<string> > links(n);

    for(int i = 0; i<pages.size(); i++){
        cout<<"#"<<i<<endl;
        for(int j = 0; j<pages[i].size(); j++){
            if(j>=pages[i].size()-METATAG.length()){ 
                break;
            }
            if(pages[i].substr(j,METATAG.length())==METATAG){
                int start = j+METATAG.length();
                int k = 0;
                while(pages[i].substr(start+k,3)!="\"/>"){
                    k++;
                }
                url[i] = pages[i].substr(start,k);
                j+=k;
            }
            else if(pages[i].substr(j,LINKTAG.length())==LINKTAG){
                int start = j+LINKTAG.length();
                int k = 0;
                while(pages[i].substr(start+k,2)!="\">"){
                    k++;
                }
                string link = pages[i].substr(start,k);
                links[i].push_back(link);
                j+=k;
                exlscore[i]++;
            }
            
        }
        
        for(int j = 0; j<pages[i].size(); j++){
            if(j>pages[i].size()-word.length()+1){
                break;
            }
            if(pages[i].substr(j,word.length()) == word){
                if(isalpha(pages[i][j-1])||isalpha(pages[i][j+word.length()]))
                    continue;
                cout<<pages[i].substr(j,word.length())<<endl;
                bscore[i]++;
                j++;
            }
        }
    }

    for(int i = 0; i<n; i++){
        lnkscore[i]+=(bscore[i]/exlscore[i]);
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<links[i].size(); j++){
            for(int k = 0; k<n; k++){
                if(links[i][j] == url[k]){
                    inlscore[k]+=lnkscore[i];
                }
            }
        }
    }
    double score = -1;
    for(int i = 0; i<n; i++){
        if(score<bscore[i]+inlscore[i]){
            score = bscore[i]+inlscore[i];
            answer = i;
        }
    }
    for(int i = 0; i<pages.size(); i++){
        //cout<<url[i]<<endl;
        cout<<i<<" bscore "<<bscore[i]<<endl;
        cout<<i<<" lnkscore "<<lnkscore[i]<<endl;
        cout<<i<<":"<<bscore[i]+inlscore[i]<<endl;
    }
    return answer;
}
int main(){
    string a = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>";
    string b = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>";
    string c = "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>";
    vector<string> pages;
    pages.push_back(a);
    pages.push_back(b);
    pages.push_back(c);
    string word = "blind";
    cout<<solution(word, pages);
}