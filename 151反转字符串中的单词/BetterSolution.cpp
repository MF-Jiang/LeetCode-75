class Solution {
public:
    string reverseWords(string s) {
        // 移除头尾多余的空格
        int headspace = 0;
        for(int i = 0; i < s.size(); i++)
        {
            if(s[i] == ' ') 
            {
                headspace++;
            }else{
                break;
            }
        }
        int tailspace = 0;
        for(int i = s.size() -1; i >=0; i--)
        {
            if(s[i] == ' ')
            {
                tailspace++;
            }else{
                break;
            }
        }
        s = s.substr(headspace, s.size() - headspace - tailspace);
        
        int i = s.size()-1;
        int j = s.size() - 1;
        string res = "";
        // 使用双指针把单词拆分出来，并填充到res中

        while(i >= 0)
        {
            while(i >= 0 && s[i] != ' ') i--;
            res.append(s.substr(i+1, j-i));
            res += " ";
            while(i >=0 && s[i] == ' ') i--;
            j = i;
        }
        // 去掉尾部的一个多余空格
        res = res.substr(0, res.size() - 1);
        
        return res;
    }

};