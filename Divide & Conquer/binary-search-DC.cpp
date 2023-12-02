#include <iostream>
#include <vector>
using namespace std;

int binarySearch(int arr[], int n, int key, int s, int e)
{
    // Base Case
    if (s > e)
    {
        return -1;
    }
    int mid = s + (e - s) / 2; // base case ke baad declare kro mid ko
    // Solve 1 case
    if (arr[mid] == key)
    {
        return mid;
    }
    // Other will be handled by recursion
    if (arr[mid] > key)
    {
        return binarySearch(arr, n, key, s, mid - 1);
    }
    else
    {
        return binarySearch(arr, n, key, mid + 1, e);
    }
}

int main()
{
    int n;
    cout << "Enter the size of an array:";
    cin >> n;
    int arr[n];
    cout << "\nEnter the elements:";
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int key;
    cout << "\nEnter the key:";
    cin >> key;
    int s = 0;
    int e = n - 1;
    int result = binarySearch(arr, n, key, s, e);
    if (result == -1)
    {
        cout << "\nElement not present";
    }
    else
    {
        cout << "\nElement is present at the index " << result;
    }
    return 0;
}
