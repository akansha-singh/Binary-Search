#include <bits/stdc++.h>
using namespace std;

class Solution{
  public:
    int first(vector<int>&arr, int low, int high, int x, int n)
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
 
    int last(vector<int>&arr, int low, int high, int x, int n)
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
    vector<int> firstAndLast(vector<int> &arr, int n, int x) {
        int firstO=first(arr, 0, n - 1, x, n);
        int lastO=last(arr, 0, n - 1, x, n);
        
        vector<int>v;
        if(firstO==-1){
            v.push_back(-1);
            return v;
        }
        v.push_back(firstO);
        v.push_back(lastO);
        return v;
    }
};
//1334