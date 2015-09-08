class Solution {
    char[][] map = {{' '}, {}, {'a', 'b', 'c'}, {'d', 'e', 'f'}, {'g', 'h', 'i'}, {'j', 'k', 'l'},
    {'m', 'n', 'o'}, {'p', 'q', 'r', 's'}, {'t', 'u', 'v'}, {'w', 'x', 'y', 'z'}};
    public List<String> letterCombinations(String digits) {
        LinkedList<String> r = new LinkedList<String>();
        
        if(digits.length() != 0) {
            r = foo(digits, digits.length());
        }
        
        return r;
    }
    
    private LinkedList<String> foo(String digits, int idx) {
        int dig = digits.charAt(idx-1)-'0';
        LinkedList<String> r = new LinkedList<String>(), _r = new LinkedList<String>();
        if(idx != 1) {
            _r = foo(digits, idx-1);
        }
        for(int i = 0; i < map[dig].length; i++) {
            if(idx == 1) {
                r.add("" + map[dig][i]);
            } else {
                for(int j = 0; j < _r.size(); j++) {
                    r.add((_r.get(j) + map[dig][i]));
                }
            }
        }
        
        return r;
    }
}
