/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    
    Node* helper(vector<vector<int>>& grid,int up,int down,int left,int right){
        bool allSame=true;
        for(int i=up;i<down;i++){
            for(int j=left;j<right;j++){
                if(grid[i][j]!=grid[up][left]){
                    allSame=false;break;
                }
            }
        }
        Node* result;
        if(allSame){
            result=new Node(grid[up][left],1);
        }else{
            int midupdown=(up+down)/2;
            int midleftright=(left+right)/2;
            result=new Node();
            result->topLeft=helper(grid,up,midupdown,left,midleftright);
            
            result->topRight=helper(grid,up,midupdown,midleftright,right);
            
            result->bottomLeft=helper(grid,midupdown,down,left,midleftright);
            
            result->bottomRight=helper(grid,midupdown,down,midleftright,right);
        }
        return result;
    }
    Node* construct(vector<vector<int>>& grid) {
        return helper(grid,0,grid.size(),0,grid.size());
    }
};