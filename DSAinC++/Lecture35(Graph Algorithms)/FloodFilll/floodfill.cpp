//leetcode 733
//https://leetcode.com/problems/flood-fill/description/


//image is a set of 3 2d vectors, of each red green and blue


#include<iostream>
#include<vector>

using namespace std;

class Solution {
public:
    void helper(vector<vector<int>>& image, int i, int j, int originalColor, int newColor) {
        if (i < 0 || i >= image.size() || j < 0 || j >= image[0].size() || image[i][j] != originalColor || image[i][j] == newColor) return;
        image[i][j] = newColor;
        helper(image, i - 1, j, originalColor, newColor);
        helper(image, i + 1, j, originalColor, newColor);
        helper(image, i, j - 1, originalColor, newColor);
        helper(image, i, j + 1, originalColor, newColor);
    }

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int originalColor = image[sr][sc];
        if (originalColor != color) {
            helper(image, sr, sc, originalColor, color);
        }
        return image;
    }
    void display(vector<vector<int>>&v){
        for(int i = 0; i<v.size(); i++){
           for(int j = 0; j < v[0].size();j++){
            cout<<v[i][j]<< " ";
           }
           cout<<endl;
        }
    }
};

int main(){

    Solution sol;
    vector<vector<int>> image = {{1,1,1},{1,1,0},{1,0,1}};
    int sr = 1;
    int sc = 1;
    int color = 2;
    sol.display(image);
    image = sol.floodFill(image,sr,sc,color);
    cout<<endl;
    sol.display(image);
}
