package algorithm_150;

public class EvaluateReversePolishNotation {
	
    public int evalRPN(String[] tokens) {
        int[] stack = new int[5000];
        int top = 0;
        for(int i = 0; i < tokens.length; i++) {
            if(tokens[i].equals("+")) {
                stack[top-2] += stack[top-1];
                top --;
            } else if(tokens[i].equals("-")) {
                stack[top-2] -= stack[top-1];
                top --;
            } else if(tokens[i].equals("*")) {
                stack[top-2] *= stack[top-1];
                top --;
            } else if(tokens[i].equals("/")) {
                stack[top-2] /= stack[top-1];
                top --;
            } else {
                stack[top++] = Integer.parseInt(tokens[i]);
            }
        }
        
        return stack[0];
    }

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}

}
