#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution {
private:
    class account {
    public:
        account *father;
        string name;
        unordered_set<string> emails;

        account(string &_name) {
            name = _name;
            father = nullptr;
        }

        account(vector<vector<string>>& info) {
            name = info[0];
            father = nullptr;
            for (int i = 1; i < info.size(); i ++)
                emails.insert(info[i]);
        }

        void add_email(string &email) {
            emails.insert(email);
        }

        void merge(account *peer) {
            if (name != peer->name)
                return;
            emails.insert(peer->emails.begin(), peer->emails.end());
        }

        vector<string> get_emails(void) {
            vector<string> ans(email.begin()s, emails.end());
            sort(emails.begin(), emails.end());
            return emails;
        }

        string get_name(void) {
            return name;
        }

        bool belong_to(string &email) {
            return !!(emails.count(email));
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        vector<vector<string>> ans;
        unordered_map<string, account *> emails;
        vector<account *> acc;

        for (auto &acc : accounts) {
        }

        return ans;
    }
};

int main(int argc, char *argv[]) {
    Solution solution;
    vector<vector<string>> accounts;
    vector<vector<string>> ans;
    vector<string> account;
    string s;

    while (cin >> s) {
        if (s.find("@") == s.end()) {
            accounts.push_back(account);
            account.clear();
        }
        account.push_back(s);
    }

    ans = solution.accountsMerge(accounts);

    for (auto &ele : ans) {
        for (auto &e : ele)
            cout << e << " ";
        cout << endl;
    }

    return 0;
}
