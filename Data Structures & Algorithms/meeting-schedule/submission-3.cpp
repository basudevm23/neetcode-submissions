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
        int n  = intervals.size();
        if(n==1) return true;
        
        sort(intervals.begin(), intervals.end(), [](const Interval A, const Interval B){
            if(A.start != B.start){
                return A.start<B.start;
            }
            return A.end< B.end;
        });
        int endd = intervals[0].end;
        for(int i=1; i<n; i++){
            if(intervals[i].start <endd){
                return false;
            }
            endd = intervals[i].end;
        }   
        return true;     
    }
};
