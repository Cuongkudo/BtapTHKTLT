#include <stdio.h>
#define ll long long

ll somax(ll a,ll b){
    if(a>b) return a; else return b;
}

ll somin(ll a,ll b){
    if(a>b) return b; else return a;
}

int main(){
    ll x,y,z;
    printf("Nhap x: "); scanf("%lld", &x);
    printf("Nhap y: "); scanf("%lld", &y);
    printf("Nhap z: "); scanf("%lld", &z);
    printf("max(x,y,z)= %lld\n", somax(x,somax(y,z)));
    printf("min(x,y,z)= %lld\n", somin(x,somin(y,z)));
    printf("min(x+y+z,xyz)= %lld\n", somin(x+y+z,x*y*z));
    printf("(min(x+y+z/2,xyz))^2+1= %lld\n", somin(x+y+z/2,x*y*z)*somin(x+y+z/2,x*y*z)+1);
    return 0;
}