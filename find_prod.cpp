#include <iostream>
#include <cstdio>
#include <cmath>
#include <vector>

using namespace std;



int subArr_prod_one (int arr[], int n) {
    int i = 0;
    int len = 0;
    int result = 0;

    while (i < n) {
        //If the current element in the array is 1
        //increment to find the length of the subarray starting from
        //this current position.
        if (arr[i] == 1) {
            len = 0;
            while (i < n && arr[i] == 1) {
                i++;
                len++;
            }
            //Add this new possible subarray to the result
            result += (len * (len + 1)) / 2;
        }
        i++;
    }

    return result;
}

int numSubArrays(int arr[], int n, int k) {
    int start = 0, endNum = 0, prod = 1, result = 0, countProdOne = 0;


    while (endNum < n) {
        //While endNum is less than n, calculate the product
        prod *= (arr[endNum]);

        //If product > k then decrease it. Move sliding window one space
        //to the right and update the new product until it is less than
        //or equal to k
        if (prod > k) {
            while (start <= endNum && prod > k) {
                prod /= arr[start];
                start++;
            }
        }

        if (prod == k) {
            //keep a running count of future ones in the array
            countProdOne = 0;
            while (((endNum + 1) < n) && (arr[endNum + 1] == 1)) {
                countProdOne++;
                endNum++;
            }
            //Make sure to update result so that it has the new subarray
            //and the future ones
            result += (countProdOne + 1);


            //Need to move sliding window
            //Update the result as well as the window
            //Now account for preceding ones and add them to the result
            while (start <= endNum && arr[start] == 1 && k != 1) {
                result += (countProdOne + 1);
                start++;
            }
            //Move start back to appropriate position to continue finding
            //new subarrays and also update the product
            prod /= arr[start];
            start++;
        }
        endNum++;
    }
    return result;
}



int main (void) {

    int arr1[100];

    for (int i = 1; i <= 100; i++) {
        arr1[i] = i;
    }

    unsigned int n1 = sizeof(arr1) / sizeof(arr1[0]);
    int k = 1;

    if (k != 1) {
        cout << numSubArrays(arr1, n1, k) << endl;
    }
    else {
        cout << subArr_prod_one(arr1, n1) << endl;
    }

    int arr2[100];

    for (int i = 1; i <= 100; i++) {
        arr2[i] = i;
    }

    unsigned int n2 = sizeof(arr2) / sizeof(arr2[0]);

    k = 24;

    if (k != 1) {
        cout << numSubArrays(arr2, n2, k) << endl;
    }
    else {
        cout << subArr_prod_one(arr2, n2) << endl;
    }


    return 0;
}
