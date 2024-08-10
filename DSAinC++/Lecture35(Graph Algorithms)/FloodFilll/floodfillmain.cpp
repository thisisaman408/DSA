#include<iostream>
#include<vector>

using namespace std;

void dfs(vector<vector<int>>& image, int i, int j, int originalColor, int newColor){
    if(i < 0 or j < 0 or i>= image.size() or j >= image[0].size() or image[i][j] != originalColor or image[i][j] == newColor) return;
    image[i][j] = newColor;
    dfs(image, i-1, j,originalColor, newColor);
    dfs(image, i+1, j,originalColor, newColor);
    dfs(image, i, j-1,originalColor, newColor);
    dfs(image, i, j+1,originalColor, newColor);
}



int main(){

}