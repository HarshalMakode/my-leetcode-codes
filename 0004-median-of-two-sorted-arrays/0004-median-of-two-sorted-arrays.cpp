class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());
        for(int x : nums1) {
            cout << x << " ";
        }
        int l = 0;
        int h = nums1.size() - 1;
        double m = (l + h) / 2.0;

        if(m != floor(m)) {
            return (nums1[floor(m)] + nums1[floor(m) + 1] ) / 2.0;
        }
        
        return nums1[m];
    }
};