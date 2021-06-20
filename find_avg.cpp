#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;

vector<int> arr;
int N = 0;




int main (void) {
    vector<int> subArr;

    int count = 0;



    int arr[] = {10, 2, 7, 30, 20, 50, 40, 23, 54, 61, 15, 67};
    int k = 6;
    N = sizeof(arr) / sizeof(arr[0]);
    int res = 0;

    // Calculate all subarrays
    for (int i = 0; i < N; i++) {
      int sum = 0;
      for (int j = i; j < N; j++) {
        // Calculate required sum
        sum += arr[j];
        // Check if sum is equal to
        // required sum
        if (sum/N == k)
          res++;
      }
    }
    cout << (res) << endl;


    return 0;
}
