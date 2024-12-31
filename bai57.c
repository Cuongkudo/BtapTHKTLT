#include <stdio.h>
#define ll long long

void nhap(ll a[],ll n){
    ll i;
    printf("Nhap mang A: ");
    for(i=0; i<n; i++){
        printf("A[%lld]= ", i+1);
        scanf("%lld", &a[i]);
    }
}

void xuat(ll a[], ll n){
    ll i;
    printf("Mang A la: ");
    for(i=0; i<n; i++){
        printf("%lld ", a[i]);
    }
    printf("\n");
}

int check(ll a) {
    ll i, sum = 0;
    for ( i = 1; i <= a / 2; i++) {
        if (a % i == 0) {
            sum += i;
        }
    }
    return sum==a;
}

void xuatshh(ll a[], ll n){
    ll i;
    printf("So hoan hao trong mang A la: ");
    for(i=0; i<n; i++){
        if(check(a[i])) printf("%lld ", a[i]);
    }
    printf("\n");
}

int main(){
    ll n;
    printf("Nhap n= "); scanf("%lld", &n);
    while(n<10){
        printf("So n nhap vao khong hop le.\nNhap lai n= ");
        scanf("%lld", &n);
    }
    
    ll a[n];
    nhap(a, n);
    xuat(a, n);
    xuatshh(a, n);
    return 0;
}