#!/usr/bin/env python
import sys
import os

Solution_name = "Solution.cpp"
Solution_src = """#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <deque>
#include <queue>
#include <stack>

using namespace std;

class Solution {
public:
};

int main(int argc, char *argv[]) {
    Solution solution;
    return 0;
}
"""

Makefile_name = "Makefile"
Makefile_src = """Solution: Solution.cpp
	g++ --std=c++11 Solution.cpp -o Solution
"""

folder = "%04d" % int(sys.argv[1])
if not os.path.exists(folder):
    os.mkdir(folder)

Solution_path = os.path.join(folder, Solution_name)
with open(Solution_path, "w") as f:
    f.write(Solution_src);

Makefile_path = os.path.join(folder, Makefile_name)
with open(Makefile_path, "w") as f:
    f.write(Makefile_src);

cmd = "git add %s" % folder
os.system(cmd)

print "%s done" % folder
