#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> park, vector<string> routes) {
    int w = park[0].size();
    int h = park.size();
    int cx = -1;
    int cy = -1;
    for (int i = 0; i < h; i++) {
        for (int k = 0; k < w; k++) {
            char& c = park[i][k];
            if (c == 'S') {
                cx = k;
                cy = i;
                break;
            }
        }
        if (cx != -1) break;
    }

    for (string& s : routes) {
        char dir = s[0];
        int dist = s[2] - 48;

        switch (dir) {
        case 'E': {
            if (cx + dist >= w) {}
            else {
                int t = cx;
                while (dist--) {
                    t++;
                    if (park[cy][t] == 'X') break;
                }
                if (dist == -1) cx = t;

            }
            break;
        }
        case 'W': {
            if (cx - dist < 0) {}
            else {
                int t = cx;
                while (dist--) {
                    t--;
                    if (park[cy][t] == 'X') break;
                }
                if (dist == -1) cx = t;
            }
            break;
        }
        case 'S': {
            if (cy + dist >= h) {}
            else {
                int t = cy;
                while (dist--) {
                    t++;
                    if (park[t][cx] == 'X') break;
                }
                if (dist == -1) cy = t;
            }
            break;
        }
        case 'N': {
            if (cy - dist < 0) {}
            else {
                int t = cy;
                while (dist--) {
                    t--;
                    if (park[t][cx] == 'X') break;
                }
                if (dist == -1) cy = t;
            }
            break;
        }
        }
    }

    vector<int> ret;
    ret.push_back(cy);
    ret.push_back(cx);
    return ret;
}