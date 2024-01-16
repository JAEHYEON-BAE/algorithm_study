#include <ios>
int main()
{
        long long int x1, y1, x2, y2, x3, y3, x4, y4;
        scanf("%lld%lld%lld%lld%lld%lld%lld%lld", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
        if ((x2-x1)*(y4-y3) == (x4-x3)*(y2-y1)) {
                if ((y3-y1)*(x2-x1)==(y2-y1)*(x3-x1)) {
                        if (x1 != x2 && ((x3-x1)*(x3-x2)<=0 || (x4-x1)*(x4-x2)<=0 || (x1-x3)*(x1-x4)<=0 || (x2-x3)*(x2-x4)<=0)) {
                                printf("1"); return 0;
                        }
                        if (x1 == x2 && ((y3-y1)*(y3-y2)<=0 || (y4-y1)*(y4-y2)<=0 || (y1-y3)*(y1-y4)<=0 || (y2-y3)*(y2-y4)<=0)) {
                                printf("1"); return 0;
                        }
                        printf("0"); return 0;
                }
                else {printf("0"); return 0;}
        }

        long long int d123 = (x2-x1)*(y3-y1) - (y2-y1)*(x3-x1);
        long long int d124 = (x2-x1)*(y4-y1) - (y2-y1)*(x4-x1);
        long long int d341 = (x4-x3)*(y1-y3) - (y4-y3)*(x1-x3);
        long long int d342 = (x4-x3)*(y2-y3) - (y4-y3)*(x2-x3);
        if (((d123<=0 && d124>=0) || (d123>=0 && d124<=0)) && ((d341<=0 && d342>=0) || (d341>=0 && d342<=0))) {
                printf("1"); return 0;}
        else {printf("0"); return 0;}
}