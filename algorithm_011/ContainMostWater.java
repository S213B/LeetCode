package algorithm_11;

public class ContainMostWater {
	public int maxArea(int[] height) {
		int r = 0, mh = -1, idx = 0;
		int[] l = new int[height.length], h = new int[height.length+1];

		for(int i = 0; i < height.length; i++) {
			h[i] = height[i];
			if(mh < height[i]) {
				mh = height[i];
				idx = i;
			}
		}
		
		for(int i = height.length-1; i >= idx; i--) {
			if(h[i] > h[i+1]) {
				for(int j = 0; j <= idx; j++) {
					if(height[j] >= height[i]) {
						l[i-j] = l[i-j] > height[i] ? l[i-j] : height[i];
						break;
					} else {
						l[i-j] = l[i-j] > height[j] ? l[i-j] : height[j];
					}
				}
			}
		}
		
		for(int i = 0; i < l.length; i++) {
			r = r > l[i]*i ? r : l[i]*i;
		}

		return r;
	}

	public int corAns(int[] height) {
		int r = 0;

		for (int i = 1; i < height.length; i++) {
			int t_max = 0;
			for (int j = i - 1; j > -1; j--) {
				int h = height[j] > height[i] ? height[i] : height[j];
				int t = h * (i - j);
				t_max = t_max > t ? t_max : t;
			}
			r = r > t_max ? r : t_max;
		}

		return r;
	}

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		long start = System.currentTimeMillis();
		int[] a = {177,112,74,197,90,16,4,61,103,133,198,4,121,143,55,138,47,167,165,159,93,85,53,118,127,171,137,65,135,45,151,64,109,25,61,152,194,65,165,97,199,163,53,72,58,108,10,105,27,127,64,120,164,70,190,91,41,127,109,176,172,12,193,34,38,54,138,184,120,103,33,71,66,86,143,125,146,105,182,173,184,199,46,148,69,36,192,110,116,53,38,40,65,31,74,103,86,12,39,158};
//		for (int i = 0, j = 15000; i < a.length; i++) {
//			a[i] = j--;
//		}
		ContainMostWater s = new ContainMostWater();
		System.out.println(s.maxArea(a) + ":" + s.corAns(a));
		System.out.println(System.currentTimeMillis() - start);
	}

}
