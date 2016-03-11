#pragma once
#include <stdlib.h>
#include <time.h>
char names[20][20]={"Jacob","Michael","Joshua","Matthew","Ethan","Andrew","Daniel","William","Joseph","John","Emily","Emma","Madison","Olivia",
"Hannah","Abigail","Isabella","Ashley","Samantha","Elizabeth"};



typedef struct Person{
	char* name;
	int group;
	double mark;
}Person;

void test(){
	printf("Hi\n");
}
void print_menu(){
	printf("|----------------------------------------------|\n");
	printf("|   		     Menu   	               |\n");
	printf("|----------------------------------------------|\n");
	printf("|1.	Fill the base	 		       |\n");
	printf("|2.	Generate a new base	 	       |\n");
	printf("|3.     Add new element		  	       |\n");
	printf("|4.	Remove the N-th element		       |\n");
	printf("|5.	Remove all element with the same name  |\n");
	printf("|6.	Option                                 |\n");
	printf("|7.	Delete the base                        |\n");
	printf("|8.     Quit                                   |\n");
	printf("|----------------------------------------------|\n");
}

void generate_a_base(){
	int amount;
	FILE *f;
	srand((unsigned) time(0) );
	printf("Please enter amount of elements:\n");
	scanf("%d",&amount);
	f=fopen("Generated_base","wb");
	char c[10];
	for(int i=0;i<amount;i++){
		Person p;
		int rand_names=rand()%20;
		int group=rand()%8+1;
		double mark=(rand()%100+1.0);
		p.name=names[rand_names];
		p.group=group;
		p.mark=mark;	
		printf("%s %d %f\n",p.name,p.group,p.mark);
		fwrite(&p, sizeof(p),1,f);
	}
	fclose(f);
}
void read_a_base(char* c[]){
	//FILE* f;
	//f=fopen(&c,"rb");
	//char d[20];
	//while (1){
	//	Person p;
	//	fread(&p.name,1,10,f);
		


	//}


}
