#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> points, vector<vector<int>> routes) {
    int answer=0;
    int completed=0;
    int pos[100][2];
    int cur_route[100]={0};
    int x=routes.size();
    for(int i=0;i<x;i++){
        cur_route[i]=1;
        pos[i][0]=(points[routes[i][0]-1][0]);
        pos[i][1]=(points[routes[i][0]-1][1]);
    }
    while(1){
        int map[101][101]={0};
        for(int i=0;i<x;i++){//위험한지 판단하기
            if(pos[i][0]==-1||pos[i][1]==-1)continue;
            if(map[pos[i][0]][pos[i][1]]==1)answer++;
            map[pos[i][0]][pos[i][1]]++;
        }
        for(int i=0;i<x;i++){//이동하기
            if(cur_route[i]>routes[i].size())continue;
            int destpoint=routes[i][cur_route[i]];
            int destx=points[destpoint-1][0];
            int desty=points[destpoint-1][1];
            if(pos[i][0]==destx&&pos[i][1]==desty)cur_route[i]++;
            if(cur_route[i]==routes[i].size()){
                completed++;
                cur_route[i]++;
                pos[i][0]=-1;
                pos[i][1]=-1;
            }
            if(cur_route[i]>routes[i].size())continue;
            destpoint=routes[i][cur_route[i]];
            destx=points[destpoint-1][0];
            desty=points[destpoint-1][1];
            if(pos[i][0]>destx)pos[i][0]--;
            else if(pos[i][0]<destx)pos[i][0]++;
            else if(pos[i][1]>desty)pos[i][1]--;
            else if(pos[i][1]<desty)pos[i][1]++;
        }
        if(completed==x)break;
         
    }
 
    
    return answer;
}