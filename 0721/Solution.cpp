#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>

using namespace std;

class Solution {
private:
    class my_account {
    private:
        my_account *father;
        string name;
        vector<string> emails;

    public:
        my_account(string &_name) : name(_name), father(nullptr) { }

        void add_email(const string &email) {
            emails.push_back(email);
        }

        vector<string> &get_emails(void) {
            sort(emails.begin(), emails.end());
            return emails;
        }

        string get_name(void) {
            return name;
        }

        my_account *get_ancestor(void) {
            my_account *ancestor = this;
            while (ancestor->father)
                ancestor = ancestor->father;
            return ancestor;
        }

        void set_ancestor(my_account *ancestor) {
            father = ancestor;
        }

        bool is_ancestor(void) {
            return father == nullptr;
        }
    };

public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, my_account *> email2account;
        vector<my_account *> people;
        vector<vector<string>> ans;

        for (auto &account : accounts) {
            my_account *person = new my_account(account[0]);
            people.push_back(person);
            for (int i = 1; i < account.size(); i ++) {
                string &email = account[i];
                if (email2account.count(email)) {
                    my_account *peer = email2account[email];
                    peer->get_ancestor()->set_ancestor(person);
                } else {
                    email2account[email] = person;
                }
            }
        }

        for (auto &e2a : email2account) {
            const string &email = e2a.first;
            my_account *account = e2a.second;
            my_account *ancestor = account->get_ancestor();
            ancestor->add_email(email);
        }

        for (auto person : people) {
            if (person->is_ancestor()) {
                vector<string> account(person->get_emails());
                account.insert(account.begin(), person->get_name());
                ans.push_back(account);
            }
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
        if (s.find("@") == s.npos && account.size()) {
            accounts.push_back(account);
            account.clear();
        }
        account.push_back(s);
    }
    if (account.size())
        accounts.push_back(account);

    ans = solution.accountsMerge(accounts);

    for (auto &ele : ans) {
        for (auto &e : ele)
            cout << e << " ";
        cout << endl;
    }

    return 0;
}
