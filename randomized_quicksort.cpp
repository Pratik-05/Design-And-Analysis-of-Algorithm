#include <iostream>
#include <cstdlib>
using namespace std::chrono;
#define MAX 100
using namespace std;

// Partitioning the array on the basis of values at high as pivot value.
int Partition(int a[], int low, int high)
{
    int pivot, index, i;
    index = low;
    pivot = high;
    for (i = low; i < high; i++)
    {
        // finding index of pivot.
        if (a[i] < a[pivot])
        {
            swap(a[i], a[index]);
            index++;
        }
    }
    swap(a[pivot], a[index]);
    return index;
}
int RandomPivotPartition(int a[], int low, int high)
{
    // Random selection of pivot.
    int pvt, n, temp;
    n = rand();
    pvt = low + n % (high - low + 1); // Randomizing the pivot value from sub-array.
    swap(a[high], a[pvt]);
    return Partition(a, low, high);
}
void quick_sort(int arr[], int p, int q)
{
    // recursively sort the list
    int pindex;
    if (p < q)
    {
        pindex = RandomPivotPartition(arr, p, q); // randomly choose pivot
        // Recursively implementing QuickSort.
        quick_sort(arr, p, pindex - 1);
        quick_sort(arr, pindex + 1, q);
    }
}
int main()
{
    int i;
    int num;
    cout<<"Enter the number of elements in array:- ";
    cin>>num;
    int arr[num];
    for (i = 0; i < num; i++)
        arr[i] = rand()%100000;

    cout<<"Array:- ";
    for(int i=0;i<num;i++)
    {
        cout<<arr[i]<<" ";
    }

    //random_shuffle(arr,num);         // To randomize the array
    quick_sort(arr, 0, num - 1); // sort the elements of array
    cout<<"\nAfter sorting:- ";
    for (i = 0; i < num; i++)
        cout << arr[i] << " ";
    cout << endl;
    
    return 0;
}



/*Output
Enter the number of elements in array:- 22
Array:- 41 18467 6334 26500 19169 15724 11478 29358 26962 24464 5705 28145 23281 16827 9961 491 2995 11942 4827 5436 32391 14604
After sorting:- 41 491 2995 4827 5436 5705 6334 9961 11478 11942 14604 15724 16827 18467 19169 23281 24464 26500 26962 28145 29358 32391

Time taken to execute this program is:- 0 ms*/











