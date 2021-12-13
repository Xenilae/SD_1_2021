#include <iostream>
#include <fstream>
#include <conio.h>
#define max 50
using namespace std;
int a[max][max],gp[max],gm[max],v[max];
int n,i,j,k,ok;
int main();
int nevizitat() {
int i;
for (i=1;i<=n;i++)
if (v[i]==0) return i;
return -1;
}
int main() {
system("cls");
cout<<"Număr de varfuri "; cin>>n;
ifstream f;
f.open("in.txt");
for (i=1; i<=n; i++)
for (j=1; j<=n; j++)
f>>a[i][j];
f.close();
for (i=1; i<=n; i++) v[i]=0;
do{
k=nevizitat();
if (k!=-1){
for (i=1;i<=n;i++) gp[i]=a[k][i];
do {
ok=0;
for (j=1;j<=n;j++)
if(gp[j]==1)
for (i=1;i<=n;i++)
if ((a[j][i]==10&& gp[i]==0)) {
ok=1;
gp[i]=1; }
} while (ok==1);
for (i=1;i<=n;i++) gm[i]=a[i][k];
do {
ok=0;
for(j=1;j<=n;j++)
if (gm[j]==1)
for(i=1;i<=n;i++)
if((a[i][j]==1)&&(gm[i]==0)) {
ok=1;
gm[i]=1; }
}while (ok==1);
for (i=1;i<=n;i++)
if ((gp[i]==1)&&(gm[i]==1)) {
cout<<i<<",";
v[i]=1; }
if (k==nevizitat()) {
v[k]=1;
cout<<k; }
cout<<endl;
} }while (k!=-1);
_getch();
}