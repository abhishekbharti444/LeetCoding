class Solution {
public:
    int minMoves(int sx, int sy, int tx, int ty) {
        if (sx == 0 && sy == 0) {
            if (tx == 0 && ty == 0) {
                return 0;
            }
            return -1;
        }


        int res = 0;
        while (tx != sx || ty != sy) {
            if (tx < sx || ty < sy) return -1;
            if (tx > ty) {
                if (tx > 2 * ty) {
                    if (tx % 2 == 0) tx /= 2;
                    else return -1;
                }
                else {
                    tx -= ty;
                }
            }
            else if (ty > tx) {
                if (ty > 2 * tx) {
                    if (ty % 2 == 0) ty /= 2;
                    else return -1;
                }
                else ty -= tx;
            }
            else {
                if (sx == 0) tx = 0;
                else if (sy == 0) ty = 0;
                else return -1;
            }

            res++;
        }
        return res;

    }
};