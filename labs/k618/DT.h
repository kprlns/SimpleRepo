#pragma once
#include <stdlib.h>
#include <time.h>
char names[20][20]={"Jacob","Michael","Joshua","Matthew","Ethan","Andrew","Daniel","William","Joseph","Christopher","Emily","Emma","Madison","Olivia",
"Hannah","Abigail","Isabella","Ashley","Samantha","Elizabeth"};



typedef struct Person{
	char name[20];
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
	scanf("%d\n",&amount);
	f=fopen("Generated_base.dat","w+b");
	for(int i=0;i<amount;i++){
		int rand_names=rand()%20;
		int group=rand()%8+1;
		double mark=(rand()%100+1.0);
		fprintf(f,"%s %d %f\n",names[rand_names],group,mark);
	}
	fclose(f);




}
void read_a_base(FILE *f){



}
