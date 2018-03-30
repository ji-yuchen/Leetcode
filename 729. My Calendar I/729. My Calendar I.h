/*
https://leetcode.com/problems/my-calendar-i/description/

Implement a MyCalendar class to store your events. A new event can be added if adding the event will not cause a double booking.

Your class will have the method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A double booking happens when two events have some non-empty intersection (ie., there is some time that is common to both events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a double booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)


*/
//Brute Force
//Time complexity : O(N^2)

class MyCalendar {
public:
    MyCalendar() {
        
    }
    vector<pair<int, int>> books;
    
    bool book(int start, int end) {
        for(pair<int, int> p : books){
            if (max(p.first, start) < min(end, p.second)) 
                return false;
        }
        books.push_back({start, end});
        return true;        
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar obj = new MyCalendar();
 * bool param_1 = obj.book(start,end);
 */
 
 
 
//ordered map
 
 /*
class MyCalendar {
    map<int, int> books;
public:
    bool book(int s, int e) {
        auto next = books.lower_bound(s); // first element with key not go before k (i.e., either it is equivalent or goes after).
        if (next != books.end() && next->first < e) return false; // a existing book started within the new book (next)
        if (next != books.begin() && s < (--next)->second) return false; // new book started within a existing book (prev)
        books[s] = e;
        return true;
    }
};
 
 */
