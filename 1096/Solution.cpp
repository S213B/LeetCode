#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    class node {
    private:
        vector<string> data;
        unordered_set<string> exist;
        bool is_comma;

        void add_by_comma(node *n) {
            for (auto &d : n->data) {
                if (exist.count(d))
                    continue;
                data.push_back(d);
                exist.insert(d);
            }
        }

        void add_by_concatenate(node *n) {
            exist.clear();
            for (auto &d : data) {
                for (auto &dd : n->data) {
                    string ddd = d + dd;
                    exist.insert(ddd);
                }
            }
            data.assign(exist.begin(), exist.end());
        }

    public:
        node(char c) : is_comma(false) {
            string s(1, c);
            data.push_back(s);
            exist.insert(s);
        }

        void set_comma(void) {
            is_comma = true;
        }

        bool get_comma(void) {
            return is_comma;
        }

        void add(node *n) {
            if (is_comma)
                add_by_comma(n);
            else
                add_by_concatenate(n);
            is_comma = n->get_comma();
        }

        vector<string>& get_data(void) {
            sort(data.begin(), data.end());
            return data;
        }

        void debug(void) {
            for (auto &d : data)
                cout << d << " ";
            cout << endl;
        }
    };

public:
    vector<string> braceExpansionII(string expression) {
        vector<node *> vec;
        vector<int> open_brace_idx;

        for (int i = 0; i < expression.size(); i ++) {
            char c = expression[i];
            if (c == '{') {
                open_brace_idx.push_back(vec.size());
                continue;
            } else if (c == ',') {
                vec.back()->set_comma();
                continue;
            } else if (c == '}') {
                int idx = open_brace_idx.back();
                for (int j = idx+1; j < vec.size(); j ++)
                    vec[idx]->add(vec[j]);
                vec.resize(idx+ 1);
                open_brace_idx.pop_back();
            } else {
                node *n = new node(c);
                vec.push_back(n);
            }

            int last_open_brace_idx = open_brace_idx.size() ? open_brace_idx.back() : -1;
            if (last_open_brace_idx != vec.size()-1 && vec.size() > 1 && !vec[vec.size()-2]->get_comma()) {
                vec[vec.size()-2]->add(vec.back());
                vec.pop_back();
            }
        }

        for (int i = 1; i < vec.size(); i ++)
            vec[0]->add(vec[i]);

        return vec[0]->get_data();
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    string expression(argv[1]);
    vector<string> ans;

    ans = solution.braceExpansionII(expression);

    for (auto &an : ans)
        cout << an << " ";
    cout << endl;

    return 0;
}
