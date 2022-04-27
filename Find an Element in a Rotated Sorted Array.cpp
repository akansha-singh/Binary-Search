#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int binarySearch(vector<int>&arr,int l,int r,int x)
    {
	if (r >= l){
		int mid=l+(r-l)/2;
		if (arr[mid] == x)
			return mid;
		if (arr[mid] > x)
			return binarySearch(arr, l, mid - 1, x);
		return binarySearch(arr, mid + 1, r, x);
	}
	return -1;
    }

    int countRotations(vector<int>&arr,int low,int high)
    {
    if (high < low)
        return 0;
    if (high == low)
        return low;
    int mid = low + (high - low)/2; /*(low + high)/2;*/
    if (mid < high && arr[mid+1] < arr[mid])
       return (mid+1);
    if (mid > low && arr[mid] < arr[mid - 1])
       return mid;
    if (arr[high] > arr[mid])
       return countRotations(arr, low, mid-1);
    return countRotations(arr, mid+1, high);
    }
    int search(vector<int>&arr, int target){
        int n=arr.size();
        int p=countRotations(arr,0,n-1);
        int l=binarySearch(arr,0,p,target);
        int r=binarySearch(arr,p,n-1,target);
        if(l!=-1)return l;
        if(r!=-1)return r;
        return -1;
    }
};