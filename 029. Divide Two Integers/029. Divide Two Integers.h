/*
Given two integers dividend and divisor, divide two integers without using multiplication, division, and mod operator.

The integer division should truncate toward zero, which means losing its fractional part. For example, 8.345 would be truncated to 8, and -2.7335 would be truncated to -2.

Return the quotient after dividing dividend by divisor.

Note: Assume we are dealing with an environment that could only store integers within the 32-bit signed integer range: [−231, 231 − 1]. For this problem, if the quotient is strictly greater than 231 - 1, then return 231 - 1, and if the quotient is strictly less than -231, then return -231.


Need to extend to long type to avoid the case of INT_MIN inputs.

*/


class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        if (dividend == INT_MIN && divisor == -1) {
            return INT_MAX;
        }
        bool isPositive = (dividend<0 == divisor<0);
        long a, b = 0;
        a = labs(dividend);
        b = labs(divisor);

        unsigned int ans = 0;
        while(a>=b){
            int q = 0;
            while(a > (b<<(q+1))){
                q++;
            }
            ans += (1<<q);
            a = a-(b<<q);
        }
        if(ans == (1<<31) and isPositive){
            return INT_MAX;
        }
        return isPositive?ans:-ans;

    }
};
