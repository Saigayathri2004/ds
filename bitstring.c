void display() 
{ 
top1=top; 
 if(top1==NULL) 
{ 
printf("\nEmpty stack!!\n"); 
return; 
} 
while(top1!=NULL) 
{ 
printf("%d--->",top1->data); 
top1=top1->link; 
} 
printf("NULL\n"); 
}
{
t=1;
break;
}
}
if(t==1)
sa[i]=1;
else
sa[i]=0;
}
printf("\nbitstring ofA\n");
for(i=0;i<N;i++)
{
printf("%d\t",sa[i]);
}
for(i=0;i<N;i++)
{
t=0;
for(j=0;j<N;j++)
{
if(b[j]==u[i])
{
t=1;
break;
}
}
if(t==1)
sb[i]=1;
else
sb[i]=0;
}
printf("\nbitstring ofB\n");
for(i=0;i<N;i++)
{
printf("%d\t",sb[i]);
}
printf("\n---------------------------------------------------------------------------------
-------");
for(i=0;i<10;i++)
{
if(sa[i]==1||sb[i]==1)
cs[i]=1;
else
cs[i]=0;
}
printf("\nunion bit set\n");
printf("\n");
for(i=0;i<10;i++)
{
printf("%d\t",cs[i]);
}
printf("\nunion number set\n");
for(i=0;i<10;i++)
{
if(cs[i]==1)
{
c[k]=u[i];
printf("%d\t",c[k]);
k++;
}
}
printf("\n---------------------------------------------------------------------------------
-------");
for(i=0;i<10;i++)
{
if(sa[i]==1 && sb[i]==1)
ds[i]=1;
else
ds[i]=0;
}
printf("\nintersection bit set\n");
printf("\n");
for(i=0;i<10;i++)
{
printf("%d\t",ds[i]);
}
printf("\nintersection number set\n");
for(i=0;i<10;i++)
{
if(ds[i]==1)
{
d[k]=u[i];
printf("%d\t", d[k]);
k++;
}
}
printf("\n");
/*for(i=0;i<k;i++)
{
printf("%d\t",d[i]);
}*/
return 0;
}