// Last updated: 2/9/2026, 1:27:45 PM
class Solution {
public:
    vector<vector<int>> ans;
    void fill(vector<vector<int>> &img, int i, int j, int dup, int org)
    {
        if(i<0 || j<0 || i>=img.size() || j>=img[0].size() || img[i][j] != org)
            return;
        img[i][j] = dup;
        fill(img, i+1,j,dup,org);
        fill(img, i-1,j,dup,org);
        fill(img, i,j+1,dup,org);
        fill(img, i,j-1,dup,org);
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) 
    {
        int org = image[sr][sc];
        if(org == color)    return image;
        fill(image, sr,sc,color,org);
        return image;
    }
};