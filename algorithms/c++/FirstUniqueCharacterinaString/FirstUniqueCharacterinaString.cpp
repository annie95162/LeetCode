class Solution {
public:
    int firstUniqChar(string s) {
        int ans = -1;
        unordered_map<char,vector<int>> map;
        for(int i = 0; i < s.size(); i++){
            map[s[i]].emplace_back(i);
        }
        for(int j = 0; j < s.size(); j++){
            if(map[s[j]].size() == 1){
                ans = map[s[j]][0];
                break;
            }
        }
        return ans;
    }
};
