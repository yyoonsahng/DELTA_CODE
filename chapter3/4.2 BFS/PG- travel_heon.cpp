#include <string>
#include <vector>
#include <algorithm>
using namespace std;
bool dfs(string here, vector<vector<string>>& tickets, vector<bool>& visited, vector<string>& tmp, vector<string>& answer, int cnt) {
	tmp.push_back(here);
	if (cnt == tickets.size()) {
		answer = tmp;
		return true;
	}
	for (int i = 0; i < tickets.size(); i++) {
		if (tickets[i][0] == here and !visited[i]) {
			visited[i] = true;
			if (dfs(tickets[i][1], tickets, visited, tmp, answer, cnt + 1)) return true;
			visited[i] = false;
		}
	}
	tmp.pop_back();
	return false;
}
vector<string> solution(vector<vector<string>> tickets) {
	vector<string> answer;
	vector<bool> visited(tickets.size(), false);
	sort(tickets.begin(), tickets.end());
	vector<string> temp;
	dfs("ICN", tickets, visited, temp, answer, 0);
	return answer;
}