package algorithm_210;

import java.util.HashMap;
import java.util.Iterator;

public class CourseScheduleII {
	
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        boolean changed = true;
        int num = 0, preNum = prerequisites.length, courNum = 0, rl = 0;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        int[] r = new int[numCourses];
        
        for(int i = 0; i < prerequisites.length; i++) {
            if(!map.containsKey(prerequisites[i][1])) {
                map.put(prerequisites[i][1], 0);
            }
            if(map.containsKey(prerequisites[i][0])) {
                map.put(prerequisites[i][0], map.get(prerequisites[i][0])+1);
            } else {
                map.put(prerequisites[i][0], 1);
            }
        }
        Iterator<Integer> keys = map.keySet().iterator();
        int[] cource = new int[map.size()];
        while(keys.hasNext()) {
            int key = keys.next();
            cource[courNum++] = key;
        }
        for(int i = 0; i < numCourses; i++) {
            if(!map.containsKey(i)) {
                r[rl++] = i;
            }
        }
        
        while(changed) {
            changed = false;
            for(int i = 0; i < courNum-num; i++) {
                if(map.get(cource[i]) == 0) {
                    r[rl++] = cource[i];
                    preNum -= delet(cource[i], prerequisites, preNum, map);
                    cource[i] = cource[courNum-num-1];
                    num++;
                    changed = true;
                }
            }
        }
        
        return num == courNum ? r : new int[0];
    }
    
    private int delet(int n, int[][] prereq, int preNum, HashMap<Integer, Integer> map) {
        int r = 0;
        for(int i = 0; i < preNum - r;) {
            if(prereq[i][1] == n) {
            	map.put(prereq[i][0], map.get(prereq[i][0])-1);
                prereq[i][0] = prereq[preNum-r-1][0];
                prereq[i][1] = prereq[preNum-r-1][1];
                r++;
            } else {
            	i++;
            }
        }
        
        return r;
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
