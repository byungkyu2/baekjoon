#include<iostream>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;
    int y = board.size();
    int x=board[0].size();
    answer=y*x;
    int psum[1001][1001]={0};
    for(int s=0;s<skill.size();s++){
        int type=skill[s][0];
        int y1=skill[s][1];
        int x1=skill[s][2];
        int y2=skill[s][3];
        int x2=skill[s][4];
        int degree=skill[s][5];
        if(type==1){
            psum[y1][x1]-=degree;
            psum[y2+1][x2+1]-=degree;
            psum[y1][x2+1]+=degree;
            psum[y2+1][x1]+=degree;
        }
        else if(type==2){
            psum[y1][x1]+=degree;
            psum[y2+1][x2+1]+=degree;
            psum[y1][x2+1]-=degree;
            psum[y2+1][x1]-=degree;
        }
    }
    for(int j=1;j<x;j++){
        psum[0][j]+=psum[0][j-1];
        psum[j][0]+=psum[j-1][0];
    }
    for(int i=1;i<y;i++){
        for(int j=1;j<x;j++){
            psum[i][j]=psum[i][j]+psum[i-1][j]+psum[i][j-1]-psum[i-1][j-1];
        }
    }
    for(int i=0;i<y;i++){
        for(int j=0;j<x;j++){
            if(board[i][j]+psum[i][j]<=0)answer--;
        }
    }
    return answer;
}