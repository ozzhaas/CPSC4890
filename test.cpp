#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;


int countOne(int arr[], int n){
    int i = 0;

    // To store number of ones in
    // current segment of all 1s.
    int len = 0;

    // To store number of subarrays
    // having product equal to 1.
    int ans = 0;
    cout << "n = " << n << endl;
    while(i < n){

        // If current element is 1, then
        // find length of segment of 1s
        // starting from current element.
        if(arr[i] == 1){
            len = 0;
            while(i < n && arr[i] == 1){
                i++;
                len++;
            }

            // add number of possible
            // subarrays of 1 to result.
            ans += (len*(len+1)) / 2;
        }
        i++;
    }

    return ans;
}

/// Function to find number of subarrays having
/// product exactly equal to k.
int findSubarrayCount(int arr[], int n, int k)
{
    int start = 0, endval = 0, p = 1,
        countOnes = 0, res = 0;

    while (endval < n)
    {
        p *= (arr[endval]);

        // If product is greater than k then we need to decrease
        // it. This could be done by shifting starting point of
        // sliding window one place to right at a time and update
        // product accordingly.
        if(p > k)
        {
            while(start <= endval && p > k)
            {
                p /= arr[start];
                start++;
            }
        }


        if(p == k)
        {
            // Count number of succeeding ones.
            countOnes = 0;
            while(endval + 1 < n && arr[endval + 1] == 1)
            {
                countOnes++;
                endval++;
            }

            // Update result by adding both new subarray
            // and effect of succeeding ones.
            res += (countOnes + 1);

            // Update sliding window and result according
            // to change in sliding window. Here preceding
            // 1s have same effect on subarray as succeeding
            // 1s, so simply add.
            while(start <= endval && arr[start] == 1 && k!=1)
            {
                res += (countOnes + 1);
                start++;
            }

            // Move start to correct position to find new
            // subarray and update product accordingly.
            p /= arr[start];
            start++;
        }

        endval++;
    }
    return res;
}

// Driver code
int main()
{
    int arr1[] = { 2, 1, 1, 1, 3, 1, 1, 4};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    cout << "n1 in test main = " << n1 << endl;
    int k = 1;

    if(k != 1)
        cout << findSubarrayCount(arr1, n1, k) << "\n";
    else
        cout << countOne(arr1, n1) << "\n";

    int arr2[] = { 2, 1, 1, 1, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    cout << "n2 in test main = " << n2 << endl;
    k = 4;

    if(k != 1)
        cout << findSubarrayCount(arr2, n2, k) << "\n";
    else
        cout << countOne(arr2, n2) << "\n";
    return 0;
}
