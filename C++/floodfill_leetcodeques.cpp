#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>& image, int color,int intialColor){
       int m = image.size();
        int n= image[0].size();
        if(i<0 || j<0) return;
        if(i>=m || j>=n) return;
        if(image[i][j]!=intialColor) return;
        
        image[i][j]= color;
        
        dfs(i+1,j,image,color,intialColor);
        dfs(i-1,j,image,color,intialColor);
        dfs(i,j-1,image,color,intialColor);
        dfs(i,j+1,image,color,intialColor);
        
        
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int intialColor = image[sr][sc];
        if(intialColor!=color){
            dfs(sr,sc,image,color,intialColor);
        }
        return image;
        
    }
};

