//
//  main.cpp
//  JobSequenceWithDeadLines
//
//  Created by Sivaprasad Tamatam on 19/09/20.
//
/*Given an array of jobs where every job has a deadline and associated profit if the job is finished before the deadline. It is also given that every job takes single unit of time, so the minimum possible deadline for any job is 1. How to maximize total profit if only one job can be scheduled at a time.*/
#include <iostream>
using namespace std;

class Job{
public:
    char ID;
    int dead;
    int profit;
  
    Job(char c, int d, int p): ID(c), dead(d), profit(p){
        
    }
};

bool cmp(Job a, Job b){
    return a.profit > b.profit;
}

void JobScheduling(Job a[], int n){
    sort(a, a+n, cmp);
    int result[n];
    bool slot[n];
    
    for( int i =0; i<n; ++i)
    slot[i] = false;
    
    for( int i = 0; i<n; ++i){
        for( int j = min(n, a[i].dead) -1; j>=0; --j){
            if(slot[j] == false){
                result[j] = i;
                slot[j] = true;
                break;
            }
        }
    }
    
    for( int i =0; i<n; ++i){
        if(slot[i])
            cout<<a[result[i]].ID<<"    ";
    }
    
}

int main(int argc, const char * argv[]) {
    Job arr[] = { {'a', 2, 100}, {'b', 1, 19}, {'c', 2, 27},
                       {'d', 1, 25}, {'e', 3, 15}};
        int n = sizeof(arr)/sizeof(arr[0]);
    cout<<endl;
    JobScheduling(arr, n);
    cout<<endl;
    return 0;
}
