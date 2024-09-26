    //  Link: https://leetcode.com/problems/my-calendar-i/
class MyCalendar {

private:
set<pair<int,int>> events; // Member where we will save the events

public:
    MyCalendar() {}
    
    bool book(int start, int end) {

        pair<int,int> new_event{start, end};

        //  Find the first event that starts after the new one
        auto prev_event = events.lower_bound(new_event);

        //  If that event starts before the new one ends, we end here
        if( ( prev_event != events.end() ) && ( prev_event->first < end ) )
        {
            return false;
        }

        //  Get the previous event
        if( prev_event != events.begin() )
        {
            prev_event--;
            
            //  If that event ends after the new one starts, we end here
            if( prev_event->second > start ) return false;
        }

        //  Intert the new event
        events.insert(new_event);
        return true;
    }
};

/**
 * Your MyCalendar object will be instantiated and called as such:
 * MyCalendar* obj = new MyCalendar();
 * bool param_1 = obj->book(start,end);
 */