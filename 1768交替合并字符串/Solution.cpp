class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int len=0;
        string ans;
        if(word1.size()>word2.size()){
            len = word1.size();
        }else{
            len = word2.size();
        }
        ans.reserve(len);
        int index=0;
        for(int i=0;i<len;i++){
            if(index<word1.size()){
                ans.push_back(word1[index]);
                //cout<<word1[index];
            }
            if(index<word2.size()){
                ans.push_back(word2[index]);
                //cout<<word2[index];
            }
            index++;
        }
        return ans;
    }
};