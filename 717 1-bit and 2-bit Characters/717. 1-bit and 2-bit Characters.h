#include <vector>
using std::vector

class Solution {
public:
    bool isOneBitCharacter(vector<int>& bits) {
        int N = bits.size();
        int i = 0;
        while(i < N - 1)
        {
            if(bits[i]==0)
            {
                i++;
            }
            else
            {
                i+=2;
            }
        }
        return i != N;
    }
};
