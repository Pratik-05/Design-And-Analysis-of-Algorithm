#include<bits/stdc++.h>
using namespace std; 

// A structure to represent a job 
struct Job 
{ 
    int id;     // Job Id 
    int dead;   // Deadline of job 
    int profit; // Profit if job is over before or on deadline 
}; 

class Solution 
{
    public:
    static bool comp(Job a,Job b){
        return a.profit>b.profit;
    }
    //Function to find the maximum profit and the number of jobs done.
    void JobScheduling(Job arr[], int n) 
    { 
        sort(arr,arr+n,comp);
        bool* done = new bool[n];
        memset(done, 0, n * sizeof(bool));
        int day = 0, profit = 0;

        cout<<"Sequence will be : ";
        for(int i = 0; i < n; i++)
        {
            for(int j = min(n,arr[i].dead-1);j>=0;j--)
            {
                if(done[j] == false)
                {
                    day += 1;
                    profit += arr[i].profit;
                    done[j] = true;
                    cout << arr[i].id <<" ";
                    break;
                }
            }
        } 
        cout << endl;
        
        cout<<"No. of jobs done are : "<<day<<endl;
        cout<<"Maximum Profit is : "<<profit<<endl;
        
        delete[] done;
    } 
};

int main() 
{ 
    
        int n;
        //size of array
        cout<<"Enter the size of the array : "<<endl; 
        cin >> n;
        cout<<endl;

        Job arr[n];

        cout<<"Enter the Job Id, Deadline and Profit : "<<endl;
        //adding id, deadline, profit
        for(int i = 0;i<n;i++)
        {
            int x, y, z;
            cin >> x >> y >> z;
            arr[i].id = x;
            arr[i].dead = y;
            arr[i].profit = z;
        }cout<<endl;

        Solution ob;
        //function call
        ob.JobScheduling(arr, n);

    return 0; 
}

/* OUTPUT:
Enter the size of the array : 
4

Enter the Job Id, Deadline and Profit : 
1 4 20
2 1 10
3 1 40
4 1 30

Sequence will be : 3 1 
No. of jobs done are : 2
Maximum Profit is : 60
*/