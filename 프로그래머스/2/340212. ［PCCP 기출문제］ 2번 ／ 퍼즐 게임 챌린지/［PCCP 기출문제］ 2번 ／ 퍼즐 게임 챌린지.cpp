#include<iostream>
#include <string>
#include <vector>

using namespace std;
long long int puzzle(vector<int> diffs, vector<int> times, long long limit, int level){
    long long int time=times[0];
    for(int i=1;i<diffs.size();i++){
        if(diffs[i]>level)time+=(diffs[i]-level)*(times[i]+times[i-1])+times[i];
        else time+=times[i];
    }
    return time;
}
int solution(vector<int> diffs, vector<int> times, long long limit) {
    int answer = 100000;
    int st=1;
    int ed=100000;
    while(st<=ed){
        int mid=(st+ed)/2;
        if(limit<puzzle(diffs,times,limit,mid)){ //레벨 올려야함
            st=mid+1;
        }
        else{//레벨 낮춰야함
            answer=mid;
            ed=mid-1;
        }
    }
    return answer;
}