class Solution {
public:
    string create_line(vector<string>& words, int start, int end, int line_real_len, int line_width) {
        string str = words[start];
        int cnt = end - start;
        
        if (cnt == 1)
            return str.append(line_width - str.size(), ' ');
        
        int total_sp = line_width - line_real_len;
        int sp_cnt = cnt - 1;
        int l_sp = total_sp % sp_cnt;
        int r_sp = sp_cnt - l_sp;
        int r_sp_len = total_sp / sp_cnt;
        int l_sp_len = l_sp ? r_sp_len + 1 : 0;
        
        //cout << total_sp << " " << sp_cnt << endl;
        //cout << r_sp_len << " " << l_sp_len << endl;
        
        str = words[start];
        for (int i = start+1; i < end; i++) {
            str.append(l_sp > 0 ? l_sp_len : r_sp_len, ' ');
            l_sp--;
            str += words[i];
        }
        
        return str;
    }
    
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        bool flush_line = false;
        int line_len = 0, line_real_len = 0;
        int start = 0, end = 0;
        
        for (int i = 0; i < words.size(); ) {
            auto &w = words[i];
            if (line_len + w.size() <= maxWidth) {
                line_len += w.size() + 1;
                line_real_len += w.size();
                end++;
                i++;
            } else {
                flush_line = true;
            }
            if (flush_line) {
                ans.push_back(create_line(words, start, end, line_real_len, maxWidth));
                start = i;
                line_len = line_real_len = 0;
                flush_line = false;
            }
        }
        
        if (start != end) {
            string str = words[start];
            for (int i = start+1; i < words.size(); i++)
                str += ' ' + words[i];
            ans.push_back(str.append(maxWidth - str.size(), ' '));
        }
        
        return ans;
    }
};
