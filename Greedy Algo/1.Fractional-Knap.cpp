#include <bits/stdc++.h>
using namespace std;

struct Item {
   int value;
   int weight;
};

class Solution {
   public:
      static bool comp(Item a, Item b) {
         double r1 = (double) a.value / (double) a.weight;
         double r2 = (double) b.value / (double) b.weight;
         return r1 > r2;
      }

      double fractionalKnapsack(int W, Item arr[], int n) {

         sort(arr, arr + n, comp);

         int curWeight = 0;
         double finalvalue = 0.0;

         for (int i = 0; i < n; i++) {

            if (curWeight + arr[i].weight <= W) {
               curWeight += arr[i].weight;
               finalvalue += arr[i].value;
            } else {
               int remain = W - curWeight;
               finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
               break;
            }
         }

         return finalvalue;
      }
};

int main() {
   int n, weight;
   cout << "Enter the number of items: ";
   cin >> n;
   cout << "Enter the capacity of the knapsack: ";
   cin >> weight;

   Item arr[n];
   cout << "Enter the value and weight of each item:\n";
   for (int i = 0; i < n; i++) {
      cin >> arr[i].value >> arr[i].weight;
   }

   Solution obj;
   double ans = obj.fractionalKnapsack(weight, arr, n);
   cout << "The maximum value is " << setprecision(2) << fixed << ans;
   return 0;
}
/*
Enter the number of items: 3
Enter the capacity of the knapsack: 50
Enter the value and weight of each item:
100 20
60 10
120 30
The maximum value is 240.00

Time complexity: O(nlogn) + O(n)
                 sorting  iteration
*/