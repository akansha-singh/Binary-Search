#include <bits/stdc++.h>
using namespace std;

class Solution{
public:
    int helper(vector<int>& a, int l, int r, int n){
        int mid = l + (r-l)/2;
        if((mid == 0 || a[mid-1]< a[mid]) && (mid==n-1 || a[mid+1] < a[mid])){
            return mid;
        }else if(mid > 0 && a[mid-1] > a[mid]){
            return helper(a,l,mid-1,n);
        }
        return helper(a,mid+1,r,n);
    }
    
    int findPeakElement(vector<int>& a) {
        return helper(a,0,a.size()-1,a.size());
    }
};

