/*
1567. Maximum Length of Subarray With Positive Product
Given an array of integers nums, find the maximum length of a subarray where the product of all its elements is positive.
A subarray of an array is a consecutive sequence of zero or more values taken out of that array.
Return the maximum length of a subarray with positive product.
*/

/*3.Maximum Length of Subarray With Positive Product

TC->
SC->
ASC->

*/
class Solution
{
public:
    int getMaxLen(vector<int> &nums)
    {
        int ans = 0, first_neg = -1, cur_zero = -1, neg = 0;
        for (int i = 0; i < nums.size(); i++)
        {
            // if current number is 0, we can't use any element from index 0 to i anymore,
            // so update zeroPosition, and reset sum and firstNegative.If it is a game, we should refresh the game when we meet 0. if (nums[i] == 0)
            {
                first_neg = -1;
                cur_zero = i;
                neg = 0;
            }
            else if (nums[i] < 0)
            {
                neg++;
                // we only need to know index of first negative number
                if (first_neg == -1)
                {
                    first_neg = i;
                }
            }
            // if neg number are even then we can count the positive numbers from last zero to current index
            if (!(neg & 1))
            {
                ans = max(ans, i - cur_zero);
            }
            else
            {
                ans = max(ans, i - first_neg);
            }
        }

        return ans;
    }
};