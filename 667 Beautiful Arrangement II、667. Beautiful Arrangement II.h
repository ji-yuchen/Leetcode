#include <vector>
using std::vector;

class Solution {
public:
    vector<int> constructArray(int n, int k) {
        vector<int> ret;
        for(int i =1; i <= n - k; i++)
        {
            ret.push_back(i);
        }
        for(int i = n - k + 1; i <= n;)
        {
            ret.push_back(n--);
            
            if(i < n)
            {
                ret.push_back(i++);
            }
        }
        return ret;
        
    }
