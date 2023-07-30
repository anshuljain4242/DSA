#include<iostream>
#include<vector>
#include<math.h>
using namespace std;


double timeRequired(vector<int>& dist, int speed){
    double time = 0.0;
    for(int i=0; i<dist.size(); i++){
        double t = (double) dist[i]/(double) speed;
        // round off to the next integer, if not the last ride
        time += ((i == dist.size()-1) ? t : ceil(t));
    }
    return time;
}
int minSpeedOnTime(vector<int>& dist, double hour) {

    int left = 0;
    int right = 10000000;
    int minSpeed = -1;

    while(left <= right){
        int mid = left + (right - left)/2;

        if(timeRequired(dist, mid) <= hour){
            minSpeed = mid;
            right = mid - 1;
        }
        else{
            left = mid + 1;
        }   
    } 
    return minSpeed;
}