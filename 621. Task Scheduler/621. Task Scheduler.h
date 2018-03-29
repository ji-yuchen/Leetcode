/*
https://leetcode.com/problems/task-scheduler/description/
Given a char array representing tasks CPU need to do. It contains capital letters A to Z where different letters represent different tasks.Tasks could be done without original order. Each task could be done in one interval. For each interval, CPU could finish one task or just be idle.

However, there is a non-negative cooling interval n that means between two same tasks, there must be at least n intervals that CPU are doing different tasks or just be idle.

You need to return the least number of intervals the CPU will take to finish all the given tasks.


//I'm confused about the interval at first. 
//It's worth reviewing at some time.


*/

//Using Sorting
//Time complexity : O(time); Space complexity : O(1)

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> sort_map(26, 0);
        for(auto c:tasks)
            sort_map[c - 'A']++;
        sort(sort_map.begin(), sort_map.end());
        int time = 0;
        while(sort_map[25] > 0)
        {
            int i = 0;
            while(i<=n){
                if(sort_map[25]==0)
                    break;
                if(i <26 && sort_map[25 - i] > 0)
                    sort_map[25 - i]--;
                time++;
                i++;
            }
            sort(sort_map.begin(), sort_map.end());
        }
        return time;
    }
};


//Calculating Idle slots
//Time complexity : O(n) ; Space complexity : O(1)
/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> sort_map(26, 0);
        for(auto c:tasks)
            sort_map[c - 'A']++;
        sort(sort_map.begin(), sort_map.end());
        int max_val = sort_map[25] - 1;
        int idle_slots = max_val * n;
        for(int i = 24; i >= 0 && sort_map[i]>0; i--){
            idle_slots -= min(sort_map[i], max_val);
        }
        return idle_slots>0? idle_slots + tasks.size():tasks.size(); 

    }
};



*/

//priority queue
//Time complexity : O(n) ; Space complexity : O(1)
/*
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char, int> counts;
        for(char t : tasks){
            counts[t]++;
        }
        priority_queue<int> pq;
        for(auto count:counts){
            pq.push(count.second);
        }
        int total_times = 0;
        int cycle = n+1;
        while(!pq.empty()){
            int time =0;
            vector<int> tmp;
            for(int i = 0; i<cycle; i++){
                if(!pq.empty())
                {
                    tmp.push_back(pq.top());
                    pq.pop();
                    time++;
                }
            }
            for(int cnt : tmp){
                if(--cnt){
                    pq.push(cnt);
                }
            }
            total_times += !pq.empty() ? cycle : time;
        }
            return total_times;
    }
};


*/
