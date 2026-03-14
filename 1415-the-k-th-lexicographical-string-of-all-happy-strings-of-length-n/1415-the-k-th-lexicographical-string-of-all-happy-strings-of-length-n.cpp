class Solution {
public:
    void solve(string curr, string& result, int& count, int k, int n) {
        if(curr.length() == n) {
            count++;
            if(count == k) 
                result = curr;
            return;
        }

        for(char ch='a'; ch <= 'c'; ch++) {
            if(!curr.empty() && curr.back() == ch) 
                continue;

            curr.push_back(ch); //do

            solve(curr, result, count, k, n); //explore

            curr.pop_back(); //undo
        }
    }

    string getHappyString(int n, int k) {
        string result = "";
        int count = 0;
        solve("", result, count, k, n);
        return result;
    }
};