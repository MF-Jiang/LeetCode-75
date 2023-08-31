class Solution {
public:
    string reverseWords(string s) {
        string ans="";
        string array[800];
        int place = 0;
        string temp="";
        for(int i=0;i<=s.size()-1;i++)
        {
            if(s[i]!=' '){
                temp.push_back(s[i]);
                //cout<<temp<<endl;
            }else{
                if(temp!=""){
                    array[place] = temp;
                    temp = "";
                    place++;
                }
            }
        }
        if(temp!=""){
            array[place]=temp;
        }
        
        for(;place>=0;place--){
            if(array[place]!=""){
                ans=ans + array[place];
                if(place!=0){
                    ans=ans + " ";
                }
            }
        }

        return ans;
    }
};