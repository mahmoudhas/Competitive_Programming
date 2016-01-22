vector<int> zfunction(string s)
{
    vector<int> z(s.size());
    int l = 0, r = 0;
    for (int i = 1; i < s.size(); i++)
    {
        if (i > r || z[i - l] >= r - i + 1)
        {
            l = i; r = max(r, i);
            while (r < s.size() && s[r - l] == s[r])
                r++;
            z[i] = (r--) - l;
        }
        else
            z[i] = z[i - l];
    }
    return z;
}
