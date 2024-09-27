class MyCalendarTwo {
private:
    vector<pair<int, int>> booked;
    vector<pair<int, int>> overlaps;
    
public:
    MyCalendarTwo() {
        
    }
    
    bool book(int start, int end) {
        // Check for any overlap with the double booked intervals.
        for (auto& [s, e] : overlaps) {
            if (max(s, start) < min(e, end)) {
                return false; // Triple booking would occur.
            }
        }
        
        // Check for new overlaps with already booked intervals.
        for (auto& [s, e] : booked) {
            if (max(s, start) < min(e, end)) {
                // Add the overlapping interval to overlaps.
                overlaps.push_back({max(s, start), min(e, end)});
            }
        }
        
        // Add the current interval to booked.
        booked.push_back({start, end});
        return true;
    }
};