class Solution {
public:
    string minWindow(string s, string t) {
        unordered_map<char , int>mp;
        int low = 0;
        int start = 0;
        int count = t.size();
        int n = s.size();
        int minLen = INT_MAX;

        for(char c : t){
            mp[c]++;
        }

        for(int high = 0; high < n; high++){
            if(mp[s[high]] > 0)
            count--;

            mp[s[high]]--;

            while(count == 0){
                int res = high-low+1;
                if(res < minLen){
                    minLen = res;
                    start = low;
                }

                mp[s[low]]++;

                if(mp[s[low]] > 0)
                count++;

                low++;

            }
        }
        if(minLen == INT_MAX)
        return "";
        return s.substr(start , minLen);
    }
};