class Solution {
public:
    void solve(string curr, vector<string>& result, int n) {
        if(curr.length() == n) {
            result.push_back(curr);
            return;
        }

        for(char ch='a'; ch <= 'c'; ch++) {
            if(!curr.empty() && curr.back() == ch) 
                continue;
            curr.push_back(ch); //do

            solve(curr, result, n); //explore

            curr.pop_back(); //undo
        }
    }

    string getHappyString(int n, int k) {
        string curr = "";
        vector<string> result;
        solve(curr, result, n);
        if(k > result.size()) return "";
        return result[k-1];
    }
};