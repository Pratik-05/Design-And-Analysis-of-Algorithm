#include<iostream>
using namespace std;

int binarysearch(int arr[],int size, int key)
{
    int start=0;
    int end=size-1;

    int mid = start+ (end-start)/2;

    while(start<=end)
    {
        
        if(arr[mid]==key)
        {
            return mid;
        }
        //go to right wala part
        else if(key>arr[mid])
        {
            start=mid+1;
        }
        else{ //key < arr[mid]
            end=mid-1;
        }
        mid = start+ (end-start)/2;
    }
    return -1;
}


int main()
{
    int n;
    cin >> n;
    int arr[100000];
    
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand();
    }
    sort(arr, arr + n);

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    int key;
    cin >> key;
    int s = 0;
    int e = n - 1;
    int result = binarysearch(arr, n, key);
    cout << result;
}