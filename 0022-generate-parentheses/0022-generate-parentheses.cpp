class Solution {
public:

    bool isValid(string s) {
        vector<int> arr;
        for(int i=0; i< s.size(); i++){
            if(s[i] == '('){
                arr.push_back(s[i]);
            } else {
                if (arr.empty() || 
                    (s[i] == ')' && arr.back() != '(')) {
                    return false;
                }
                arr.pop_back();
            }
        }
        int result = arr.empty();
        return result;
    }

    void generate(vector<string>& result, string s, int n) {

        if(s.length() == 2*n) {
            if (isValid(s)) {  
                result.push_back(s);
            }
            return; 
        }

        generate(result, s + "(", n);
        
        generate(result, s + ")", n);
        

    }

    vector<string> generateParenthesis(int n) {
        vector<string> result;

        generate(result, "", n);

        return result;
    }
};