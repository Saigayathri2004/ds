#include<stdio.h>
#include<stdlib.h>
#define MAX 100
#define initial 1
#define waiting 2
#define visited 3
int n;
int adj[MAX][MAX];
int state[MAX];
void create_graph();
void DFS_Traversal();
void DFS(int v);
int stack[MAX], top = -1;
void insert(int vertex);
int delete();
int isEmpty();
int main()
{
create_graph();
DFS_Traversal();
return 0;
}
void DFS_Traversal()
{
int v;
for(v=0; v<n; v++)
state[v] = initial;
 printf("Enter 
StartVertex for DFS: \n");
scanf("%d", &v);
DFS(v);
}
void DFS(int v)
{
int i;
printf("DFS traversal");
insert(v);
state[v] = waiting;
while(!isEmpty())
{
v = delete();
printf("%d ",v);
state[v] = visited;
for(i=0;i<n;i++)
{
if(adj[v][i] == 1 && state[i] == initial)
{
insert(i);
state[i] = waiting;
}
}
}
printf("\n");
}
void insert(int vertex)
{
if(top == MAX-1)
printf("stack Overflow\n");
else
{
top++;
stack[top] = vertex ;
}
}
int isEmpty()
{
if(top==-1)
return 1;
else
return 0;
}
int delete()
{
int delete_item;
if(top == -1)
{
printf("stack empty\n");
exit(1);
}
delete_item = stack[top];
top--;
return delete_item;
}
void create_graph()
{
int count,max_edge,origin,destin;
printf("Enter number of vertices : ");
scanf("%d",&n);
max_edge = n*(n-1);
for(count=1;count<=max_edge;count++)
{
printf("Enter edge %d( -1 -1 to quit ) : ",count);
scanf("%d %d",&origin,&destin);
if((origin == -1) && (destin == -1))
break;
if(origin>=n || destin>=n || origin<0 || destin<0)
{
printf("Invalid edge!\n");
count--;
}
else
{
adj[origin][destin] = 1;
}
}
}
