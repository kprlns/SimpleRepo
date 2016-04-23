#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node{
    float data;
    struct list* sons;

}node;

typedef struct list{
	struct node* n;
	struct list* next;	
}list;


typedef struct node* tree;
tree t;

int has_sons(tree t){
	if(t->sons==NULL)
		return 1;
	else
		return 0;

}	
tree create_a_tree(tree tr,int levels){
	levels-=1;
	tree t=(node*)malloc(sizeof(node));
	t->data=(float)((rand()%100)/(rand()%7+1.0));
	t->sons=NULL;
	int nodes_for_levels=rand()%5+1;
	list* temp=t->sons;
	if(levels>0){
		//Added one node
		list* l=(list*)malloc(sizeof(list));
		node* elem=(node*) malloc(sizeof(node));
		l->n=elem;
		l->n->data=(float)((rand()%100)/(rand()%7+1.0));
		l->n->sons=NULL;
		l->next=NULL;
		temp=l;
		t->sons=temp;
		printf("%f \n",l->n->data);
		//Finished
		create_a_tree(temp->n,levels);
		for(int i=0;i<nodes_for_levels-1;i++){
			list* l=(list*)malloc(sizeof(list));
			node* elem=(node*) malloc(sizeof(node));
			l->n=elem;
			l->n->data=(float)((rand()%100)/(rand()%7+1.0));
			l->n->sons=NULL;
			l->next=NULL;
			temp->next=l;
			printf("%f \n",l->n->data);
			temp=temp->next;
			create_a_tree(temp->n,levels);
		}	
	//	printf("%d %d\n",levels,nodes_for_levels);
	}

	return t;
}



int main(){
	srand(time(NULL));
	t=create_a_tree(t,3);
	//printf("%f\n",t->data);
	//printf("%d\n",t->sons==NULL?1:0);
	printf("%lu %lu\n",sizeof(list),sizeof(node));
	return 1;
}

