class Solution {
public:
    
    void dfs(vector<vector<int>>& image, int row, int col, int old,int newColor)
    {
        //越界
        if(row<0||row>=image.size()||col<0||col>=image[0].size())
            return;
        
        if(image[row][col]!=old)//不是相连的颜色
            return;
        image[row][col]=newColor;
        //往四个方向搜索
        dfs(image,row+1,col,old,newColor);
        dfs(image,row,col+1,old,newColor);
        dfs(image,row-1,col,old,newColor);
        dfs(image,row,col-1,old,newColor);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        int old=image[sr][sc];//记录原来的颜色
        if(old!=newColor)
            dfs(image,sr,sc,old,newColor);
        
        return image;
    }
};