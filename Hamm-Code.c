#include<stdio.h>
#include<math.h>
int main()
{
    char Dataword[10];
    int n,r,k,r1,r2,r3,r4;
    printf("Enter the number of bits - ");
    scanf("%d",&k);
    for(r=1;r<=k;r++){

    n=k+r;
    if (k<=(pow(2,r)-1)){
        printf("\nThe number of redundancy bits is - %d\n",r);
        break;
    }
    }
    printf("Enter the 8-bit dataword ");
    scanf("%s",&Dataword);
    printf("Value of n is %d\n",n);
    int Codeword[n];
    for (int i=0; i<=k-1; i++){
    int m=Dataword[i]-'0';
    printf("\n%d\n",m);
    }

    int a=1;
    int q=0;
    for (int i=n;i>=1;i--){
        if ((i==1) || (i==2 )|| (i==4) ||(i==8))
        {
            Codeword[i-1]=0;
            a++;
        }
        else
        {
            int dk= Dataword[q]-'0';
            Codeword[i-1]=dk;
            q++;
        }
    }

    n=n+1;
    int re[r];
    int i,j;
    for(i=0;i<r;i++){
        re[i]=0;
        for(j=pow(2,i);j<=n;j++){
                //printf("The value of j %d\n", j);
                    for(k=1;k<=(pow(2,i));k++){
                            if((n-k-j)<0 ){
                                break;
                            }
            re[i]=re[i]+Codeword[(k+j-2)];
            printf("Value of Codeword[%d] is %d\n",k+j-1,Codeword[(k+j-2)]);
            //printf("Value of re[%d] inside loop %d\n index - %d\n",i+1, re[i],n-(k+j));
                    }
                    //printf("j%d\n\n",j);

            j+=pow(2,i);
            j+=pow(2,i);
            j--;
//printf("j%d\n\n",j);

        }
        if(re[i]%2==0){
            re[i]=0;
        }
        else{
            re[i]=1;
        }
        printf("Value of r%d - %d\n", i,re[i]);
    }
    Codeword[0]=re[0];
    Codeword[1]=re[1];
    Codeword[3]=re[2];
    Codeword[7]=re[3];

    printf("Codeword is  - ");
    for (int i=n-2;i>=0;i--)

    {
    printf("%d",Codeword[i] );
}
}
