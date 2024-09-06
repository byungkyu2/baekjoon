#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> Graph[101];
vector<int> Graph2[101];


int solution(int n, vector<vector<int>> results) {
    for(int i=0; i< results.size();i++)
    {
        int win, lose;
        win = results[i][0];
        lose = results[i][1];
        Graph[win].push_back(lose);
        Graph2[lose].push_back(win);
    }    
    int answer = 0;
    for(int i=1;i<=n;i++)
    {
        queue<int> q;
        bool visited[101] = {false};
        q.push(i);
        visited[i]= true;
        int cnt= 0;
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            for(int j=0;j<Graph[now].size();j++)
            {
                int next = Graph[now][j];
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
        for(int j=1;j<=n;j++) visited[j] = false;
        q.push(i);
        visited[i] = true;
        while(!q.empty())
        {
            int now = q.front();
            q.pop();
            for(int j=0;j<Graph2[now].size();j++)
            {
                int next = Graph2[now][j];
                if(visited[next]) continue;
                visited[next] = true;
                q.push(next);
                cnt++;
            }
        }
        if(cnt == n-1) answer++;
    }
    
    return answer;
}