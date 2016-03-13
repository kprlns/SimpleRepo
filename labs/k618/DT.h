#pragma once
#include <stdlib.h>
#include <time.h>
const char names[20][10]={"Jacob","Michael","Joshua","Matthew","Ethan","Andrew","Daniel","William","Joseph","John","Emily","Emma","Madison","Olivia",
"Hannah","Abigail","Isabella","Ashley","Samantha","Elizabeth"};
char inits[17][5]={"J.F" , "M.M","E.D","W.J","A.Q","E.A","V.P","W.A","L.A","D.C","M.A","R.V","E.L","N.E","W.Y","O.R","K.O"};

typedef struct Person{
	char name[10];
	char initial[5];
	char gen[2];
	int group;
	int marks[4];
}Person;

void test(){
	printf("Hi\n");
}
void print_menu(){
	printf("|----------------------------------------------|\n");
	printf("|   		     Menu   	               |\n");
	printf("|----------------------------------------------|\n");
	printf("|1.	Fill the base	 		       |\n"); // REMOVE
	printf("|2.	Generate a new base	 	       |\n"); // REMOVE
	printf("|3.     Add new elements		       |\n"); //DONE
	printf("|4.     Print the base		  	       |\n"); //DONE
	printf("|5.	Remove the N-th element		       |\n"); //DONE ????TESTING????
	printf("|6.	Remove all element with the same name  |\n");
	printf("|7.	Option 18                              |\n");
	printf("|8.	Delete the base                        |\n");
	printf("|9.     Quit                                   |\n");
	printf("|----------------------------------------------|\n");
}
void add_new_elements(char* path){
	FILE* f;
	f=fopen(path,"a+b");
	Person p;
	int a;
	printf("Please enter a number of elemts:\n");
	scanf("%d",&a);
	//printf("%d",sizeof(p.marks));
	for(int i=0;i<a;i++){
		scanf("%s%s%s%d",&p.name,&p.initial,&p.gen,&p.group);
		for(int j=0;j<4;j++){
			scanf("%d",&p.marks[j]);
		}
		fwrite(&p,sizeof(Person),1,f);
	}
	//Person q;
	//rewind(f);
	//fread(&q,sizeof(Person),1,f);
	//printf("%s %s %s",q.name,q.initial,q.gen);
	fclose(f);
}
void print_a_base(char* path){
	FILE* f;
	f=fopen(path,"rb");
	Person q;
	while(fread(&q,sizeof(Person),1,f)>0){
		printf("%s %s %s %d ",q.name,q.initial,q.gen,q.group);
		for(int j=0;j<4;j++){
				printf("%d ",q.marks[j]);
		}
		printf("\n");
	}
	fclose(f);
}
void remove_nth_element(char* path,int n){
	FILE* f;
	FILE* temp;
	f=fopen(path,"rb");
	temp=fopen("temp.dat","w+b");
	int i=0;
	Person q;
	while(fread(&q,sizeof(Person),1,f)>0){
		if(i==n){
			i++;
			continue;
		}
		else{
			//fread(&q,sizeof(Person),1,f);
			fwrite(&q,sizeof(Person),1,temp);
		}			
		i++;
	}

	fclose(temp);
	temp=fopen("temp.dat","rb");
	fclose(f);
	f=fopen(path,"wb");
	
	while(fread(&q,sizeof(Person),1,temp)>0){
			fread(&q,sizeof(Person),1,temp);
			fwrite(&q,sizeof(Person),1,f);	
	}
	fclose(temp);
	fclose(f);
	remove("temp.dat");
	
}

























