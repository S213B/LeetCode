void prepro(char * pat, int * r) {
    int i, j;
    
    *r = -1;
    if(strlen(pat) == 1) {
        return;
    }
    if(*pat == *(pat+1)) {
        *(r+1) = -1;
    } else {
        *(r+1) = 0;
    }
    
    for(i = 2, j = 0; i < strlen(pat);) {
        if(*(pat+i-1) == *(pat+j)) {
            *(r+i) = ++j;
            if(*(pat+i) == *(pat+*(r+i))) {
                *(r+i) = *(r+*(r+i));
            }
            i++;
        } else {
            j = *(r+j);
            if(j == -1) {
                *(r+i) = ++j;
                i++;
            }
        }
    }
    
    return;
}

int strStr(char* haystack, char* needle) {
    int * lps;
    int i, j;
    
    if(strlen(needle) == 0) {
        return 0;
    }
    
    lps = (int*) malloc(sizeof(int) * strlen(needle));
    
    prepro(needle, lps);
    
    for(i = 0, j = 0; i < strlen(haystack);) {
        if(*(haystack+i) == *(needle+j)) {
            j++;
            if(j == strlen(needle)) {
                free(lps);
                return i-j+1;
            }
            i++;
        } else {
            j = *(lps+j);
            if(j == -1) {
                j = 0;
                i++;
            }
        }
    }
    
    free(lps);
    return -1;
}
