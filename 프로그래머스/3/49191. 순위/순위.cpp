#include <string>
#include <vector>
#include <queue>
using namespace std;

vector<int> graph1[101];
vector<int> graph2[101];
int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    for(int i=0;i<results.size();i++){
        graph1[results[i][0]].push_back(results[i][1]);
        graph2[results[i][1]].push_back(results[i][0]);
    }
    for(int i=1;i<=n;i++){
        int visited1[101]={0};
        int cnt=0;
        visited1[i]=1;
        queue<int>q1;
        q1.push(i);
        while(!q1.empty()){
            int now=q1.front();q1.pop();
            for(int j=0;j<graph1[now].size();j++){
                int next=graph1[now][j];
                if(visited1[next]==1)continue;
                visited1[next]=1;
                cnt++;
                q1.push(next);
            }
        }
        int visited2[101]={0};
        visited2[i]=1;
        queue<int>q2;
        q2.push(i);
        while(!q2.empty()){
            int now=q2.front();q2.pop();
            for(int j=0;j<graph2[now].size();j++){
                int next=graph2[now][j];
                if(visited2[next]==1)continue;
                visited2[next]=1;
                cnt++;
                q2.push(next);
            }
        }
        //cout << cnt;
        //return cnt;
        if(cnt==n-1)answer++;
    }
    return answer;
}