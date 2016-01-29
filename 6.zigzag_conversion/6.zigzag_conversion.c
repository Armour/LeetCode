char *convert(char *s, int numRows) {
    char map[numRows][strlen(s)];
    int stx = 0;
    int sty = 0;
    int dir = 0;
    int i, j, k = 0;
    char *ans = malloc(sizeof(char) * (strlen(s) + 1));
    if (numRows == 1) return s;
    memset(map, ' ', sizeof(map));
    ans[0] = '\0';
    for (i = 0; i < strlen(s); i++) {
        map[stx][sty] = s[i];
        if (dir == 0) {
            stx++;
        } else {
            sty++;
            stx--;
        }
        if (stx == numRows - 1) dir = 1;
        if (stx == 0) dir = 0;
    }
    for (i = 0; i < numRows; i++) {
        for (j = 0; j < strlen(s); j++) {
            if (map[i][j] != ' ') {
                ans[k] = map[i][j];
                ans[++k] = '\0';
            }
        }
    }
    return ans;   
}
