class Solution {
public:
    static bool cmp(vector<int>& a, vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int m = intervals.size();
        int n = intervals[0].size();
            
        sort(intervals.begin(), intervals.end(), cmp);
        int count = 1;
        int last = intervals[0][1];

        for(int i = 1; i < m; i++) {
            if(intervals[i][0] >= last) {
                count++;
                last = intervals[i][1];
            }
        }

        return m - count;
    }
};