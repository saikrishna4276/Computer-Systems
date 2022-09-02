#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void main(){
    time_t s,val=1;
    struct tm* curr_time;
    s=time(NULL);
    curr_time=localtime(&s);
printf("System Time:%02d:%02d:%02d\n",curr_time->tm_hour,curr_time->tm_min,curr_time->tm_min);
struct timespec begin,end,begin2;
clock_gettime(CLOCK_REALTIME, &begin);
double **mat1, **mat2,**res;
int i,j,n,k;
n=1024;
mat1= (double**) malloc(n*sizeof(double*));
for(i=0;i<n;i++)
    mat1[i]=(double*)malloc(n*sizeof(double));

mat2= (double**) malloc(n*sizeof(double*));

for(i=0;i<n;i++)
    mat2[i]=(double*)malloc(n*sizeof(double));

res=(double**)calloc(n,sizeof(double*));

for(i=0;i<n;i++)
    res[i]=(double*)calloc(n,sizeof(double));
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        mat1[i][j]=1.5;
        mat2[i][j]=1.5;
    }
}
clock_gettime(CLOCK_REALTIME,&begin2);
for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
            res[i][j]=0;
            for(k=0;k<n;k++)
                res[i][j]+= mat1[i][k]*mat2[k][j];
    }
}
clock_gettime(CLOCK_REALTIME, &end);
long double ex=(end.tv_sec-begin2.tv_sec)+((end.tv_nsec-begin2.tv_nsec)*1e-9);
long double nanoseconds=(end.tv_sec-begin.tv_sec)+((end.tv_nsec-begin.tv_nsec)*1e-9);
printf("Whole program execution time is:%Lf\n",nanoseconds);
printf("Matrix multiplication execution time is:%Lf\n",ex);
printf("Percentage:%Lf\n",(ex/nanoseconds)*100);
/*for(i=0;i<n;i++)
{
    for(j=0;j<n;j++)
    {
        printf("%f",res[i][j]);
    }
    printf("\n");
}*/

printf("System time:%02d:%02d:%02d\n",curr_time->tm_hour,curr_time->tm_min,curr_time->tm_min);
}
