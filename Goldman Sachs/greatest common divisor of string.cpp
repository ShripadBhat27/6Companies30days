class Solution {
public:
    
    string gcdOfStrings(string str1, string str2) {
        if(str1.length()>str2.length())
            swap(str1,str2);
        
        
        
        for(int k=str1.length();k>=1;k--){
            if(str2.length()%k!=0) continue;
            if(str1.length()%k!=0) continue;
            
            string ans=str1.substr(0,k);
            int flg=1;
            
            for(int i=0;i<str1.length();i+=k){
                if(str1.substr(i,k)!=ans){
                    flg=0;break;
                }
            }
            
            for(int i=0;i<str2.length();i+=k){
                if(str2.substr(i,k)!=ans){
                    flg=0;break;
                }
            }
            
            if(flg) return ans;
        }
        return "";
    }
};