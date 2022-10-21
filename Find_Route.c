/* C Program to find Shortest Distances or Path using Dijkstra's algorithm */

#include<stdio.h>
#include<string.h>

#define MAX 100
#define DIM 50



void Dijkstra( int source, int dest);
void create_graph(char file_name[100]);

int Number_of_Vertex ;    /* Denotes number of vertices in the graph */
int path[MAX];  
char City_list[DIM][25];
int adjacent_matrix[DIM][DIM];



int main(int argc, char** argv)
{
        int i,Counter,s,v,flag,source_pos,dest_pos;
        char source[25], desti[25];
		
		create_graph(argv[1]); //Function call for Creatin adjacency matrix of the Graph.

   
     // Validation of Source and Destination of a Search Instance.
		strcpy(source,argv[2]);
		Counter=0;flag=0;source_pos=0;
		while(Counter<21)
		{
			if(!(strcmp(City_list[Counter],source)))
			{
				flag=1;source_pos=Counter;
				break;
			}	
			Counter++;
			printf("C:%d ",Counter);
		}
		if(flag==0)
        {
        	printf("\nThis vertex %s does not exist\n",source);
        	getch();
        }   
        else{
        	strcpy(desti,argv[3]);
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
        	}	   
        }

//     	Finding shortest Route :	
  		if(flag!=0)
		   		Dijkstra(source_pos,dest_pos);
       	else
       			printf("Path does't exit");
  
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
   		         //      int h_n;
	                   int f_n;
	    unsigned short int d;
   		struct queue *Parent_Node;
			    };
	typedef struct queue *SNode;
	
	SNode Generated_Node[MAX], Temp_Node, Temp, Temp1;
    int Generated_list[MAX];
    int front=0,rear=-1,GNode_counter=0,Route[MAX];
    int index,index1,counter, Closed_list[MAX], Closed_LC=0, flag;
    float M_Cost;
    
	for(index=0;index<MAX;index++)
		Closed_list[index]=-1;
	
	Temp_Node=(struct queue*)malloc(sizeof(struct queue));	
	
	Temp_Node->Node= source;
    Temp_Node->Parent= MAX;
    Temp_Node->g_n=0;
   // Temp_Node->h_n=0;
    Temp_Node->f_n=0;
    Temp_Node->d=0;
    Temp_Node->Parent_Node=NULL;
    
    Generated_Node[front++]=Temp_Node;
    Generated_list[Node_Generated++]=source;
  //  Node_Generated++;
    printf("\nNode Popped: %d",Node_popped);
    printf("\nNodes Expanded: %d",Node_Expanded);
    printf("\nNodes Generated: %d",Node_Generated);
    
    printf("\n Fringe:");
	for(index=rear+1;index<front;index++)	
    	{
	    		Temp=Generated_Node[index];	
	    		printf("\n");
		    do{
				printf("< state = %s, g(n)= %d, d = %d  Parent : ",City_list[Temp->Node],Temp->f_n,Temp->d);	
	    		Temp=Temp->Parent_Node;	
	    	}while(Temp!=NULL);
		}
	printf("\n Closed :[");
	for(counter=0;counter<Closed_LC;counter++)
		 	printf("%s ",City_list[Closed_list[counter]]);	
	printf("]");
   	rear++;
   	Node_popped++;
   	Node_Expanded++;
  	

    while(Generated_Node[rear]->Node!=dest)
    {
        getch();
		Closed_list[Closed_LC++]=Generated_Node[rear]->Node;
				 		 	
    	printf("\n Popping Node %d : ",Node_popped);
    	Temp=Generated_Node[rear];	
   		printf("\n");
	    do{
	    		printf("< state = %s, g(n)= %d, d = %d  Parent : ",City_list[Temp->Node],Temp->f_n,Temp->d);
				Temp=Temp->Parent_Node;	
    	}while(Temp!=NULL);
		
		
		for(index=0;index<Number_of_Vertex;index++)	
    	{
	    	if(adjacent_matrix[Generated_Node[rear]->Node][index]!=0)
	    	{
				Temp_Node=(struct queue*)malloc(sizeof(struct queue));	
	
				Temp_Node->Node= index;
				Temp_Node->Parent= Generated_Node[rear]->Node;
    			Temp_Node->g_n=adjacent_matrix[Generated_Node[rear]->Node][index];
   			 	// Temp_Node->h_n=0;
    			Temp_Node->f_n=Generated_Node[rear]->f_n+Temp_Node->g_n;
    			Temp_Node->d=Generated_Node[rear]->d+1;
    			Temp_Node->Parent_Node=Generated_Node[rear];
    			
				Generated_Node[front++]=Temp_Node;
				Node_Generated++;
 	    	}
	    }
	    for(index1=rear+1;index1<(front-1);index1++)	
    	{
	    	for(index=rear+1;index<(front-1);index++)	
    		{
		    	if(Generated_Node[index]->f_n>Generated_Node[index+1]->f_n)
		    	{
	    			Temp = Generated_Node[index];
	    			Generated_Node[index]=Generated_Node[index+1];
	    			Generated_Node[index+1]=Temp;
    			}
		    }	
	    }
	    printf("\nNode Popped: %d",Node_popped);
    	printf("\nNodes Expanded: %d",Node_Expanded);
    	printf("\nNodes Generated: %d",Node_Generated);
    	 printf("\n Fringe:");
	    for(index=rear+1;index<front;index++)	
    	{
	    		Temp=Generated_Node[index];	
	    		printf("\n");
		    do{
	    		printf("< state = %s, g(n)= %d, d = %d  Parent : ",City_list[Temp->Node],Temp->f_n,Temp->d);
				Temp=Temp->Parent_Node;	
	    	}while(Temp!=NULL);
		}
		printf("\n Closed :[");
	   	for(counter=0;counter<Closed_LC;counter++)
			 	printf("%s ",City_list[Closed_list[counter]]);	
		printf("]");	 	
		
		do{ rear++;
			if(rear==front) 
			{
				printf("\n\nPath not possible");
				return 0;
			}
				Node_popped++;
			    for(counter=0,flag=0;counter<Closed_LC;counter++)
				{
					if(Generated_Node[rear]->Node==Closed_list[counter])
					{
						flag=1; break;
					}
				 			
				}
			
	   	}while(flag!=0);

 		Node_Expanded++;
    }
   
		printf("\n Popping Node %d : ",Node_popped);
    	Temp=Generated_Node[rear];	
   		index=0;
        printf("\n");
	    do{
	    		printf("< State = %s, g(n)= %d, d = %d  Parent : ",City_list[Temp->Node],Temp->f_n,Temp->d);
				Route[index++]=Temp->Node;
				Temp=Temp->Parent_Node;	
    	}while(Temp!=NULL);
    	
    	printf("\nNode Popped: %d",Node_popped);
    	printf("\nNodes Expanded: %d",Node_Expanded);
    	printf("\nNodes Generated: %d",Node_Generated);
    	M_Cost=Generated_Node[rear]->f_n;
		printf("\nDistance: %0.1f km",M_Cost);
		printf("\nRoute: ");
		for(index1=index-1;index1>0;index1--)
		{
			M_Cost=adjacent_matrix[Route[index1]][Route[index1-1]];
			printf("\n %s to %s, %0.1f km",City_list[Route[index1]],City_list[Route[index1-1]],M_Cost);
		}
}
// End of Dijkstra( )


