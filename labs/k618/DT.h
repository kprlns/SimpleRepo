#pragma once
#include <stdlib.h>
#include <time.h>
char names[20][10]={"Jacob","Michael","Joshua","Matthew","Ethan","Andrew","Daniel","William","Joseph","John","Emily","Emma","Madison","Olivia",
"Hannah","Abigail","Isabella","Ashley","Samantha","Elizabeth"};
char inits[17][5]={"J.F" , "M.M","E.D","W.J","A.Q","E.A","V.P","W.A","L.A","D.C","M.A","R.V","E.L","N.E","W.Y","O.R","K.O"};
char gen[2][2]={"M","F"};

typedef struct Person{
	char* name;
	char* init;
	char* gen;
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
	printf("|1.	Fill the base	 		       |\n"); 
	printf("|2.	Generate a new base	 	       |\n"); // DONE
	printf("|3.     Add new element		  	       |\n"); 
	printf("|4.     Print the base		  	       |\n"); //DONE
	printf("|5.	Remove the N-th element		       |\n");
	printf("|6.	Remove all element with the same name  |\n");
	printf("|7.	Option                                 |\n");
	printf("|8.	Delete the base                        |\n");
	printf("|9.     Quit                                   |\n");
	printf("|----------------------------------------------|\n");
}
int read_a_person(char* path){
	printf("%s\n",path);
	FILE* f;
	f=fopen(path,"rb");
	if(f) printf("Succes\n");
	Person q;
	int ans=fread(&q,sizeof(Person),1,f);
	//printf("%s %d ",q.name,q.group);
	/*for(int j=0;j<4;j++){
		printf("%d ",q.marks[j]);
	}*/
	//printf("\n");
	return ans;
}
void generate_a_base(){
	int amount;
	FILE *f;
	srand( (unsigned) time(0) );
	printf("Please enter amount of elements:\n");
	scanf("%d",&amount);
	f=fopen("Generated_base","wb");
	char c[10];
	for(int i=0;i<amount;i++){
		Person p;
		int rand_names=rand()%20;
		int group=rand()%8+1;
		int initial=rand()%17;
		if(rand_names<10)
			p.gen=gen[0];			
		else
			p.gen=gen[1];

		p.name=names[rand_names];
		p.init=inits[initial];
		p.group=group;
		for(int j=0;j<4;j++){
			p.marks[j]=2+(rand()%4);
		}
		//printf("%s %d %f\n",p.name,p.group,p.mark);
		fwrite(&p, sizeof(p),1,f);
	}
	fclose(f);
}
void write_a_base(char* c){
	FILE* f;
	f=fopen(c,"rb");
	Person p;
	while(fread(&p,sizeof(p),1,f)){

		printf("%s %s %s %d ",p.name,p.init,p.gen,p.group);

		for(int j=0;j<4;j++){
			printf("%d ",p.marks[j]);
		}

		printf("\n");
	}
}

void fill_the_base(char* base){
	int amount;
	FILE *f;
	srand( (unsigned) time(0) );
	printf("Please enter amount of elements:\n");
	scanf("%d",&amount);
	f=fopen(base,"a+b");
	char c[10];
	for(int i=0;i<amount;i++){
		Person p;
		int rand_names=rand()%20;
		int group=rand()%8+1;
		int initial=rand()%17;

		if(rand_names<10)
			p.gen=gen[0];			
		else
			p.gen=gen[1];

		p.name=names[rand_names];
		p.init=inits[initial];
		p.group=group;
		for(int j=0;j<4;j++){
			p.marks[j]=2+(rand()%4);
		}
		fwrite(&p, sizeof(p),1,f);
	}
	fclose(f);
}





/*void read_a_base(char* c){
	FILE* f;
	f=fopen(c,"rb");
	Person p;
	while(fread(&p,sizeof(p),1,f)){

		printf("%s %s %s %d ",p.name,p.init,p.gen,p.group);

		for(int j=0;j<4;j++){
			printf("%d ",p.marks[j]);
		}

		printf("\n");
	}
}*/










