class MyCalendarTwo {
public:
    set<pair<int, int>> bookings, overlaps;

    MyCalendarTwo() {}

    bool book(int start, int end) {
        for (auto& [s, e] : overlaps) {
            if (max(s, start) < min(e, end)) {
                return false;
            }
        }

        for (auto& [s, e] : bookings) {
            if (max(s, start) < min(e, end)) {
                overlaps.insert({max(s, start), min(e, end)});
            }
        }

        bookings.insert({start, end});
        return true;
    }
};
