+/*INPUT:- 5
 +OUTPUT:-
 +1
 +1 2
 +2 3 5
 +5 7 10 15
 +15 20 27 37 52
 +*/
 +#include<stdio.h>
 +#include<conio.h>
 +#include<string.h>
 +int belln(int x)
 +{int i,j;
 +printf("enter bell no. :");
 +scanf("%d",&x);
 +int bell[x][x];
 +bell[0][0]=1;
 +printf("%d",bell[0][0]);
 +printf("\n");
 +for(i=1;i<=x-1;i++)
 +{
 +    int a=bell[i][0]=bell[i-1][i-1];
 +    printf("%d ",a);
 +    for(j=1;j<=i;j++)
 +    {
 +        int b=bell[i][j]=bell[i-1][j-1]+bell[i][j-1];
 +        printf("%d ",b);
 +    }
 +    printf("\n");
 +}
 +return bell[x-1][x-1];
 +}
 +int main()
 +{
 +int n,p;
 +        printf("bell series number is %d ",belln(n));
 +return 0;
 +}
