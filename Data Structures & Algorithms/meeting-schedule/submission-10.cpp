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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if(n == 0) return true;
        // keeps track of the final index, which is used for comparison

        sort(intervals.begin(), intervals.end(), [](const Interval A, const Interval B){
            if(A.start != B.start){
                return A.start < B.start;
            }
            else return A.end < B.end;
        });

        int endIndex = intervals[0].end;

        for(int i = 1; i < n; i++){
            if(intervals[i].start >= endIndex){
                endIndex = intervals[i].end;
            }
            else{
                return false;
            }
        }
        return true;
    }
};
