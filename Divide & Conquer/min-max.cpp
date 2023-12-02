#include <iostream>
using namespace std;

// Function to find minimum and maximum element in an array using divide and conquer
void findMinMax(int arr[], int low, int high, int& minVal, int& maxVal) {
    if (low == high) {
        // Base case: only one element is present in the array
        minVal = maxVal = arr[low];
    } else if (high - low == 1) {
        // Base case: only two elements are present in the array
        if (arr[low] < arr[high]) {
            minVal = arr[low];
            maxVal = arr[high];
        } else {
            minVal = arr[high];
            maxVal = arr[low];
        }
    } else {
        // Recursive case: more than two elements are present in the array
        int mid = (low + high) / 2;
        int minVal1, maxVal1, minVal2, maxVal2;
        findMinMax(arr, low, mid, minVal1, maxVal1);
        findMinMax(arr, mid + 1, high, minVal2, maxVal2);
        minVal = min(minVal1, minVal2);
        maxVal = max(maxVal1, maxVal2);
    }
}

// Driver code
int main() {
    int n;
    cout << "Enter the size of the array: ";
    cin >> n;
    int arr[n];
    cout << "Enter the elements of the array: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    int minVal, maxVal;
    findMinMax(arr, 0, n - 1, minVal, maxVal);
    cout << "Minimum value: " << minVal << endl;
    cout << "Maximum value: " << maxVal << endl;
    return 0;
}
