#include <stdlib.h>

void dfs(int** image, int r, int c, int rows, int cols, int origColor, int newColor) {
    if (r < 0 || c < 0 || r >= rows || c >= cols || image[r][c] != origColor)
        return;

    image[r][c] = newColor;
    dfs(image, r + 1, c, rows, cols, origColor, newColor);
    dfs(image, r - 1, c, rows, cols, origColor, newColor);
    dfs(image, r, c + 1, rows, cols, origColor, newColor);
    dfs(image, r, c - 1, rows, cols, origColor, newColor);
}

int** floodFill(int** image, int imageSize, int* imageColSize, int sr, int sc, int color, int* returnSize, int** returnColumnSizes) {

    int origColor = image[sr][sc];

 
    if (origColor == color) {
        *returnSize = imageSize;
        *returnColumnSizes = imageColSize;
        return image;
    }

    int cols = imageColSize[0];

    dfs(image, sr, sc, imageSize, cols, origColor, color);

    // Return values
    *returnSize = imageSize;
    *returnColumnSizes = imageColSize;

    return image;
}