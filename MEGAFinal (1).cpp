#include<bits/stdc++.h>
#include <time.h>       /* time */

using namespace std;
int arr[100][100],i,val,j,k,r,reward=0,m,n,z[100],arms=10,chosenarm,lower=0,upper=9,checkarm[100],meanrew[100],x,c,d,rew[100][100];
float p=0.5,al=0.5,be=0.5,po=0.5;

void collision(int yq,int u,int a1[100][100],int z1[100], int val,int zbc1)
{

    int a=1,i;
    float t;
    for(int y=val;y>1;y--)
    {
    int l=(rand()%(upper-lower+1))+lower;
    printf("Random arm generated = %d\n",l);
    float pr=(float)rand()/((float)RAND_MAX/a);
    printf("pr=%0.2f\n",pr);
    if(pr>=0.5 && z1[l]==0)
    {
        --z1[u];
        ++z1[l];
        printf("\n");
        for(i=9;i>=0;i--)
        {
            if(a1[i][yq]==u)
            {
                a1[i][yq]=l;
                printf("new alloted arms is = %d\n\n",a1[i][yq]);
                break;
            }
        }

    }
    else
    {
        printf("user is refrained from transmitting in this round\n\n");


    }
    }
    for(int wq=0;wq<zbc1;wq++)
    {
        printf("updated column %d\n",a1[wq][yq]);
    }
    printf("\n");
    return ;
}
int epsilon(int k,int t)
{
    float et,pe;
    pe=(c*k*k)/(d*d*(k-1)*t);
    if(pe<1)
    {
        et=pe;
    }
    else
    {
        et=1;
    }
    return et;
}
int choice(int arr1[100],int rex[100],int z1[100])
{
    int k,Count=0,epsi;
    int aa=1,j=0,p0,p;

    if(z1[k]!=0)
    {
        printf("exploit");
        return k;
    }
    else
    {
        for(int i=0;i<10;i++)
        {
            if(z1[i]==0)
            {
                arr1[j]=i;
                ++j;
                ++Count;
            }
        }
        if(Count==0)
        {
            printf("refrained");
            int arm1=rand()%10;
        }
        else
        {
          //  float epsi=epsilon();
             float pro=(float)rand()/((float)RAND_MAX/aa);
             if(pro<epsi)
             {
             //   int newarm=choice(arr1);
               int newarm;
			    if(k!=newarm)
                {
                    p=p0;
                }

             }
             else
             {
                 sort(rex,rex+10,greater<int>());
                 k=rex[0];
             }
        }
        return k;
    }
}

int main()
{
 //   memset(checkarm,0,100);
   for(i=0;i<100;i++)
   {
       for(j=0;j<100;j++)
       {
           rew[i][j]=0;
       }
   }

	srand(time(NULL));
	int zbc=5;
    for(j=0;j<10;j++)
    {
        memset(z,0,sizeof(z));
        printf("for time slot t = %d\n\n",j);

        for(i=0;i<zbc;i++)
        {

            arr[i][j]=(rand()%(upper-lower+1))+lower;
            printf("Selected arms for user %d is = %d \n",i,arr[i][j]);
            ++z[arr[i][j]];


        }
        printf("\n");
        i=0;
        for(i=0;i<10;i++)
        {
        	printf("%d ",z[i]);
        }
        printf("\n\n");
        for(k=0;k<5;k++)
        {
            float p=0.5;
            if(z[k]>1)
            {

                printf("collision \n");
                r=k;
                printf("Arm on which collision occuring = %d\n",r);
                val = z[k];

                collision(j,r,arr,z,val,zbc);

            }
            else
            {
                printf(" no collision on %d arm\n",k);
                p=p*al+(1-al);
                printf("changed persistance prob. = %.2f \n\n",p);
                if(z[k]==1)
                {
                    //++rew[k][j];
                    rew[k][j] = rew[k][j-1]+1;
                    printf("updated reward = %d\n\n",rew[k][j]);
                }
                //float eps=epsilon(k,j);
                //printf("exploration probability = %f\n\n",eps);
            }
        }
        /*for(x=0;x<10;x++)
        {
            meanrew[x]=rew[x][j]+meanrew[x];

        }*/

    }
    return 0;
}

