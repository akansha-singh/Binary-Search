//greatest element smaller than x
// if x is present in the array then return x, bcoz the floor of x is x
#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int floorSearch(vector<long long>arr,long long low,long long high,long long x)
{
    // If low and high cross each other
    if (low > high)
        return -1;
    // If last element is smaller than x
    if (x >= arr[high])
        return high;
    // Find the middle point
    int mid = (low + high)/2;
    // If middle point is floor.
    if (arr[mid] == x)
        return mid;
    // If x lies between mid-1 and mid
    if (mid > 0 && arr[mid - 1] <= x&& x < arr[mid])
        return mid-1;
    // If x lies between mid and mid+1
    if (mid < high && arr[mid + 1] >= x&& x > arr[mid])
        return mid + 1;
    //If x is smaller than mid, floor must be in left half.
    if (x<arr[mid])
        return floorSearch(arr, low, mid - 1, x);
    // If mid-1 is not floor and x is greater than arr[mid],
    return floorSearch(arr, mid + 1, high, x);
}

    int findFloor(vector<long long> v, long long n, long long x){
        return floorSearch(v,0,n-1,x);
    }
};