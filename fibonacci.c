#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//question1
int fibonacci(int n){
    if(n==0 ||n==1 ){
        return n;
    }
    else{
        return fibonacci(n-1)+fibonacci(n-2);
    }
} 
//question2
long long fibonacci_dp(int n){
    if(n<=1){
        return n;
    }
    long long *fib=malloc((n+1)*sizeof(long long));
    fib[0]=0;
    fib[1]=1;
    for(int i=2;i<=n;i++){
        fib[i]=fib[i-1]+fib[i-2]
    }
    long long r=fib[n];
    free(fib);
    return r;
}
//question 3
void main(){
    int n=40
    clock_t start_fibonacci=clock();
    long long res1=fibonacci(n);
    clock_t end_fibonacci=clock();
    double diff1=(end_fibonacci-start_fibonacci)/CLOCKS_PER_SEC;
    clock_t start_fibonaccidp=clock();
    long long res2=fibonacci_dp(n);
    clock_t end_fibonaccidp=clock();
    double diff1=(end_fibonaccidp-start_fibonaccidp)/CLOCKS_PER_SEC;
    printf("Naif (n = %d) : %lld | Temps : %f s\n", n, res1, diff1);
    printf("DP   (n = %d) : %lld | Temps : %f s\n", n, res2, diff2);
    return 0;






}