#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

#if 0
class StockSpanner {
private:
    vector<int> prices;
    vector<int> spans;

public:
    StockSpanner() {
        prices.push_back(INT_MAX);
        spans.push_back(1);
    }

    int next(int price) {
        int span = 1;
        int i = prices.size() - span;
        while (i >= 0 && prices[i] <= price) {
            span += spans[i];
            i -= spans[i];
        }
        prices.push_back(price);
        spans.push_back(span);
        return span;
    }
};
#else
class StockSpanner {
private:
    stack<pair<int, int>> stk;

public:
    StockSpanner() {

    }

    int next(int price) {
        int span = 1;
        while (stk.size() && stk.top().first <= price) {
            span += stk.top().second;
            stk.pop();
        }
        stk.push(make_pair(price, span));
        return span;
    }
};
#endif

/**
 * Your StockSpanner object will be instantiated and called as such:
 * StockSpanner* obj = new StockSpanner();
 * int param_1 = obj->next(price);
 */

int main(int argc, char *argv[]) {
    StockSpanner* obj = new StockSpanner();
    int n;

    while (cin >> n)
        cout << obj->next(n) << endl;

    return 0;
}
