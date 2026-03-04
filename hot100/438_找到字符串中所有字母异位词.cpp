// 3.4 21点22分
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> result;
        if (s.size() < p.size()) return result;

        unordered_map<char, int> need_match, window;
        for (char c : p) need_match[c]++;

        int left = 0, right = 0;
        int match = 0; 

        while (right < s.size()) {
            char c = s[right];
            right++; // 扩大窗口
            
            // 1. 进行窗口内数据的更新
            if (need_match.count(c)) {
                window[c]++;
                if (window[c] == need_match[c])
                    match++;
            }

            // 2. 判断左侧窗口是否需要收缩
            // 当窗口大小达到 p 的长度时，就需要判断并移动 left
            if (right - left == p.size()) {
                // 判断是否找到了合法异位词
                if (match == need_match.size()) {
                    result.push_back(left);
                }

                char l = s[left];
                left++; // 缩小窗口
                
                // 3. 移出字符时的窗口数据更新
                if (need_match.count(l)) {
                    if (window[l] == need_match[l])
                        match--;
                    window[l]--;
                }
            }
        }
        return result;
    }
};