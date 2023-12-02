#include <iostream>
#include <algorithm>
using namespace std;

int minCab(int start[], int end[], int n){
    sort(start, start+n); //sort start times
    sort(end, end+n); //sort end times
    
    int cabs_needed=1;
    int result=1;
    
    int i=1; //first train will always arrived at platform 1 that's why not taken 0(index)
    int j=0; //departure time will start from start i.e 0th index
    
    while(i<n && j<n){
        if(start[i]<=end[j]){
            cabs_needed++;
            i++;
        }
        else if(start[i]>=end[j]){
            cabs_needed--;
            j++;
        }
        
        if(cabs_needed>result){
            result=cabs_needed;
        }
    }
    return result;
}

int main(){
    int n;
    cout<<"Enter the number of persons: ";
    cin>>n;
    
    int start[n]; //Start time
    int end[n]; //Departure time
    cout<<"Enter the start time: ";
    for(int i=0; i<n; i++){
        cin>>start[i];
    }
    cout<<"Enter the departure time: ";
    for(int i=0; i<n; i++){
        cin>>end[i];
    }
    cout<<"\n";
    
    int result = minCab(start, end, n);
    cout<<"Minimum number of cabs required is "<<result;
    
    return 0;
}
