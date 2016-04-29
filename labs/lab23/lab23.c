#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_LEVEL = 15
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
int levels[16];
int has_sons(tree t){
    if(t->sons)
        return 1;
    else
        return 0;

}

int len(char* a){
    int i=0;
    while(a[i]!='\0')
        i++;
    return i;
}

int correct_path(char* a){

    for(int i=0;a[i]!='\0';i++){
        if( a[i]<48 || a[i]>57){
            return 0;
        }

    }
    return 1;
}

int is_empty_tree(tree tr){
    if(tr)
        return 0;
    else
        return 1;
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
        //printf("%f \n",temp->n->data);
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
            //printf("%f \n",temp->n->data);
            temp=temp->next;
            temp->n=create_a_tree(levels);
        }
        //printf("%d %d\n",levels,nodes_for_levels);
    }
    return t;
}
void print_a_tree(tree tr,int flag){
    if(is_empty_tree(tr)){
        printf("This tree is empty\n");
    }else {
        if(!flag) {
            for (int i = 0; i < counter + 1; i++)
                printf("=");
        }
        if(!flag)
            printf("%f\n", tr->data);
        if(flag)
            levels[counter]++;
        if (has_sons(tr)) {

            list *temp = tr->sons;
            while (temp->next != NULL) {
                counter++;
                print_a_tree(temp->n,flag);
                temp = temp->next;
                counter--;
            }
            counter++;
            print_a_tree(temp->n,flag);
            counter--;
        }
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
void add_new_node(tree tr,char* path,int flag){
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
            if(flag)
                l->n->data=(float)((rand()%100)/(rand()%7+1.0));
            else
                scanf("%f",&l->n->data);
            l->n->sons=NULL;
            l->next=NULL;
            temp->next=l;
        }else{
            list* l=(list*)malloc(sizeof(list));
            node* elem=(node*) malloc(sizeof(node));
            l->n=elem;
            if(flag)
                l->n->data=(float)((rand()%100)/(rand()%7+1.0));
            else
                scanf("%f",&l->n->data);
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
            add_new_node(temp->n, path,flag);
            counter--;
        }else{
            list* l=(list*)malloc(sizeof(list));
            node* elem=(node*) malloc(sizeof(node));
            l->n=elem;
            if(flag)
                l->n->data=(float)((rand()%100)/(rand()%7+1.0));
            else
                scanf("%f",&l->n->data);
            l->n->sons=NULL;
            l->next=NULL;
            tr->sons=l;
        }
    }
}


void deletion_sons(tree tr){
    if(has_sons(tr)){
        list* temp=tr->sons;
        int num_of_sons=number_of_sons(tr);
        for(int i=0;i<num_of_sons-1;i++){
            deletion_sons(temp->n);
            //free(temp->n);
            temp=temp->next;
        }
    }else{
        free(tr);
    }
}


void remove_a_node(tree tr,char* path){
    if(!len(path) || !correct_path(path)){
        printf("Sorry connot delete this node (uncorrect path)\n");
    }else{
        int nth=path[counter]-'0';
        if(number_of_sons(tr)<nth || !(tr->sons)){
            printf("Sorry there are only %d sons connot delete anything\n",number_of_sons(tr));
        }else{

            list* temp=tr->sons;

            if(path[counter+1]=='\0'){

                if(nth==1){
                    if(number_of_sons(tr)==1){
                        tr->sons=NULL;
                        deletion_sons(temp->n);
                    }else{
                        tr->sons=temp->next;
                        deletion_sons(temp->n);
                    }
                }else {
                    for (int i = 0; i < nth-2; ++i) {
                        temp = temp->next;
                    }
                    list* del=temp->next;
                    temp->next=del->next;
                    deletion_sons(del->n);
                    free(del);
                }
            }else{
                counter++;
                for(int i=0;i<nth-1;i++){
                    temp=temp->next;
                }
                remove_a_node(temp->n,path);
                counter--;
            }

        }
    }
}

void print_menu(){
    printf("|----------------------------------------------|\n");
    printf("|   		     Menu                          |\n");
    printf("|----------------------------------------------|\n");
    printf("|1. Create a tree		                       |\n");
    printf("|2. Print tree		                           |\n");
    printf("|3. Add new node to tree automatically	  	   |\n");
    printf("|4. Add new node to tree manually	  	       |\n");
    printf("|5.	Remove node		                           |\n");
    printf("|6.	Delete tree                                |\n");
    printf("|7.	Task 34			                           |\n");
    printf("|8. Quit                                       |\n");
    printf("|----------------------------------------------|\n");
}
tree delete_tree(tree tr){
    deletion_sons(tr);
    //free(tr);
    tr=NULL;
    return tr;
}
int find_max_level(int* a){
    int max=a[0];
    int i=0;

    for(int j=1;j<17;j++){
        if(a[j]>max){
            i=j;
            max=a[j];
        }
    }
    return i+1;
}
int main(){
    srand(time(NULL));
    print_menu();
    int num;
    int lvl;
    char path[15];
    while(1){
        scanf("%d",&num);
        switch(num){
            case 1:
                printf("How much levels for tree?\n");
                scanf("%d",&lvl);
                t=create_a_tree(lvl);
                break;
            case 2:
                printf("---------\n");
                print_a_tree(t,0);
                printf("---------\n");
                break;
            case 3:
                printf("Write a path to the node:\n");
                scanf("%s",path);
                add_new_node(t,path,1);
                break;
            case 4:
                printf("Write a path to the node:\n");
                scanf("%s",path);
                add_new_node(t,path,0);
                break;
            case 5:
                printf("Write a path to the node:\n");
                scanf("%s",path);
                remove_a_node(t,path);
                break;
            case 6:
                t=delete_tree(t);
                break;
            case 7:
                print_a_tree(t,1);
                printf("%d\n",find_max_level(levels));
                break;
            case 8:
                return 0;
            default:
                printf("Please use number from 1 to 7\n");
                break;
        }
    }
}
