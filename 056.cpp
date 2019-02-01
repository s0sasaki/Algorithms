/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        if(intervals.size()==0) return intervals;
        vector<int> nodes;
        for(int i=0;i<intervals.size();i++){
            nodes.push_back(intervals[i].start);
            nodes.push_back(intervals[i].end);
        }
        sort(nodes.begin(), nodes.end());
        vector<bool> included(nodes.size()-1, false);
        for(int i=0;i<included.size();i++){
            double mid = ((double)nodes[i]+nodes[i+1])/2.0;
            for(int j=0;j<intervals.size();j++){
                if(intervals[j].start<=mid&&mid<=intervals[j].end){
                    included[i] = true;
                    break;
                }
            }
        }
        vector<Interval> r;
        int s=0;
        int i=0;
        while(1){
            while(included[i]&&i<nodes.size()-1) i++;
            r.push_back(Interval(nodes[s], nodes[i]));
            if(i>=nodes.size()-1) break;
            while(!included[i]) i++;
            s = i;
        }
        return r;
    }
};