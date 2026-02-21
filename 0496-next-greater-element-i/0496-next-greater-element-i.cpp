class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        vector<int> result;

        for(int i = 0; i < nums1.size(); i++) {
            int ele = nums1[i];
            int found = -1;
            for(int j = 0; j < nums2.size(); j++) {
                if(ele == nums2[j]) {
                    for(int k = j+1; k < nums2.size(); k++) {
                        if(ele < nums2[k]) {
                            found = nums2[k];
                            break;
                        }
                    }
                    break;
                }
            }
            result.push_back(found);
        }

        return result;
    }
};