class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size()!=t.size())
            return false;

        unordered_map<char,int> s1;
        unordered_map<char,int> t1;

        for(auto i: s)
            s1[i]++;
            
        for(auto i: t)
            t1[i]++;

        return s1==t1;

    }
};
