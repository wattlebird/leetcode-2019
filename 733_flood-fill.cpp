#include "util.h"

using namespace std;

typedef struct {
    int x, y;
} point_t;

class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor) {
        if (image[sr][sc] == newColor) return image;
        int dir[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        queue<point_t> Q;
        Q.push({.x = sr, .y = sc});
        int original = image[sr][sc];
        while (!Q.empty()) {
            point_t u = Q.front();
            Q.pop();
            image[u.x][u.y] = newColor;
            for(int i = 0; i < 4; i++) {
                point_t v = {.x = u.x + dir[i][0], .y = u.y + dir[i][1]};
                if (v.x >= 0 && v.x < image.size() && v.y >= 0 && v.y < image[0].size() && image[v.x][v.y] == original) {
                    Q.push(v);
                }
            }
        }
        return image;
    }
};
