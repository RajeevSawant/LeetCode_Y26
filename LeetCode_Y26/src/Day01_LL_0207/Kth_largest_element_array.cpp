/*
 * Kth_largest_element_array.cpp
 *
 *  Created on: Feb 7, 2026
 *      Author: Rajeev Sawant
 *
 *
 *
 *
 *
215. Kth Largest Element in an Array

Given an integer array nums and an integer k, return the kth largest element in the array.

Note that it is the kth largest element in the sorted order, not the kth distinct element.

Can you solve it without sorting?



Example 1:

Input: nums = [3,2,1,5,6,4], k = 2
Output: 5
Example 2:

Input: nums = [3,2,3,1,2,4,5,5,6], k = 4
Output: 4


Constraints:

1 <= k <= nums.length <= 105
-104 <= nums[i] <= 104
 */

   /*
         Algorithm: Quick select
         1. Medium case time complexity is O(n)

        - Quick Select is similar to Quick sort

    */

#include<vector>
#include <iostream>
using namespace std;


    int quickSelect(vector<int>& nums, int k){

        int pivot = nums[rand() % nums.size()];

        vector<int> right;
        vector<int> left;
        vector<int> mid;

        for(int num: nums){
            if (num > pivot){
                right.push_back(num);
            }else if (num < pivot){
                left.push_back(num);
            }else{
                mid.push_back(num);
            }
        }


        if (k <= right.size()){
           return quickSelect(right, k);
        }

        if (right.size() + mid.size() < k){
           return quickSelect(left, k - right.size() - mid.size());
        }

        return pivot;
    }


    int findKthLargest(vector<int>& nums, int k) {

        return quickSelect(nums, k);
    }

/*
 * Youtube : https://www.youtube.com/watch?v=XEmy13g1Qxc&t=828s
 */



