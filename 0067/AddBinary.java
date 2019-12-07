package algorithm_067;

public class AddBinary {
    public String addBinary(String a, String b) {
        String l, s;
        Boolean c = false;
        StringBuilder r = new StringBuilder();
        l = a.length() > b.length() ? a : b;
        s = a.length() > b.length() ? b : a;
        
        for(int i = s.length()-1, j = l.length()-1; i >= 0; i--, j--) {
            if(l.charAt(j) != s.charAt(i)) {
                if(c) {
                    r.append('0');
                } else {
                    r.append('1');
                }
            } else {
                if(c) {
                    r.append('1');
                } else {
                    r.append('0');
                }
                c = l.charAt(j) == '1' ? true : false;
            }
        }
        for(int i = l.length()-s.length()-1; i >= 0; i--) {
            if(c) {
                if(l.charAt(i) == '0') {
                    r.append('1');
                    c = false;
                } else {
                    r.append('0');
                }
            } else {
                r.append(l.charAt(i));
            }
        }
        if(c) {
            r.append('1');
        }
        return r.reverse().toString();
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
