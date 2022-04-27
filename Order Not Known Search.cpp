#include <bits/stdc++.h>
using namespace std;

//It returns location of x in given array arr[l..r] is present, otherwise -1
int binarySearchAsc(int arr[], int l, int r, int x)
{   
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearchAsc(arr, l, mid - 1, x);
        
		// Else the element can only be present
		// in right subarray
		return binarySearchAsc(arr, mid + 1, r, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}

int binarySearchDsc(int arr[], int l, int r, int x)
{
	if (r >= l) {
		int mid = l + (r - l) / 2;

		// If the element is present at the middle
		// itself
		if (arr[mid] == x)
			return mid;

		// If element is smaller than mid, then
		// it can only be present in left subarray
		if (arr[mid] > x)
			return binarySearchDsc(arr, mid + 1, r, x);
        
		// Else the element can only be present
		// in right subarray
		return binarySearchDsc(arr, l, mid - 1, x);
	}

	// We reach here when element is not
	// present in array
	return -1;
}


int main(void)
{
	int arr[] = { 2, 3, 4, 10, 40 };
	int x = 10;
	int n = sizeof(arr) / sizeof(arr[0]);
    int result;
    //first check if the size of array is greater or equal to 2
    if(arr[0]<arr[1]){
        result = binarySearchAsc(arr, 0, n - 1, x);
    }
	if(arr[0]>arr[1]){
        result = binarySearchDsc(arr, 0, n - 1, x);
    }
	(result == -1)
		? cout << "Element is not present in array"
		: cout << "Element is present at index " << result;
	return 0;
}


