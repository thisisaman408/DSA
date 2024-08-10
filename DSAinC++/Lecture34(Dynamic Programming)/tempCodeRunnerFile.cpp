double f3(int r, int s, int p)
{
    if (r == 0)
        return 1;
    if (p == 0)
        return 0;
    if (s == 0)
        return 0;
    if (dp[r][s][p] > -0.9)
        return dp[r][s][p];
    return dp[r][s][p]  = f3(r, s - 1, p) * (r * s) / (r * s + s * p + r * p) + f3(r - 1, s, p) * (r * p) / (r * s + s * p + r * p) + f3(r, s, p - 1) * (s * p) / (r * s + s * p + r * p);
}