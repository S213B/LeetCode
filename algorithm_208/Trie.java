package algorithm_208;

class TrieNode {
    // Initialize your data structure here.
    private TrieNode[] next;
    private boolean end;
    public TrieNode() {
        end = false;
        next = new TrieNode[26];
    }
    
    public void setEnd(boolean end) {
        this.end = end;
    }
    
    public boolean isEnd() {
        return this.end;
    }
    
    public void setNext(int n) {
        next[n] = new TrieNode();
    }
    
    public TrieNode getNext(int n) {
        return next[n];
    }
}

public class Trie {
    private TrieNode root;

    public Trie() {
        root = new TrieNode();
    }

    // Inserts a word into the trie.
    public void insert(String word) {
        TrieNode t = root;
        for(int i = 0; i < word.length(); i++) {
            int next = (int) (word.charAt(i)-'a');
            if(t.getNext(next) == null) {
                t.setNext(next);
            }
            t = t.getNext(next);
        }
        t.setEnd(true);
    }

    // Returns if the word is in the trie.
    public boolean search(String word) {
        TrieNode t = root;
        for(int i = 0; i < word.length(); i++) {
            int next = (int) (word.charAt(i)-'a');
            if(t.getNext(next) == null) {
                return false;
            }
            t = t.getNext(next);
        }
        return t.isEnd();
    }

    // Returns if there is any word in the trie
    // that starts with the given prefix.
    public boolean startsWith(String prefix) {
        TrieNode t = root;
        for(int i = 0; i < prefix.length(); i++) {
            int next = (int) (prefix.charAt(i)-'a');
            if(t.getNext(next) == null) {
                return false;
            }
            t = t.getNext(next);
        }
        return true;
    }
}

// Your Trie object will be instantiated and called as such:
// Trie trie = new Trie();
// trie.insert("somestring");
// trie.search("key");
