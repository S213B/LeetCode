class Solution {
public:
    int strongPasswordChecker(string s) {
        const int min_len = 6, max_len = 20, max_rep = 3;
        int ans = max_len;
        int up_cnt = 0, low_cnt = 0, num_cnt = 0;
        vector<int> rep_v;

        if (s.empty()) return min_len;
        
        for (auto c : s) {
            if (c >= 'A' && c <= 'Z')
                up_cnt++;
            else if (c >= 'a' && c <= 'z')
                low_cnt++;
            else if (c >= '0' && c <= '9')
                num_cnt++;            
        }
        
        char pre_c = s[0];
        int rep_cnt = 1;
        for (int i = 1; i < s.size(); i++) {
            const char cur_c = s[i];
            if (pre_c == cur_c)
                rep_cnt++;
            else {
                if (rep_cnt >= max_rep)
                    rep_v.push_back(rep_cnt);
                rep_cnt = 1;
            }
            pre_c = cur_c;
        }
        //cout << rep_cnt << endl;
        if (rep_cnt >= max_rep)
            rep_v.push_back(rep_cnt);
        
        //cout << up_cnt << " " << low_cnt << " " << num_cnt << endl;
        int c1_add = s.size() < min_len ? min_len - s.size() : 0;
        int c1_del = s.size() > max_len ? s.size() - max_len : 0;
        int c2_rep = (up_cnt ? 0 : 1) + (low_cnt ? 0 : 1) + (num_cnt ? 0 : 1);
        c2_rep -=  c2_rep > c1_add ? c1_add : c2_rep;
        int c3_rep = 0;
        
        ans = c1_add + c1_del + c2_rep;
        
        int c1_add_need = 0, c1_delx_need[max_rep] = {0};
        for (auto rep : rep_v) {
            int r = rep % max_rep;
            c1_delx_need[r]++;
            if (r < (max_rep - 1))
                c1_add_need++;
            c3_rep += rep / max_rep;
            //cout << rep << endl;
        }
        //cout << c1_add << " " << c1_del << " " << c2_rep << " " << c3_rep << endl;
        for (int i = 0; c1_del > 0 && i < max_rep; i++) {
            //cout << i << ":" << c1_delx_need[i] << endl;
            c3_rep -= (c1_del > c1_delx_need[i]*(i+1)) ? (c1_delx_need[i]) : (c1_del/(i+1));
            c1_del -= c1_delx_need[i] * (i+1);
        }
        c3_rep -= c1_del / max_rep;
        c3_rep -= (c1_add > c1_add_need) ? (c1_add_need + (c1_add - c1_add_need)*(max_rep-1)/max_rep) : c1_add;
        c3_rep -= c2_rep;
        c3_rep = c3_rep < 0 ? 0 : c3_rep;

        return ans + c3_rep;
    }
};
