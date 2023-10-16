#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


//lower_bound 实现
int left_bsearch(vector<int>& nums, const int target) {  
    int left = 0, right = nums.size() ;               //注意right的位置为nums.size() ;    
    while (left < right) {                            //搜索区间为[left,right)            
        int mid = left + (right - left) / 2;
        if (nums[mid] < target)    
            left = mid + 1;
        else
            right = mid;
    }
    return left;
}

//upper_bound 实现
int right_bsearch(vector<int>& nums, const int target) {  //右边界
    int left = 0, right = nums.size() ;            //注意right的位置为nums.size() ;   
    while (left < right) {                         //搜索区间为[left,right)  
        int mid = left + (right - left) / 2;
        if (nums[mid] <= target)    
            left = mid + 1;
        else
            right = mid;
    }
    return left;
    
}

