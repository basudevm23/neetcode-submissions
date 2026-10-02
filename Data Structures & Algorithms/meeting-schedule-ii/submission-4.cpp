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
        // lets say construct two separate arrays
        vector<int> startArray;
        vector<int> endArray;

        int s = 0;
        int e = 0;

        for(int i = 0; i < intervals.size(); i++){
            int x = intervals[i].start;
            int y = intervals[i].end;

            startArray.push_back(x);
            endArray.push_back(y);
        }
        sort(startArray.begin(), startArray.end());
        sort(endArray.begin(), endArray.end());

        int n = intervals.size();
        int res = 0;
        int count = 0;

        while(s < n){
            if(startArray[s] < endArray[e]){
                s++;
                count++;
            }
            else {
                e++;
                count--;
            }
            res = max(count, res);
        }
        return res;
    }
};
