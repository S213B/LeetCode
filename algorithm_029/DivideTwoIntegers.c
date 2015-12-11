int divide(int dividend, int divisor) {
    bool positive;
    int num[32], exp[32], r = 0, i;
    if(divisor == 0 || (dividend == INT_MIN && divisor == -1)) {
        return INT_MAX;
    }
    if(((dividend ^ divisor) & 0x80000000) == 0) {
        positive = true;
    } else {
        positive = false;
    }
    
    if(dividend > 0) {
        dividend = 0-dividend;
    }
    if(divisor > 0) {
        divisor = 0-divisor;
    }
    if(dividend > divisor) {
        return 0;
    }
    
    num[0] = divisor;
    exp[0] = 1;
    for(i = 1; i < 32; i++) {
        if(dividend-num[i-1] > num[i-1]) {
            i--;
            break;
        }
        num[i] = num[i-1] + num[i-1];
        exp[i] = exp[i-1] + exp[i-1];
    }
    for(; i >= 0; i--) {
        if(dividend-num[i] <= 0) {
            dividend -= num[i];
            r += exp[i];
        }
    }
    
    return positive ? r : (0-r);
}
