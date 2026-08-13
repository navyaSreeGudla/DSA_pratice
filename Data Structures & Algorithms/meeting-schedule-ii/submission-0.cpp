class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if (intervals.empty()) {
            return 0;
        }

        sort(intervals.begin(), intervals.end(), [](const Interval& a, const Interval& b) {
            return a.start < b.start;
        });

        priority_queue<int, vector<int>, greater<int>> pq;

        for (auto& interval : intervals) {
            if (!pq.empty() && pq.top() <= interval.start) {
                pq.pop();
            }

            pq.push(interval.end);
        }

        return pq.size();
    }
};