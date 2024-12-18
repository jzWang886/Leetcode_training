#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int SquareSum(int n){
    int total = 0;
    while(n>0){
        total += ((n%10) * (n%10));
        n /= 10;
    }
    return total;
}

bool isHappy(int n){
    bool checkRepeatTable[1000] = {false};
    n = SquareSum(n);
    while(!checkRepeatTable[n]) {
        if(n == 1) return true;
        checkRepeatTable[n] = true;
        n = SquareSum(n);
    }
    return false;
}

int main(){
    int n;
    bool ans;
    scanf("%d", &n);
    
    ans = isHappy(n);
    printf("Answer is %s\n", ans ? "true":"false");

    return 0;
}
