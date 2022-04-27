#include <bits/stdc++.h>
using namespace std;

class Solution{
public:	
	/* if x is present in arr[] then returns the count
		of occurrences of x, otherwise returns 0. */
	int first(int arr[], int low, int high, int x, int n)
    {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == 0 || x > arr[mid - 1]) && arr[mid] == x)
            return mid;
        else if (x > arr[mid])
            return first(arr, (mid + 1), high, x, n);
        else
            return first(arr, low, (mid - 1), x, n);
    }
    return -1;
    }
 
    int last(int arr[], int low, int high, int x, int n)
    {
    if (high >= low) {
        int mid = low + (high - low) / 2;
        if ((mid == n - 1 || x < arr[mid + 1]) && arr[mid] == x)
            return mid;
        else if (x < arr[mid])
            return last(arr, low, (mid - 1), x, n);
        else
            return last(arr, (mid + 1), high, x, n);
    }
    return -1;
    }
	int count(int arr[], int n, int x){
	    int firstO=first(arr, 0, n - 1, x, n);
        int lastO=last(arr, 0, n - 1, x, n);
        //cout<<firstO<<" "<<lastO;
        if(firstO==-1)return 0;
        return lastO-firstO+1;
	}
};