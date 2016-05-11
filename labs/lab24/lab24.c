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
    int* type;
    int size;
    unon cap;
}s;

typedef struct mass{
    unon* arr;
    int* type;
    int size;
}mass;

typedef struct mass* m;
typedef struct s* stack;

stack st1=(stack)malloc(sizeof(s));
stack st2=(stack)malloc(sizeof(s));

int is_empty_stack(stack s){
    if(s->size)
        return 0;
    else
        return 1;
}
int size_of_stack(stack s){
    return s->size;
}
void push_back(stack st,unon u){
    if(is_empty_stack(st)){
        st->data=(unon*)malloc(100*sizeof(unon));
        st->data[0]=u;
        st->cap=u;
        st->size=1;
    }else{
        st->data[st->size]=u;
        st->size++;
        st->cap=u;
    }
}
void pop_back(stack s){
    if(!is_empty_stack(s)){
        s->size--;
    }
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
int is_power(char a){
    return a=='^';
}

int size_of_string(char* a){
    int j=0;
    while(a[j]!='\0')
        j++;
    return j;
}

int correct_bracket(char* a){
    int res=0;
    for(int i=0;i<size_of_string(a);i++){
        if(a[i]=='(')
            res++;
        else if(a[i]==')')
            res--;
        if(res<0)
            return 0;
    }
    if(res)
        return 0;
    else
        return 1;
}
int is_digit(char a){
    int t=a-'0';
    if(t<0 || t>9)
        return 0;
    else
        return 1;
}
int is_alpha(char a){
    if((a>=65 && a<=90) || (a>=97 && a<=122))
        return  1;
    else
        return 0;
}
m string_to_union_array(char* a){

    m res=(m)malloc(sizeof(mass));
    int siz=size_of_string(a);
    res->arr=(unon*)malloc(siz*sizeof(unon));
    res->type=(int*)malloc(siz*sizeof(int));
    res->size=0;
    int j=0;
    for(int i=0;i<size_of_string(a);i++){

        if( (a[i]=='-' && a[i-1]=='(') ){
            int temp=i+1;
            if(is_digit(a[i+1])){
                while(a[temp]!=')' && a[temp]!='-' && a[temp]!='+' && a[temp]!='*' && a[temp]!='/' && a[temp]!='^'){
                    if(!is_digit(a[temp])){
                        printf("Invalid variable \n");
                        return 0;
                    }else
                        temp++;
                }
                printf("its my temp:%d %d\n",temp,i);
                int size=temp-i;
                char* ar=(char*) malloc((size+1)*sizeof(char));
                int q=0;
                for(;q<size-1;q++){
                    ar[q]=a[i+q+1];
                }
                ar[q]='\0';
                int test=char_array_to_int(ar);
                test*=-1;
                res->arr[j].number=test;
                res->type[j]=1;
                j++;
                i=temp;
            }else{
                temp++;
                while(a[temp]!=')' && a[temp]!='-' && a[temp]!='+' && a[temp]!='*' && a[temp]!='/' && a[temp]!='^'){
                    if(!is_digit(a[temp]) && !is_alpha(a[temp])){
                        printf("Invalid variable \n");
                        return 0;
                    }else
                        temp++;
                }
                printf("its my temp:%d %d\n",temp,i);
                int size=temp-i;
                char* ar=(char*) malloc((size+1)*sizeof(char));
                int q=0;
                for(;q<size;q++){
                    ar[q]=a[i+q];
                }
                ar[q]='\0';
                res->arr[j].variable=ar;
                res->type[j]=2;
                j++;
                i=temp;
            }
        }else if(is_digit(a[i])){
            int temp=i+1;
            while(a[temp]!=')' && a[temp]!='-' && a[temp]!='+' && a[temp]!='*' && a[temp]!='/' && a[temp]!='^'){
                if(!is_digit(a[temp]) && !is_alpha(a[temp])){
                    printf("Invalid variable \n");
                    return 0;
                }else
                    temp++;
            }
            printf("end of number:%d\n",temp);
            int size=temp-i;
            char* ar=(char*) malloc((size+1)*sizeof(char));
            for(int q=0;q<size;q++){
                ar[q]=a[i+q];
            }
            int test=char_array_to_int(ar);
            printf("%d <- number in expr \n",test);
            res->arr[j].number=test;
            res->type[j]=1;
            j++;
            i=temp;
        }else  if(is_alpha(a[i])){
            int temp=i+1;
            while(a[temp]!=')' && a[temp]!='-' && a[temp]!='+' && a[temp]!='*' && a[temp]!='/' && a[temp]!='^'){
                if(!is_digit(a[temp]) && !is_alpha(a[temp])){
                    printf("Invalid variable \n");
                    return 0;
                }else
                    temp++;
            }
            printf("end of positive variable:%d\n",temp);
            int size=temp-i;
            char* ar=(char*)malloc(size*sizeof(char));
            int q=0;
            for(;q<size;q++){
                ar[q]=a[i+q];
            }
            ar[size]='\0';
            res->arr[j].variable=ar;
            res->type[j]=2;
            j++;
        }
        if (a[i] == '(' || a[i] == ')' || a[i] == '-' || a[i] == '+' || a[i] == '*' || a[i] == '/' || a[i] == '^') {
                unon temp;
                temp.operation = a[i];
                res->arr[j] = temp;
                res->type[j]=3;
                j++;
        }

    }
    res->size=j;
    return res;
}
int type_of_element(char a){
    if(is_bracket(a))
        return 1;
    if(is_plus_minus(a))
        return 2;
    if(is_multiply_divide(a))
        return 3;
    if(is_power(a))
        return 4;
    return 0;
}

void print_union_array(m ms){
    for(int i=0;i<ms->size;i++){
        switch(ms->type[i]){
            case 1:
                printf("%d",ms->arr[i].number);
                break;
            case 2:
                printf("%s",ms->arr[i].variable);
                break;
            case 3:
                printf("%c",(char)ms->arr[i].operation);
                break;
        }
    }
}
m dijkstra(m expr){
    




}
int main(){
    char a[100];
    unon q;
    q.number=1;
    unon t;
    t.number=2;
    printf("%d !1 \n",is_empty_stack(st1));
    push_back(st1,q);
    printf("%d !2 \n",size_of_stack(st1));
    push_back(st1,t);
    printf("%d !3 \n",size_of_stack(st1));
    pop_back(st1);
    printf("%d !4 \n",size_of_stack(st1));
    char r[]="(((-12)+b*4)+5)";
    printf("%d !5 \n",correct_bracket(r));
    m test=string_to_union_array(r);
    printf("%d !6\n",is_alpha('a'));
    print_union_array(test);

    return 0;
}
