class Solution {
public:
    string reverseVowels(string s) {
        int len = s.size();
        int start = 0;
        int end = len-1;
        for(start=0;start!=end;start++){
            if(s[start]!='a' && s[start]!='e' && s[start]!='i' && s[start]!='o' && s[start]!='u' && s[start]!='A' && s[start]!='E' && s[start]!='I' && s[start]!='O' && s[start]!='U'){
                continue;
            }
            else
            {
                while(end!=start)
                {
                    if(s[end]!='a' && s[end]!='e' && s[end]!='i' && s[end]!='o' && s[end]!='u' && s[end]!='A' && s[end]!='E' && s[end]!='I' && s[end]!='O' && s[end]!='U'){
                        end--;
                        continue;
                    }
                    else
                    {
                        char temp = s[end];
                        s[end] = s[start];
                        s[start]=temp;
                        end--;
                        break;
                    }
                }
            }
            if(start==end)
            {
                break;
            }
        }
        return s;
    }
};