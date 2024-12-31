#include <stdio.h>
#define ll long long
#define db double

int check(db x){
    ll i;
    for(i=1; i<=63; i+=2){
        if(x==i){
            return 1;
            break;
        }
    }
    
}

db bt1(db x){
    ll i;
    db gt=1;
    for(i=1; i<=63; i+=2){
        gt*= (1+(-1)/(x-i));
    }
    return gt;
}

ll bt2(ll n){
    ll i=3,j=1 , t=2, temp=2;
    while(i<=2*n){
        temp= temp*i*(i+1)/j;
        t+= temp;
        j++;
        i+=2;
    }
    return t;
}

int main(){
    db x;
    printf("Nhap x: "); scanf("%lf", &x);
    if(check(x)==1){
        printf("Bieu thuc A khong ton tai.\n\n");
    } else {
        printf("Gia tri bieu thuc A= %.2lf\n\n", bt1(x));
    }
    
    ll n;
    printf("Nhap n: "); scanf("%lld", &n);
    printf("Gia tri bieu thuc B= %lld\n", bt2(n));
    return 0;
}