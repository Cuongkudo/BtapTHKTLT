#include <stdio.h>
#include <math.h>
#define db double
#define ll long long
#define eps 1e-6

db tinhcos(db x) {
    db temp = 1, t = 1;
    ll n = 2;
    while (fabs(temp) >= eps) {  
        temp *= (-1.0 * x * x) / (n * (n - 1));
        t += temp;
        n += 2;
    }
    return t;
}

int main() {
    db x;
    printf("Nhap so do x= ");
    scanf("%lf", &x);
    x = x * M_PI / 180.0;  
    printf("Cos(x)= %.4lf\n", tinhcos(x));
    printf("Tinh theo ham chuan Cos(x)= %.4lf\n", cos(x));
    return 0;
}
