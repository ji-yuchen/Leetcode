/*
https://leetcode.com/problems/my-calendar-ii/description/
Implement a MyCalendarTwo class to store your events. A new event can be added if adding the event will not cause a triple booking.

Your class will have one method, book(int start, int end). Formally, this represents a booking on the half open interval [start, end), the range of real numbers x such that start <= x < end.

A triple booking happens when three events have some non-empty intersection (ie., there is some time that is common to all 3 events.)

For each call to the method MyCalendar.book, return true if the event can be added to the calendar successfully without causing a triple booking. Otherwise, return false and do not add the event to the calendar.

Your class will be called like this: MyCalendar cal = new MyCalendar(); MyCalendar.book(start, end)

*/

include <vector>
include <map>
using std::vector;
using std::map;

//Time complexity: O(N^2); Space complexity: O(N)
class MyCalendarTwo {
    map<int, int> books;
public:
    MyCalendarTwo() {
        
    }
    bool book(int start, int end) {
        books[start]++;
        books[end]--;
        int booked = 0;
        for (auto &d : books) {
            booked += d.second;
            if (booked == 3) {
                //accumulate 3 books while not enough ends eliminating the books. treat this as triple overlaps.
                books[start]--;
                books[end]++;
                return false;
            }
        }
        return true;        
    }
};

/**
 * Your MyCalendarTwo object will be instantiated and called as such:
 * MyCalendarTwo obj = new MyCalendarTwo();
 * bool param_1 = obj.book(start,end);
 */








//FALSE!!!
//This is my failing try based on my solve for "MyCalendar"..... 
//I trid to write down all conditions for "triple overlaps" but missed the overlap caused by prev-prev books... 
class MyCalendarTwo {
    multimap<int, int> books;
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int s, int e) {
        auto next = books.lower_bound(s); // first element with key not go before k (i.e., either it is equivalent or goes after).
        
        cout<<"start: "<<s<<" end: "<<e<<endl;
        cout<<"next.first: "<<next->first;
        cout<<" next.second: "<<next->second<<endl;
        
        auto tmp = next;
        if (next != books.end() && (++next)!=books.end() && next->first < min(e, (--next)->second) && (next)->first < e) return false; // a existing book started within the new book (next)

        next = tmp;
        if (next != books.begin() && (--next)!=books.begin() && s < next->second && s < (--next)->second) return false; // new book started within a existing book (prev)
        next = tmp;
        if(next != books.end() && next != books.begin() && next->first < e && ((next)->first < (--next)->second)) return false;
        next = tmp;
        if(next != books.end() && next != books.begin() && next->first < e && ((next)->first < (--(--next))->second)) return false;
        books.insert({s,e});
        if( s == 60){
            cout<<"caution!"<<endl;
            for(auto i : books)
                cout<< i.first << " "<<i.second<<endl;
        }
            
        return true;
        
    }
};
