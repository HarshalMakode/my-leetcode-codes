class Solution {
public:
    int M = 1e9+7;

    long long power(long long a, long long b) {
        if(b == 0) return 1;

        long long half = power(a, b/2);
        long long result = (half * half) % M;

        if(b % 2 == 1) {
            result = (result * a) % M;
        }

        return result;
    }

    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        int blockSize = ceil(sqrt(n));

        unordered_map<int, vector<vector<int>>> mp;

        for(int i = 0; i < queries.size(); i++) {
            int L = queries[i][0];
            int R = queries[i][1];
            int K = queries[i][2];
            int V = queries[i][3];

            if(K >= blockSize) {
                for(int j = L; j <=R; j+=K) {
                    nums[j] = (1LL * nums[j] * V) % M;
                }
            } else {
                mp[K].push_back(queries[i]);
            }
        }

        for(auto& [K, allQueries] : mp) {
            vector<long long> diff(n, 1);

            for(int j = 0; j < allQueries.size(); j++) {
                int L = allQueries[j][0];
                int R = allQueries[j][1];
                int V = allQueries[j][3];

                diff[L] = (diff[L] * V) % M;

                int steps = (R-L)/K;

                int next = L + (steps+1)*K;

                if(next < n) 
                    diff[next] = (diff[next] * power(V, M-2)) % M; //ferment little theorem
            }

            //cum product of diff
            for(int i = 0; i < n; i++) {
                if(i-K >= 0) 
                    diff[i] = (diff[i]*diff[i-K])%M;
            }

            for(int i = 0; i < n; i++) {
                nums[i] = (nums[i]*diff[i])%M;
            }
        }
        
        int XOR = nums[0];
        for(int i = 1; i < nums.size(); i++) {
            XOR ^= nums[i];
        }

        return XOR;
    }
};