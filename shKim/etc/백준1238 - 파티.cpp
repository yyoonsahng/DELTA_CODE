//
//  백준1238 - 파티.cpp
//  DeltaCode
//
//  Created by 김성헌 on 2020/09/08.
//  Copyright © 2020 김성헌. All rights reserved.
//

#include<iostream>
#include<vector>
#include<queue>
#include<memory.h>

using namespace std;
int V, E, dest;
int dist[1001][1001];

vector<pair<int, int>> graph[20001];

struct cmp {
    bool operator()(pair<int,int> a,pair<int,int> b) {
        if (a.second == b.second) return a.first > b.first;
        return a.second > b.second;
    }
};

priority_queue<pair<int, int>, vector<pair<int, int>>, cmp> q;

void dijkstra(int start) {
    fill(dist[start], dist[start]+1001, 1e9);
    q.push({ start ,0});
    dist[start][start] = 0;
    while (!q.empty()) {
        int x = q.top().first;
        int weight = q.top().second;
        q.pop();
        for (int i = 0; i < graph[x].size(); i++) {
            int next_x = graph[x][i].first;
            int next_weight = graph[x][i].second;
            if (dist[start][next_x] > weight + next_weight) {
                q.push({ next_x,weight + next_weight });
                dist[start][next_x] = weight + next_weight;
            }
        }
    }
}
int main() {
    cin >> V >> E;
    cin >> dest;
    for (int i = 0; i < E; i++) {
        int begin, end, weight;
        cin >> begin >> end >> weight;
        graph[begin].push_back({ end,weight });
    }
    for(int i=1;i<=V;i++) dijkstra(i);
    int answer = -1;
    for(int i=1;i<=V;i++) answer = max(answer, dist[i][dest] + dist[dest][i]);
    cout << answer << endl;
    return 0;
}
