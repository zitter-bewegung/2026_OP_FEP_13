#include <stdio.h> 

int len(char* str) {
    int len;
    for (int i = 0; ; i++){
        if (str[i] == '\0'){
            len = i;
            break;  }
    }
    return len - 1;   
}

int main(){
    char str[255];
    fgets(str, 255, stdin);
    printf("%d\n", len(str));
    return 0; 
}