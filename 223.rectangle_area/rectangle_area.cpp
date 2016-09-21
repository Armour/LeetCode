class Solution {
public:
    int computeArea(int A, int B, int C, int D, int E, int F, int G, int H) {
        int width = 0;
        int height = 0;
        int rect1 = (C - A) * (D - B);
        int rect2 = (G - E) * (H - F);
        if (A <= E && C >= E) width = min(C - E, G - E);
        if (A > E && G >= A) width = min(G - A, C - A);
        if (B <= F && D >= F) height = min(D - F, H - F);
        if (B > F &&  H >= B) height = min(H - B, D - B);
        return rect1 + rect2 - width * height;
    }
};
