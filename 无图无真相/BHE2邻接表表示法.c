#include <stdio.h>
#include <stdlib.h>
#define MAX 100

//声明作为顶点集元素的结构体 
struct graph_point 
{
	int point_num;//顶点值
	struct graph_line *next;//指向连通关系集的next指针
};

//声明作为连通关系集结点的结构体 
struct graph_line 
{
	int line_point;//与该顶点邻接的顶点的值
	struct graph_line *next;//next指针
};

typedef struct graph_point Gpoint;//声明别名
typedef struct graph_line Gline;

int main(void)
{
	Gpoint g1[MAX];
	void creat_graph(Gpoint *g);
	creat_graph(g1);
	return 0;
} 



void creat_graph(Gpoint *g)
{
	int p_num,l_num,i,h,l;
	Gline *p;//作为结点空间 
	printf("请输入顶点数：");
	scanf("%d",&p_num);
	
	for (i=0;i<p_num;i++)
	{
		printf("请输入第%d个顶点的值：",i+1);
		scanf("%d",&(g+i)->point_num);
		(g+i)->next=NULL;
	} 
	printf("请输入边数：");
	scanf("%d",&l_num);
	
	for(i=0;i<l_num;i++)
	{
		//对于有向图而言，<V1,V2>和<V2,V1>是两种连通关系 
		//将输入的两个顶点的信息分解开来，变成两个邻接表的结点 
		
		printf("请输入第%d条边连接的两个顶点（Vi，Vj):",i+1);
		scanf("%d %d",&h,&l);
		
		//申请结点空间，若失败则退出 
		p=(Gline*)malloc(sizeof(Gline));
		if(p==NULL)
		{
			printf("error!");
			return; 
		}
		
		//头插法 
		
		//将该结点的next指针指向当前顶点指向的地址
		p->next=g[h].next;
		//邻接序号为l(l是h的邻接序号~） 
		p->line_point=l; 
		//将当前顶点的next指针指向p 
		(g+h)->next=p;
		
		//重复上面步骤将另一结点插入到另一对应顶点集元素
		p=(Gline*)malloc(sizeof(Gline));
		if(p==NULL)
		{
			printf("error!");
			return;
		}
		
		p->next=(g+l)->next;
		p->line_point=h;
		(g+l)->next=p;
	}
	
	printf("图构建完成!图中顶点为：\n");
	
	for(i=0;i<p_num;i++)
	{
		printf("%d ",(g+i)->point_num);
	} 
		printf("\n");
		printf("图中的连通关系为：\n"); 
	
	for(i=0;i<p_num;i++)
	{
		printf("第%d个顶点的值为%d",i+1,(g+i)->point_num);
		
		//如果存在邻接的顶点，则输出 
		if((g+i)->next!=NULL)
		{
			printf("\n");
			printf("与它邻接的顶点为：");
			p=(g+i)->next;
			
			while(p!=NULL)
			{
				printf("%d ",p->line_point);
				p=p->next;
			}
			printf("\n"); 
	    }
		
		else
		{
			printf("\n");
		} 
	}
}





































