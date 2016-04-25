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
int counter=0;

typedef struct node* tree;
tree t;

int has_sons(tree t){
    if(t->sons)
        return 1;
    else
        return 0;

}
tree create_a_tree(int levels){
    levels-=1;
    tree t=(node*)malloc(sizeof(node));
    t->data=(float)((rand()%100)/(rand()%7+1.0));
    t->sons=NULL;
    int nodes_for_levels=rand()%4+1;
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
        printf("%f \n",temp->n->data);
        //Finished
        temp->n=create_a_tree(levels);
        for(int i=0;i<nodes_for_levels-1;i++){
            list* l=(list*)malloc(sizeof(list));
            node* elem=(node*) malloc(sizeof(node));
            l->n=elem;
            l->n->data=(float)((rand()%100)/(rand()%7+1.0));
            l->n->sons=NULL;
            l->next=NULL;
            temp->next=l;
            printf("%f \n",temp->n->data);
            temp=temp->next;
            temp->n=create_a_tree(levels);
        }
        //printf("%d %d\n",levels,nodes_for_levels);
    }
    return t;
}
void print_a_tree(tree tr){

    for(int i=0;i<counter+1;i++)
        printf("=");

    printf("%f\n",tr->data);
    if(has_sons(tr)){

        list* temp=tr->sons;
        while(temp->next!=NULL){
            counter++;
            print_a_tree(temp->n);
            temp=temp->next;
            counter--;
        }
        counter++;
        print_a_tree(temp->n);
        counter--;
    }
}
int number_of_sons(tree tr){
    int count=0;
    if(tr->sons){
        list* temp=tr->sons;
        while(temp->next!=NULL){
            count++;
            temp=temp->next;
        }
        return count+1;
    }
    return count;
}
void add_new_node(tree tr,char* path){
    int num_of_sons=number_of_sons(tr);
    int nth=path[counter]-'0';
    if(nth>num_of_sons|| nth==0 || path[counter]=='\0'){

        if(tr->sons){
            list* temp=tr->sons;

            while(temp->next!=NULL)
                temp=temp->next;


            list* l=(list*)malloc(sizeof(list));
            node* elem=(node*) malloc(sizeof(node));
            l->n=elem;
            l->n->data=(float)((rand()%100)/(rand()%7+1.0));
            l->n->sons=NULL;
            l->next=NULL;
            temp->next=l;
        }else{
            list* l=(list*)malloc(sizeof(list));
            node* elem=(node*) malloc(sizeof(node));
            l->n=elem;
            l->n->data=(float)((rand()%100)/(rand()%7+1.0));
            l->n->sons=NULL;
            l->next=NULL;
            tr->sons=l;
        }
    }else{
        if(tr->sons) {
            list *temp = tr->sons;
            for (int i = 0; i < path[counter] - '0'-1; i++) {
                temp = temp->next;
            }
            counter++;
            add_new_node(temp->n, path);
            counter--;
        }else{
            list* l=(list*)malloc(sizeof(list));
            node* elem=(node*) malloc(sizeof(node));
            l->n=elem;
            l->n->data=(float)((rand()%100)/(rand()%7+1.0));
            l->n->sons=NULL;
            l->next=NULL;
            tr->sons=l;
        }
    }
}
void deletion(tree tr){
	if(has_sons(tr)){
		list* temp=tr->sons;
		int num_of_sons=number_of_sons(tr);
		for(int i=0;i<num_of_sons-1;i++){
			deletion(temp->n);
			temp=temp->next;
		}	
	}else{
		free(tr);
	}
}


void remove_a_node(tree tr,char* path){
	
	int nth=path[counter]-'0';
	if(number_of_sons(tr)<nth){
		printf("There are only %d sons , nothing to delte\n",number_of_sons(tr));
	}else{
		


	}
}

int main(){
    srand(time(NULL));
    t=create_a_tree(2);

    //printf("%f\n",t->data);
    //printf("%d\n",t->sons==NULL?1:0);
    printf("%lu %lu\n",sizeof(list),sizeof(node));
    print_a_tree(t);
    // printf("%d %d\n",number_of_sons(t),counter);
    printf("%d\n ",counter);
    char a[10]="11";
    add_new_node(t,a);
    printf("----------\n");
    print_a_tree(t);
    printf("%d\n",counter);
    char d[3]="1";
    remove_a_node(t,d);
    return 1;
}