void create_graph(char file_name[100])
{
    FILE *fp;
    int i,i1,i2,f,f_v,max_edges,origin,destin, wt;
    char s_origin[255],s_destin[255],s_wt[255],Str_f[200];
	
	if((fp=fopen(file_name, "r"))==NULL) //Reading from Input File.
	{
		printf("Sorry File %s can not open",file_name); 
		{getch();exit(0);}
	}
	
	for(i=0;;i++)
	{
		// Each pair of nodes represented by S_origin and s_destin.
		fscanf(fp, "%s", s_origin);
		fscanf(fp, "%s", s_destin);
		fscanf(fp, "%s", s_wt); //Reading weight for a pair of node.
		wt=atoi(s_wt);
		strcpy(Str_f,s_origin);
		strcat(Str_f," ");
		strcat(Str_f,s_destin);
		strcat(Str_f," ");
		strcat(Str_f,s_wt);
		if(!strcmp(Str_f,"END OF INPUT"))
			break;
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
	fclose(fp);
	// Display for testing.
	Number_of_Vertex =i1+1;
	printf("\n");
	for(i=0;i<i1;i++)
	printf("%d[%s] ",i,City_list[i]);
	
/*	for(i=0;i<i1;i++)
	{
		printf("\n");
		for(i2=0;i2<i1;i2++)
			printf("%4d",adjacent_matrix[i][i2]);
	}
	*/
}
// End of create_graph( )