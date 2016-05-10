#include <stdio.h>
#include <stdlib.h>


typedef union unon{
    int number;
    char* variable;
    char operation;
}unon;
typedef enum{
    bracket_open=1,
    bracket_close=1,
    plus=2,
    minus=2,
    multiply=3,
    divide=3,
    power=4
}priority;

typedef struct s{
	unon* data;
	int size;
	unon cap;
}s;

typedef struct s* stack;
stack st1;

stack st2={NULL,0,NULL};


int is_empty_stack(stack s){
	if(s->size)
		return 0;
	else 
		return 1;
}




int char_array_to_int(char* a){

    int res=0;
    int j=0;
    while(a[j]!='\0'){
        res+=a[j]-'0';
        res*=10;
        j++;
    }
    return res/10;
}
int correct_number(char* a){
    int j=0;
    int temp;
    while(a[j]!='\0'){
        temp=a[j]-'0';
        if(temp<0 || temp>9)
            return 0;
        j++;
    }
    return 1;
}


int is_bracket(char a){
    return a==')' || a=='(';
}
int is_plus_minus(char a){
    return a=='+' || a=='-';
}
int is_multiply_divide(char a){
    return a=='/' || a=='*';
}


int type_of_element(char a){
    if(is_bracket(a))
        return 1;
    if(is_plus_minus(a))
        return 2;
    if(is_multiply_divide(a))
        return 3;
    return 4;
}

int main(){
	int b;
	char a[]="1530";
	unon q;
	q.number=1;
	unon t;
	t.number=1;
	printf("%d \n",st1->size);
        return 0;
}
