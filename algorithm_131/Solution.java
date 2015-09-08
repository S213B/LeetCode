public class Solution {
    
    List<Integer>[] pal;
    List<List<String>> r;
    
    public List<List<String>> partition(String s) {
        pal = new ArrayList[s.length()];
        r = new ArrayList<List<String>>();
        for(int i = 0; i < pal.length; i++) {
            pal[i] = new ArrayList<Integer>();
            pal[i].add(i);
            if(i != 0 && s.charAt(i-1) == s.charAt(i)) {
                pal[i].add(i-1);
            }
        }
        
        for(int i = 2; i < s.length(); i++) {
            for(int j = 0; j < pal[i-1].size(); j++) {
                if(pal[i-1].get(j) != 0) {
                    if(s.charAt(pal[i-1].get(j)-1) == s.charAt(i)) {
                        pal[i].add(pal[i-1].get(j)-1);
                    }
                }
            }
        }
        
        for(int i = 0; i < pal[s.length()-1].size(); i++) {
            LinkedList<String> t = new LinkedList<String>();
            int start = pal[s.length()-1].get(i);
            t.add(s.substring(start));
            foo(start, s, t);
        }
        
        return r;
    }
    
    private void foo(int end, String s, LinkedList<String> t) {
        
        if(end == 0) {
            r.add(t);
        } else {
            for(int i = 0; i < pal[end-1].size(); i++) {
                int start = pal[end-1].get(i);
                LinkedList<String> _t = (LinkedList<String>) t.clone();
                _t.addFirst(s.substring(start, end));
                foo(start, s, _t);
            }
            // int start = pal[end-1].get(pal[end-1].size()-1);
            // t.add(s.substring(start, end));
            // foo(start, s, t);
        }
        
        return;
    }
    
}
