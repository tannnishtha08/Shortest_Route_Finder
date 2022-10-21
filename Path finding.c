/* C Program to find Shortest Distances or Path using Dijkstra's algorithm */

#include<stdio.h>
#include<string.h>

#define MAX 100
#define DIM 50



void Dijkstra( int source, int dest);
void create_graph();

int Number_of_Vertex ;    /* Denotes number of vertices in the graph */
int path[MAX];  
char City_list[DIM][25];
int adjacent_matrix[DIM][DIM];



int main()
{
        int Counter,s,v,flag,source_pos,dest_pos;
        char source[25], desti[25];
        
		create_graph(); //Function call for Creatin adjacency matrix of the Graph.

        printf("\nEnter source vertex : ");
        scanf("%s",&source);
        // Validation of Source and Destination of a Search Instance.
		
		Counter=0;flag=0;source_pos=0;
		while(Counter<Number_of_Vertex)
		{
			if(!(strcmp(City_list[Counter],source)))
			{
				flag=1;source_pos=Counter;
			}	
			Counter++;
		}
		if(flag==0)
        {
        	printf("\nThis vertex %s does not exist\n",source);
        	getch();
			return 0;
        }   
        
		printf("\nEnter destination vertex(Q to quit): ");
        scanf("%s",&desti);
		
		Counter=0;flag=0;dest_pos=0;
		while(Counter<Number_of_Vertex)
		{
			if(!(strcmp(City_list[Counter],desti)))
			{
				flag=1;dest_pos=Counter;
			}	
			Counter++;
		}
		if(flag==0)
        {
        	printf("\nThis vertex %s does not exist\n",desti);
        	getch();
			return 0;
        }   
		                
        Dijkstra(source_pos,dest_pos);
		getch();
		return 0;
}/*End of main()*/


void Dijkstra( int source, int dest)
{
 	int Node_popped=0, Node_Expanded=0, Node_Generated=0; 
    struct queue{
		unsigned short int Node;
		unsigned short int Parent;
   		               int g_n;
	                   int f_n;
	                   int d
   		struct queue *Parent_Node;
			    };
	typedef struct queue *SNode;
	
	SNode Generated_Node[MAX], Temp_Node;
    int Generated_list[MAX];
    int front=0,rear=-1,GNode_counter=0;
    int index,index1,counter, Closed_list[MAX];
    
	for(index=0;index<MAX;index++)
		Closed_list[index]=-1;
	
	Temp_Node=(struct queue*)malloc(sizeof(struct queue));	
	
	Temp_Node->Node= source;
    Temp_Node->Parent= MAX
    Temp_Node->g_n=0;
   // Temp_Node->g_n=0;
    //Temp_Node->f_n=0;
    Temp_Node->d=0;
    Temp_Node->Parent_node=NULL;
    
    Generated_Node[front++]=Temp_Node;
    Generated_list[Node_Generated++]=source;
    
    printf("\nNode Popped: %d",Node_popped);
    printf("\nNodes Expanded: %d",Node_Expanded);
    printf("\nNodes Generated: %d",Node_Generated);
    
    while(Generated_Node[++rear].Node!=dest)
    {
    	for(index=0;index<Number_of_Vertex;index++)	
    	{
	    	if(adjacent_matrix[Generated_Node[rear].Node][index]!=0)
	    	{
	    		Generated_Node[front].Node= index;
    			Generated_Node[front].Parent_node= Generated_Node[rear].Node
    			Generated_Node[front++].Cost+= adjacent_matrix[Generated_Node[rear].Node][index];
    		//	Generated_Node[front++].Total_cost+= adjacent_matrix[Generated_Node[rear].Node][index];	
	    	}
	    }
	    for(index1=rear+1;index1<(front-1);index1++)	
    	{
	    	for(index=rear+1;index<(front-1);index++)	
    		{
		    	if(Generated_Node[index].Cost>Generated_Node[index+1].Cost)
		    	{
	    			Temp_Node.Node = Generated_Node[index].Node;
	    			Temp_Node.Parent_node= Generated_Node[index].Parent_node;
    				Temp_Node.Cost= Generated_Node[index].Cost;	
    			    Generated_Node[index].Node=Generated_Node[index+1].Node;
	    			Generated_Node[index].Parent_node=Generated_Node[index+1].Parent_node;
    				Generated_Node[index].Cost=Generated_Node[index+1].Cost;
    				Generated_Node[index].Node=Temp_Node.Node;
	    			Generated_Node[index].Parent_node=Temp_Node.Parent_node;
    				Generated_Node[index].Cost=Temp_Node.Cost;
	    		}
		    }	
	    }
	    for(index=rear;index<front;index++)	
    	{
	    	printf("\n%d, %d, %d",Generated_Node[index].Node,Generated_Node[index].Parent_node,Generated_Node[index].Cost);
    	}
    	if(Generated_Node[++rear].Node==dest)
    		break;
   		else
   		{
		 	  	
	   	}
    }
     
        
}
// End of Dijkstra( )
*/

void create_graph()
{
    FILE *fp;
    int i,i1,i2,f,f_v,max_edges,origin,destin, wt;
    char s_origin[255],s_destin[255],s_wt[255];
	
	if((fp=fopen("Input2.txt", "r"))==NULL) //Reading from Input File.
	{
		printf("CallRecord can not open");     
		{getch();exit(0);}
	}
	
	i1=0;
	for(i=0;i<28;i++)
	{
		// Each pair of nodes represented by S_origin and s_destin.
		fscanf(fp, "%s", s_origin);
		printf("Origin : %s\n",s_origin);
		fscanf(fp, "%s", s_destin);
		printf("Destination : %s\n",s_destin);
		fscanf(fp, "%s", s_wt); //Reading weight for a pair of node.
		wt=atoi(s_wt);
		printf("Cost : %d\n",wt);
		
		i2=0;f=0;f_v=0;
	// Creating a Unique List of City from the Input File.
	
		while(i2<i1)
		{
			if(!(strcmp(City_list[i2],s_origin)))
			{
				f=1;f_v=i2;
			}	
			i2++;
		}
	    if(f==0)
		{
			strcpy(City_list[i1++],s_origin);
			origin=i1-1;
		}	
	    else 
	    	origin=f_v;
		
		i2=0;f=0;f_v=0;
		while(i2<i1)
		{
			if(!(strcmp(City_list[i2],s_destin)))
			{
				f=1;f_v=i2;
			}	
			i2++;
		}
	    if(f==0)
		{
			strcpy(City_list[i1++],s_destin);
			destin=i1-1;
		}	
	    else 
	    	destin=f_v;
        // Creating Adjacency Metrix of the Graph.
        adjacent_matrix[origin][destin] = wt;
        adjacent_matrix[destin][origin] = wt;
	    
		
	}
	getch();
	fclose(fp);
	// Display for testing.
	Number_of_Vertex =i1+1;
	for(i=0;i<i1;i++)
	printf("%d[%s] ",i,City_list[i]);
	
	for(i=0;i<i1;i++)
	{
		printf("\n");
		for(i2=0;i2<i1;i2++)
			printf("%4d",adjacent_matrix[i][i2]);
	}
}