#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int a[220000];
int b[220000],manz,colo;
int hashh[220000],ahash[220000],ahashc[220000];
int brank[220000];
struct asd
{
    int data,yb;
};
asd aa[220000];
int n,m,p,pi=0;
int prin[220000];
bool comp(asd a,asd b)
{
    if (a.data<b.data) return true;else return false;
}
void jia(int zhi,int zf)
{
    if (ahashc[zhi]!=colo)
    {
        ahashc[zhi]=colo;
        ahash[zhi]=0;
    }
    if (ahash[zhi]==hashh[zhi]) manz-=hashh[zhi];
    ahash[zhi]+=zf;
    if ((ahash[zhi]==hashh[zhi])) manz+=hashh[zhi];
}
int main()
{
    int i,j,ii;
    scanf("%d%d%d",&n,&m,&p);
    for (i=0;i<=m;i++)
    {
        hashh[i]=0;
        ahashc[i]=0;
    }
    for (i=1;i<=n;i++)
    {
        aa[i].yb=i;
        scanf("%d",&aa[i].data);
    }
    for (i=1;i<=m;i++)
        scanf("%d",&b[i]);
    sort(b+1,b+1+m);
    sort(aa+1,aa+1+n,comp);
 //   cout<<b[1]<<b[2]<<endl;
    brank[1]=1;
    for (i=2;i<=m;i++)
    {
        if (b[i]==b[i-1]) brank[i]=brank[i-1];else
            brank[i]=brank[i-1]+1;
        hashh[brank[i]]++;
    }
    hashh[1]++;
    j=1;
    for (i=1;i<=n;i++)
    {
        while ((b[j]<aa[i].data)&&(j<m)) j++;
        if (aa[i].data==b[j]) a[aa[i].yb]=brank[j]; else
            a[aa[i].yb]=0;
    }
   // cout<<brank[1]<<brank[2]<<a[3]<<endl;
    manz=0;
    for (i=1;i<=p;i++)
    {
        manz=0;
        colo=i;
        for (j=0;j<=m-1;j++)
        {
            if (i+j*p>n) break;
            jia(a[i+j*p],1);

        }
        //if (i+j*p>n) continue;
        if (manz==m) prin[++pi]=i;
        ii=1;
        while ((m+ii-1)<=(n-i)/p)
        {
            jia(a[i+(ii-1)*p],-1);
            jia(a[i+(ii+m-1)*p],1);
            if (manz==m) prin[++pi]=i+ii*p;
             ii++;
        }
    }
    sort(prin+1,prin+1+pi);
    printf("%d\n",pi);
    for (i=1;i<=pi-1;i++) printf("%d ",prin[i]);
    if (pi!=0) printf("%d\n",prin[pi]);
}
