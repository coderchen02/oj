// 3.1 17点35分
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        //key 排序后的子串 用来辨别是否是异位词 
        //value 所有的可以通过重新排列而相等的子串
        unordered_map<string,vector<string>> recond;
        for(int i=0;i<strs.size();i++){
            string str=strs[i];//取出来当前子串
            sort(str.begin(),str.end());
            recond[str].push_back(strs[i]);//满足排序后相等的子串都添加进来
        }
        vector<vector<string>> result;//结果数组
        for(auto it= recond.begin();it!=recond.end();it++){
            result.push_back(it->second);
        }
        return result;
    }
};