// DP
//  class Solution {
//  public:
//      int trap(vector<int>& height) {
//          int n = height.size();
//          vector<int> leftMax(n, 0);
//          vector<int> rightMax(n, 0);

//         int maxi = height[0];
//         leftMax[0] = height[0];
//         for(int i = 1; i < n; i++) {
//             maxi = max(height[i], maxi);
//             leftMax[i] = maxi;
//         }

//         maxi = height[n-1];
//         rightMax[n-1] = height[n-1];
//         for(int i = n-2; i >= 0; i--) {
//             maxi = max(height[i], maxi);
//             rightMax[i] = maxi;
//         }

//         int count = 0;
//         for(int i = 0; i < n; i++) {
//             count += min(leftMax[i], rightMax[i]) - height[i];
//         }

//         return count;
//     }
// };

// two pointer
//  class Solution {
//  public:
//      int trap(vector<int>& height) {
//          int n=height.size();
//          int ans=0;
//          int l=0, r=n-1;
//          int lmax=0, rmax=0;
//          while(l<r){
//              lmax=max(lmax,height[l]);
//              rmax=max(rmax,height[r]);
//              if(lmax<rmax){
//                  ans+=lmax-height[l];
//                  l++;
//              }
//              else{
//                  ans+=rmax-height[r];
//                  r--;
//              }
//          }
//          return ans;
//      }
//  };

// stack
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> st;
        int trap = 0;
        for (int i = 0; i < height.size(); i++) {
            while (!st.empty() && height[st.top()] < height[i]) {
                int top = height[st.top()];
                st.pop();
                if (st.empty())
                    break;
                int width = i - st.top() - 1;
                int wallHeight = min(height[i], height[st.top()]) - top;
                trap += wallHeight * width;
            }
            st.push(i);
        }
        return trap;
    }
};
