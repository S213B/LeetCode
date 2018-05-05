class Solution {
public:
    bool is_pal(const string &str) {
        int s = 0, e = str.size() - 1;
        while (s < e) {
            if (str[s] != str[e])
                return false;
            s++;
            e--;
        }
        return true;
    }

    void mk_pal(string &s) {
        for (int i = 0; i < s.size()/2; i++) {
            s[s.size() - 1 - i] = s[i];
        }
    }

    string nearestPalindromic(string n) {
        int sz = n.size();
        if (sz <= 1) return to_string(stoi(n)-1);
        long long base = stoll(n);
        long long l_v, m_u, cand1, cand2, ans;
        int l_sz, r_sz, m_sz;
        string left, right, middle, temp;
        bool add_m = sz % 2;

        l_sz = r_sz = (sz)/2;
        m_sz = sz/2 + 1;
        left = n.substr(0, l_sz);
        right = n.substr(sz-r_sz, r_sz);
        middle = n.substr(sz-m_sz, m_sz);

        temp.assign(m_sz-1, '0');
        m_u = stoll('1' + temp);

        if (!is_pal(n)) {
            temp = n;
            mk_pal(temp);
            cand1 = stoll(temp);
        } else {
            temp = to_string(base + m_u);
            mk_pal(temp);
            cand1 = stoll(temp);
        }

        l_v = m_u;
        if (cand1 > base)
            l_v = -(stoll(right)+1);
        l_v += base;
        temp = to_string(l_v);
        mk_pal(temp);

        cand2 = stoll(temp);
        if (abs(base - cand1) == abs(base - cand2))
            ans = cand1 < cand2 ? cand1 : cand2;
        else
            ans = abs(base - cand1) < abs(base - cand2) ? cand1 : cand2;

        return to_string(ans);
    }
};
