#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<vector<string>> places) {
    vector<int> ret;
    int sz1 = places.size();
    int sz2 = places[0].size();
    int sz3 = places[0][0].size();

    for (auto& vec : places) {

        vector<pair<int, int>> pos;
        for (int k = 0; k < sz2; k++) {
            for (int j = 0; j < sz3; j++) {
                char& c = vec[k][j];
                if (c == 'P') pos.push_back({ j, k });
            }
        }

        int sz4 = pos.size();
        bool check = true;
        for (int i = 0; i < sz4 - 1; i++) {
            for (int k = i + 1; k < sz4; k++) {
                int ix = pos[i].first;
                int iy = pos[i].second;
                int kx = pos[k].first;
                int ky = pos[k].second;
                int gapX = abs(ix - kx);
                int gapY = abs(iy - ky);
                if (gapX + gapY <= 2) {
                    if (ix == kx) {
                        if (vec[iy + 1][ix] != 'X') {
                            check = false;
                            break;
                        }
                    }
                    else if (iy == ky) {
                        if (vec[iy][ix + 1] != 'X') {
                            check = false;
                            break;
                        }
                    }
                    else {
                        if (ix < kx) {
                            if (vec[iy][ix + 1] != 'X' || vec[iy + 1][ix] != 'X') {
                                check = false;
                                break;
                            }
                        }
                        else {
                            if (vec[iy][ix - 1] != 'X' || vec[iy + 1][ix] != 'X') {
                                check = false;
                                break;
                            }
                        }
                    }
                }
            }
            if (check == false) break;
        }

        if (check == true) ret.push_back(1);
        else ret.push_back(0);
    }
    return ret;
}