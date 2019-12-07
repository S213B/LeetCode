package algorithm_179;

public class LargestNum {
    public String largestNumber(int[] num) {
        StringBuilder sb = new StringBuilder();
        String[] str = new String[num.length];
        
        for(int i = 0; i < num.length; i++) {
        	str[i] = "" + num[i];
        }
        
        qsort(str, 0, str.length);
        
        for(int i = num.length-1; i > -1; i--) {
        	sb.append(str[i]);
        }
        
        for(int i = 0; i < sb.length(); i++) {
        	if(sb.charAt(i) != '0') {
        		return sb.toString();
        	}
        }
        return "0";
    }

	private void qsort(String[] str, int start, int end) {
		if(end <= start+1) {
			return;
		}
		
		String t;
		int low = start, high = end, sentry = start;
		
		while(true) {
			while((str[sentry]+str[--high]).compareTo(str[high]+str[sentry]) <= 0 && high > low);
			if(high <= low) {
				break;
			}
			t = str[sentry];
			str[sentry] = str[high];
			str[high] = t;
			sentry = high;
			while((str[sentry]+str[++low]).compareTo(str[low]+str[sentry]) >= 0 && high > low);
			if(high <= low) {
				break;
			}
			t = str[sentry];
			str[sentry] = str[low];
			str[low] = t;
			sentry = low;
		}
		qsort(str, start, low);
		qsort(str, high+1, end);
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		LargestNum s = new LargestNum();
		int[] a = {999999998,999999997,999999999};
		System.out.println(s.largestNumber(a));
	}

}
