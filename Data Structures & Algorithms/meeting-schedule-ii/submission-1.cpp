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
        int n = intervals.size();
        vector<int> starter;
        vector<int> ender;
        for(int i=0; i<intervals.size(); i++){
            starter.push_back(intervals[i].start);
            ender.push_back(intervals[i].end);
        }
        sort(starter.begin(), starter.end());
        sort(ender.begin(), ender.end());
        int temps=0;
        int tempe=0;
        int count =0 ;
        int maxcount=0;
        while(temps<n && tempe<n){
            if(starter[temps]<ender[tempe]){
                temps++;
                count++;
                maxcount = max(maxcount, count);
            }
            else if(starter[temps]>=ender[tempe]){
                tempe++;
                count--;
            }
        }
        return maxcount;
    }
};
