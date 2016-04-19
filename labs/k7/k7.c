#include <stdio.h>
#include <stdlib.h>
#include <time.h>


typedef struct node{
    int data;
    struct node* next;
}node;

typedef struct node* list;
node start={-1,NULL};
list l=&start;

int is_empty(list l) {

    if(l->next==NULL)
        return 1;
    else
        return 0;

}
void add_elements_to_end(list l, int n) {
    //srand(time(NULL));
    list temp = l;
    if (!is_empty(temp)) {
        temp = l->next;
    }

    while (temp->next != NULL)
        temp = temp->next;

    for (int i = 0; i < n; ++i) {

        list t = malloc(sizeof(node));
        t->data = (rand() % 101 - 50);
        t->next = NULL;
        temp->next = t;
        temp=temp->next;

    }
    /*list t = malloc(sizeof(node));
    t->data = (float) (rand() % 1000 - 500.0) / (rand() % 20 + 1);
    t->next = NULL;
    temp->next = t;*/
}

void print_list(list l){

    if(is_empty(l)){
        printf("List is empty \n");
    }else{
        list temp=l;
        temp=temp->next;
        while (temp->next != NULL) {
            printf("+--------+ \n"
                           "|  Data  |\n"
                           "+--------+\n"
                           "   %d\n"
                           "+--------+\n    |\n    |\n    v\n",temp->data);
            temp = temp->next;
        }
        printf("+--------+ \n"
                       "|  Data  |\n"
                       "+--------+\n"
                       "   %d\n"
                       "+--------+\n",temp->data);
    }
}

int number_of_elements(list l){
    int n=0;
    list temp=l;
    if(!is_empty(l)){
        while(temp->next!=NULL){
            n++;
            temp=temp->next;
        }
    }
    return n;
}

void delete_element(list l,int n) {

    list temp = l;
    if (is_empty(temp)) {
        printf("Nothing to delete,list is empty");
    } else {

        if (n > number_of_elements(l)) {

            printf("No such element,there are only %d elements\n", number_of_elements(l));

        } else {

            if(n<=0){
                printf("Please dont breake my program\n");

            }else {

                for (int i = 0; i <= n; i++) {
                    if (i == (n - 1)) {
                        list delete = temp->next;
                        temp->next = delete->next;
                        free(delete);
                        break;
                    }
                    temp = temp->next;
                }
            }
        }

    }
}

void solution(list l, int f, int flag) {

    list temp = l;
    int first = -1, last = -1;
    int flag1 = 0, flag2 = 0;
    if (is_empty(temp)) {
        printf("Nothing to do here , list is empty");
    } else {
        int i = 1;
        temp = temp->next;
        while (temp->next != NULL) {
            if (temp->data == f && !flag1) {
                flag1 = 1;
                first = i;
                last = i;
            } else if (temp->data == f && flag1) {
                last = i;
            }
            temp = temp->next;
            i++;
        }
        if (temp->data == f && flag1) {
            last = i;
        }
        printf("%d %d\n", first, last);
        temp = l;
        temp = temp->next;
        int dif = last - first;
        for (int i = 1; i < first; i++) {
            delete_element(l, 1);
        }
        temp = l->next;
        printf("%d\n", temp->data);

        for (int j = 0; j < dif; j++)
            temp = temp->next;

        if (!is_empty(temp)) {
            list stay = temp;
            temp = temp->next;
            stay->next = NULL;
            while (temp->next != NULL) {
                list del = temp;
                temp = temp->next;
                free(del);
            }
            free(temp);
        }
    }
}


void print_menu(){

    printf("|----------------------------------------------|\n");
    printf("|   		     Menu   	                   |\n");
    printf("|----------------------------------------------|\n");
    printf("|1. Create a base			                   |\n"); //DONE
    printf("|2. Add new elements		                   |\n"); //DONE
    printf("|3. Add new random elements		               |\n"); //DONE
    printf("|4. Print list		  	                       |\n"); //DONE
    printf("|5.	Remove the N-th element		               |\n"); //DONE
    printf("|7.	Option 4                                   |\n");//DONE
    printf("|8.	Delete the base                            |\n"); //DONE
    printf("|9. Quit                                       |\n");//DONE
    printf("|----------------------------------------------|\n");


}
int main(int args,int argc[]) {
    /*srand(time(NULL));
    list n1 = malloc(sizeof(node));
    list n2 = malloc(sizeof(node));
    list n3 = malloc(sizeof(node));
    list n4 = malloc(sizeof(node));
    list n5 = malloc(sizeof(node));
    list n6 = malloc(sizeof(node));
    n1->data=2;
    n1->next=n2;
    n2->data=2;
    n2->next=n3;
    n3->data=1;
    n3->next=n4;
    n4->data=2;
    n4->next=n5;
    n5->data=2;
    n5->next=NULL;
    list temp = l;
    //temp->next=&n2;
    //temp=temp->next;
    add_elements_to_end(l, 2);
    add_elements_to_end(l, 1);
    add_elements_to_end(l, 1);

    while (temp->next != NULL) {
        printf("%f\n",temp->data);
        temp = temp->next;
    }
    printf("%f\n",temp->data);

    print_list(l);
    delete_element(l,1);
    printf("\n");
    print_list(l);
    printf("%d\n",number_of_elements(l));
    l->next=n1;
    temp=temp->next;
    temp->next=n2;
    temp=temp->next;
    temp->next=n3;
    temp=temp->next;
    temp->next=n4;
    temp=temp->next;
    temp->next=n5;
    temp=temp->next;
    print_list(l);
    solution(l, 1, 0);
    print_list(l);*/

    print_menu();





    return 0;
}
