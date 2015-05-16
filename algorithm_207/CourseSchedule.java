package algorithm_207;

import java.util.HashMap;
import java.util.Iterator;

public class CourseSchedule {
	
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        boolean changed = true;
        int num = 0, preNum = prerequisites.length, courNum = 0;
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
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
        
        while(changed) {
            changed = false;
            for(int i = 0; i < courNum-num; i++) {
                if(map.get(cource[i]) == 0) {
                    preNum -= delet(cource[i], prerequisites, preNum, map);
                    cource[i] = cource[courNum-num-1];
                    num++;
                    changed = true;
                }
            }
        }
        
        return num == courNum ? true : false;
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

    public boolean canFinish2(int numCourses, int[][] prerequisites) {
        int[] status = new int[prerequisites.length];
        HashMap<Integer, Boolean> req = new HashMap<Integer, Boolean>();
        for(int i = 0; i < status.length; i++) {
            req.put(prerequisites[i][0], true);
        }
        
        for(int i = 0; i < status.length; i++) {
            if(status[i] == 0) {
                if(req.containsKey(prerequisites[i][1])) {
                    if(!search(i, i, req, status, prerequisites)) {
                        return false;
                    }
                }
            }
        }
        
        return true;
    }
    
    private boolean search(int start, int n, HashMap<Integer, Boolean> req, int[] status, int[][] prereq) {
        int t = prereq[n][1];
        if(t == prereq[n][0]) {
            return false;
        }
        status[n] = 1;
        for(int i = 0; i < status.length; i++) {
            if(t == prereq[i][0]) {
                if(status[i] == 1) {
                    return false;
                } else if(status[i] == 0) {
                    if(req.containsKey(prereq[i][1])) {
                        status[i] = 1;
                        if(!search(start, i, req, status, prereq)) {
                            return false;
                        } else {
                            status[i] = 2;
                        }
                    } else {
                        status[i] = 2;
                    }
                }
            }
        }
        status[n] = 2;
        
        return true;
    }
    
	public static void main(String[] args) {
		// TODO Auto-generated method stub
		CourseSchedule s = new CourseSchedule();
		int[][] a = {{1,0}, {2,0}};
		System.out.println(s.canFinish(3, a));
	}

}
