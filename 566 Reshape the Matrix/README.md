compile error encounterd on Leetcode website:
reference binding to null pointer of type 'value_type'

at first, i wrote:
count_c++;
if(count_c == c_in)
{
    count_r++;
    count_c = 0;
}
nums_re[i][j]=nums[count_r][count_c];

which will result count_c becoming 1 at beginning and skipping the last one.
throw "count_c++" at the end of these codes will solve this problem.
