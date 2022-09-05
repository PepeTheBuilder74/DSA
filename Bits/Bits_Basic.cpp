#include <bits/stdc++.h>
using namespace std;

void printBinary(int num)
{
    for (int i = 6; i >= 0; i--)
    {
        int k = num >> i;
        if (k & 1)
            cout << "1";
        else
            cout << "0";
    }
    cout << endl;
}

void operations(int number, int bit)
{
    int mask = 1 << bit;
    int result = number & mask;
    if (result == 0)
        cout << "The bit is not set" << endl;
    else
        cout << "The bit is set" << endl;

    // set the bit
    number = number | mask;
    printBinary(number);

    // toggle the bit
    number = number ^ mask;
    printBinary(number);

    // unset the bit
    number = number & (~mask);
    printBinary(number);
}

int countSetBits(int number)
{
    int count = 0;
    for (int i = 0; i < 32; i++)
    {
        int mask = 1 << i;
        int result = number & mask;
        if (result != 0)
            count++;
    }
    return count;
}

void clearLSB(int number, int i)
{
    int mask = (1 << (i + 1)) - 1;
    int result = number & ~(mask);
    printBinary(result);
}

void clearMSB(int number, int i)
{
    int mask = (1 << (i + 1)) - 1;
    int result = number & mask;
    printBinary(result);
}

bool isPowerOfTwo(int number)
{
    if (number & (number - 1))
        return false;
    return true;
}
int main()
{
    system("cls");
    int n = 5;
    printBinary(n);

    /* how to check if the ith bit is set or not in a number
     1. left shift 1 by i times
     2. do & with the number
     3. if the result is 0 then the ith bit is not set
     4. if the result is not 0 then the ith bit is set
    */

    /* how to set the ith bit in a number
     1. left shift 1 by i times
     2. do | with the number
    */

    /* how to unset the ith bit in a number
     1. left shift 1 by i times
     2. do ~ with the number
     3. do & with the number
    */

    /* how to toggle the ith bit in a number
     1. left shift 1 by i times
     2. do ^ with the number
    */

    operations(n, 1);

    /* Count the number of set bits in a number
       1. left shift 1 by i times and do & with the number
       2. if the result is not 0 then increment the count

       we can also use the built in function __builtin_popcount(n)
       for ll use __builtin_popcountll(n)

    */

    cout << countSetBits(n) << endl;

    /* odd even check
       1. do & with 1
       2. if the result is 0 then the number is even
       3. if the result is not 0 then the number is odd
    */

    /* multiply divide by 2
      1. left shift by 1 to multiply by 2---> if 0 times then nmber is same if 1 times then number is doubled
      2. right shift by 1 to divide by 2
    */

    /* upper case to lower case
       1.in upper case the 5th bit is not set whereas in lower case the 5th bit is set
       2. captial to small = do A | (1<<5)
       3. small to capital = do a & ~(1<<5)
    */

    /* clear the least significant set bit till ith bit
         1. left shift 1 by i+1 times
         2. subtract 1 from it
         3. ~ it
         4. do & with the number
    */

    /* clear the most significant set bit from ith bit
        1. left shift 1 by i+1 times
        2. subtract 1 from it
        3. do & with the number
    */
    clearMSB(n, 2);
    clearLSB(n, 2);

    /*power of 2 check
     1. do & with n-1
     2. if the result is 0 then the number is power of 2
     3. if the result is not 0 then the number is not power of 2
    */

    cout << isPowerOfTwo(16) << endl;

    /* swap tow numbers using xor
     1. a=a^b
     2. b=a^b
     3. a=a^b
    */
    return 0;
}