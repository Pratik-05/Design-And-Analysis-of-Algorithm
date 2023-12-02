#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the maximum number of activities that can
    //be performed by a single person.
    static bool comp(pair<int,int> a,pair<int,int> b){
        if(a.second == b.second) return a.first < b.first;
        return a.second < b.second;
    }

    int activitySelection(vector<int> start, vector<int> end, int n, vector<int>& selected)
    {
        // Your code here
        vector<pair<int,int> > v(n);
        for(int i=0;i<n;i++) {
            v[i] = {start[i],end[i]};
        }
        sort(v.begin(),v.end(),comp);
        int i=0;
        int j=1;
        int c=1;
        selected.push_back(0);
        while(j<n)
        {
            if(v[i].second <= v[j].first)
            {
                c++;
                i=j;
                j++;
                selected.push_back(i);
            }
            else
            {
                j++;
            }
        }
        return c;
    }
};

int main()
{
    //size of array
    int n;
    cout<<"Enter the size of an array: "<<endl;
    cin >> n; cout<<endl;
    vector<int> start(n), end(n);

    cout<<"Enter the start time of each activity: "<<endl;
    //adding elements to arrays start and end
    for(int i=0;i<n;i++) {
        cin>>start[i];
    }

    cout<<"Enter the end time of each activity: "<<endl;    
    for(int i=0;i<n;i++) {
        cin>>end[i];
    }cout<<endl;

    Solution ob;
    vector<int> selected;
    //function call
    int max_activities = ob.activitySelection(start, end, n, selected);

    cout<<"Max Number of activities can be held are : "<<max_activities<<endl;
    cout<<"The selected activities are: ";
    for(int i=0;i<selected.size();i++) {
        cout<<selected[i]<<" ";
    }
    cout<<endl;

    return 0;
}
/*
Enter the size of an array: 
6

Enter the start time of each activity: 
1 3 0 5 8 5
Enter the end time of each activity: 
2 4 6 7 9 9

Max Number of activities can be held is : 4
The selected activities are: 0 1 3 5 
*/