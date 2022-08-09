/*
53. Maximum Subarray
Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
A subarray is a contiguous part of an array.
*/

/*1. Kadane's Algorithm

TC->
SC->
ASC->

*/
class Solution
{
public:
    int kadaneAlgo(vector<int> &nums)
    {
        int max_sum = nums[0];
        int cur_sum = nums[0];
        for (int i = 1; i < nums.size(); i++)
        {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            max_sum = max(cur_sum, max_sum);
        }
        return max_sum;
    }

    int maxSubArray(vector<int> &nums)
    {
        return kadaneAlgo(nums);
    }
};