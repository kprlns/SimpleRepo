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
        st->type=(int*)malloc(100*sizeof(int));
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
        if(s->size!=0)
            s->cap=s->data[s->size-1];
        else{
            unon temp;
            temp.operation='&';
            s->cap=temp;
        }
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
int type_of_element(char a){
    if(is_bracket(a))
        return 10;
    if(is_plus_minus(a))
        return 20;
    if(is_multiply_divide(a))
        return 30;
    if(is_power(a))
        return 40;
    return 0;
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
                while(!type_of_element(a[temp])){
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
                while(!type_of_element(a[temp])){
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
            while(!type_of_element(a[temp])){
                if(!is_digit(a[temp]) && !is_alpha(a[temp])){
                    printf("Invalid variable \n");
                    return 0;
                }else
                    temp++;
            }
            printf("end of number:%d\n",temp);
            int size=temp-i;
            char* ar=(char*) malloc((size+1)*sizeof(char));
            int q=0;
            for(;q<size;q++){
                ar[q]=a[i+q];
            }
            ar[size+1]='\0';
            int test=char_array_to_int(ar);
            printf("%d <- number in expr \n",test);
            res->arr[j].number=test;
            res->type[j]=1;
            j++;
            i=temp;
        }else  if(is_alpha(a[i])){
            int temp=i+1;
            while(!type_of_element(a[temp])){
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
        if (type_of_element(a[i])) {
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


void print_union_array(m ms){
    for(int i=0;i<ms->size;i++){
        switch(ms->type[i]){
            case 1:
                printf("%d ",ms->arr[i].number);
                break;
            case 2:
                printf("%s ",ms->arr[i].variable);
                break;
            case 3:
                printf("%c ",ms->arr[i].operation);
                break;
            default:
                break;
        }
    }
}
m dijkstra(m expr){
    m res=(m)malloc(sizeof(mass));
    res->arr=(unon*)malloc(expr->size*sizeof(unon));
    res->type=(int*)malloc(expr->size*sizeof(int));
    int n;
    int j=0;
    for(int i=0;i<expr->size;i++){
        n=expr->type[i];
        switch(n){
            case 1:
                res->type[j]=expr->type[i];
                res->arr[j]=expr->arr[i];
                res->size++;
                j++;
                break;
            case 2:
                res->type[j]=expr->type[i];
                res->arr[j]=expr->arr[i];
                res->size++;
                j++;
                break;
            case 3:
                if(is_empty_stack(st1)){
                    push_back(st1,expr->arr[i]);
                    st1->type[st1->size-1]=3;
                } else {
                    int type = type_of_element(expr->arr[i].operation);
                    unon q = expr->arr[i];
                    /*10 - скобки
                     * 20 - (+ и -)
                     * 30 - (* и /)
                     * 40 - ^
                     * */
                    int cp = type_of_element(st1->cap.operation);
                    if (cp >= type && type!=10) {
                        res->arr[j]=st1->cap;
                        res->type[j]=3;
                        res->size++;
                        j++;
                        pop_back(st1);
                        while(type>=type_of_element(st1->cap.operation) && st1->cap.operation!='('){
                            res->arr[j]=st1->cap;
                            res->type[j]=3;
                            res->size++;
                            pop_back(st1);
                            j++;
                        }
                        push_back(st1,expr->arr[i]);
                        st1->type[st1->size-1]=3;
                    } else {
                        if (type == cp && !is_bracket(expr->arr[i].operation)) {
                            res->arr[j] = st1->cap;
                            res->type[j] = 3;
                            res->size++;
                            pop_back(st1);
                            push_back(st1, expr->arr[i]);
                            st1->type[st1->size - 1] = 3;
                            j++;
                        } else {
                            if (is_bracket(expr->arr[i].operation) && expr->arr[i].operation == ')') {
                                while (st1->cap.operation != '(') {
                                    res->arr[j] = st1->cap;
                                    res->type[j] = 3;
                                    res->size++;
                                    j++;
                                    pop_back(st1);
                                }
                                pop_back(st1);
                            } else {
                                push_back(st1, expr->arr[i]);
                            }
                        }
                    }
                }
                break;
            default:
                break;
            /*T0D0
             * нормально обработать пункт 3 для разных элементов сделано????
             * */
        }
    }
    return res;
}
int main(){
    unon q;
    q.number=1;
    unon t;
    t.number=2;
    printf("%d !1 \n",is_empty_stack(st2));
    push_back(st2,q);
    printf("%d !2 \n",size_of_stack(st2));
    push_back(st2,t);
    printf("%d !3 \n",size_of_stack(st2));
    pop_back(st1);
    printf("%d !4 \n",size_of_stack(st2));
    char r[]="((((-12)+b*4)+5)+1)";
    char d[]="(3+4*2/(1-5)^2)";
    printf("%d !5 \n",correct_bracket(d));
    m test=string_to_union_array("(26+(x*(5))+(3*x)+(5*3))");
    printf("%d !6\n",is_alpha('a'));
    print_union_array(test);
    printf("\n");
    m test2=dijkstra(test);
    print_union_array(test2);
    return 0;
}
