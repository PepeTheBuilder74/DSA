/*
1014. Best Sightseeing Pair
You are given an integer array values where values[i] represents the value of the ith sightseeing spot. Two sightseeing spots i and j have a distance j - i between them.
The score of a pair (i < j) of sightseeing spots is values[i] + values[j] + i - j: the sum of the values of the sightseeing spots, minus the distance between them.
Return the maximum score of a pair of sightseeing spots.
*/

/*4.Best Sightseeing Pair

TC->
SC->
ASC->

*/
/*Basic DP problem :
just count the previous max and add up it to current element and store the max value

Algorithm :

Count the current best score in all previous sightseeing spot.
Note that, as we go further, the score of previous spot decrement.

cur will record the best score that we have met.
We iterate each value a in the array A,
update res by max(res, cur + a)

Also we can update cur by max(cur, a).
Note that when we move forward,
all sightseeing spot we have seen will be 1 distance further.

So for the next sightseeing spot cur = Math.max(cur, a) - 1

There is a feeling that,
"A near neighbor is better than a distant cousin."

*/
class Solution
{
public:
    int maxScoreSightseeingPair(vector<int> &values)
    {
        int ans = 0;
        int prevmax = values[0] + 0;

        for (int i = 1; i < values.size(); i++)
        {
            ans = max(ans, values[i] - i + prevmax);
            prevmax = max(prevmax, values[i] + i);
        }

        return ans;
    }
};