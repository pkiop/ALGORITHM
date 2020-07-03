
#include <string>
#include <vector>
#include <queue>
#include <iostream>

using namespace std;

queue<int> q;
int solution(int bridge_length, int weight, vector<int> truck_weights) {
    
    for(int i=0;i<bridge_length;++i) {
        q.push(0);
    }
    int time = 0;
    int nowTruckidx = 0;
    int nowWeight = 0;
    int anscnt = truck_weights.size();
    while(1) {
        int qf = q.front();
        cout << "qf : " << qf << endl;
        cout << "q.size() : " << q.size() << endl;
        q.pop();
        if(qf != 0) {
            anscnt--;
            nowWeight -= qf;
            if(anscnt == 0) {
                return time+1;
            }
        }
        
        if(nowTruckidx != truck_weights.size()) {
            if(weight >= nowWeight + truck_weights[nowTruckidx]) {
                q.push(truck_weights[nowTruckidx]);
                nowWeight += truck_weights[nowTruckidx++];
            }
            else {
                q.push(0);
            }

        }
        time++;

    }
}