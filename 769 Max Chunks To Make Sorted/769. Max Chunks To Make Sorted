#include <vector>
using std::vector

class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        
        int index = 0;
        int max = 0;
        for(int i = 0; i < arr.size(); i++)
        {
            if(arr[i]>max)
                max = arr[i];
            if(max == i)
                index += 1;
        }
        return index;        
    }
};
