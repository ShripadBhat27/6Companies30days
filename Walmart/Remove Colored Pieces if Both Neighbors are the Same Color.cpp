class Solution {
public:
    bool winnerOfGame(string colors) {
       
        int ansA=0,ansB=0,currA=0,currB=0;
        for(int i=0;i<colors.length();i++){
            if(colors[i]=='A'){
                if(currB>2) ansB+=(currB-2);
                currB=0;currA++;
            }else{
                if(currA>2) ansA+=(currA-2);
                currA=0;currB++;
            }
            
        }
        
        if(currA>2) ansA+=(currA-2);
        
         if(currB>2) ansB+=(currB-2);
      
        
        
        return (ansA>ansB);
    }
};