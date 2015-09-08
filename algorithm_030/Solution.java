public class Solution {
    public List<Integer> findSubstring(String s, String[] words) {
        LinkedList<Integer> r = new LinkedList<Integer>();
        if(words.length == 0) {
            return r;
        }
        
        int wLen = words[0].length(), len = words.length*wLen, cnt = 0, _cnt;
        if(s.length() < len) {
            return r;
        }
        
        int[] word = new int[words.length], _word = new int[words.length];
        HashMap<String, Integer> dic = new HashMap<String, Integer>();
        LinkedList<Integer> queue = new LinkedList<Integer>();
        for(int i = 0, j = 0; i < words.length; i++) {
            if(dic.containsKey(words[i])) {
                word[dic.get(words[i])]++;
            } else {
                word[j]++;
                dic.put(words[i], j);
                j++;
                cnt++;
            }
        }
        
        for(int i = 0; i < wLen; i++) {
            for(int j = 0; j < word.length; j++) {
                _word[j] = word[j];
            }
            _cnt = cnt;
            queue.clear();
            for(int j = i; j+wLen <= s.length(); j += wLen) {
                if(queue.size() == words.length) {
                    int idx = queue.removeFirst();
                    _word[idx]++;
                    if(_word[idx] == 1) {
                        _cnt++;
                    } else if(_word[idx] == 0) {
                        _cnt--;
                    }
                }
                String t = s.substring(j, j+wLen);
                Integer idx = dic.get(t);
                if(idx == null) {
                    if(j+len+wLen > s.length()) {
                        break;
                    }
                    _cnt = cnt;
                    for(int k = 0; k < word.length; k++) {
                        _word[k] = word[k];
                    }
                    queue.clear();
                } else {
                    _word[idx]--;
                    queue.add(idx);
                    if(_word[idx] == 0) {
                        _cnt--;
                    } else if(_word[idx] == -1) {
                        _cnt++;
                    }
                    if(_cnt == 0) {
                        r.add(j+wLen-len);
                    }
                }
            }
        }
        
        return r;
    }
}
