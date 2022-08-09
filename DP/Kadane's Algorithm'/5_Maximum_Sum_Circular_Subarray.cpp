/*
918. Maximum Sum Circular Subarray
Medium

Given a circular integer array nums of length n, return the maximum possible sum of a non-empty subarray of nums.
A circular array means the end of the array connects to the beginning of the array. Formally, the next element of nums[i] is nums[(i + 1) % n]
and the previous element of nums[i] is nums[(i - 1 + n) % n].
A subarray may only include each element of the fixed buffer nums at most once. Formally, for a subarray nums[i], nums[i + 1], ..., nums[j],
there does not exist i <= k1, k2 <= j with k1 % n == k2 % n.
*/

/*5.Maximum Sum Circular Subarray

TC->
SC->
ASC->

*/
/*
Explanation

So there are two case.
Case 1. The first is that the subarray take only a middle part, and we know how to find the max subarray sum.
Case2. The second is that the subarray take a part of head array and a part of tail array.
We can transfer this case to the first one.
The maximum result equals to the total sum minus the minimum subarray sum.

So the max subarray circular sum equals to
max(the max subarray sum, the total sum - the min subarray sum)

Prove of the second case

max(prefix+suffix)
= max(total sum - subarray)
= total sum + max(-subarray)
= total sum - min(subarray)

Corner case

Just one to pay attention:
If all numbers are negative, maxSum = max(A) and minSum = sum(A).
In this case, max(maxSum, total - minSum) = 0, which means the sum of an empty subarray.
According to the deacription, We need to return the max(A), instead of sum of am empty subarray.
So we return the maxSum to handle this corner case.


*/
class Solution
{
public:
    int kadaneAlgo(vector<int> &nums)
    {
        int max_sum = nums[0];
        int cur_sum = nums[0];
        int cur_min = nums[0];
        int total = nums[0];
        int min_sum = nums[0];

        for (int i = 1; i < nums.size(); i++)
        {
            cur_sum = max(cur_sum + nums[i], nums[i]);
            max_sum = max(cur_sum, max_sum);
            cur_min = min(cur_min + nums[i], nums[i]);
            min_sum = min(min_sum, cur_min);
            total += nums[i];
        }

        if (total == min_sum)
            return max_sum;
        return max(max_sum, total - min_sum);
    }

    int maxSubarraySumCircular(vector<int> &nums)
    {
        return kadaneAlgo(nums);
    }
};