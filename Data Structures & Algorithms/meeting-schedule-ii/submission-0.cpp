/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        if(intervals.empty())return 0;
        sort(intervals.begin(),intervals.end(),[](const Interval &a ,const Interval &b)
        {
            return a.start<b.start;
        });
        priority_queue<int,vector<int>,greater<int>>minHeap;
         for (const Interval& meeting : intervals) {
            if (!minHeap.empty() && meeting.start >= minHeap.top()) {
                minHeap.pop();
            }
            minHeap.push(meeting.end);
        }
    return minHeap.size();
    }
};
