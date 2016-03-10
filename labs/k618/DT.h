#pragma once

char names[20][20]={"Jacob","Michael","Joshua","Matthew","Ethan","Andrew","Daniel","William","Joseph","Christopher","Emily","Emma","Madison","Olivia",
"Hannah","Abigail","Isabella","Ashley","Samantha","Elizabeth"};



typedef struct Person{
	char name[20];
	int group;
	int mark;
}Person;

void test(){
	printf("Hi\n");
}
void print_menu(){
	printf("|----------------------------------------------|\n");
	printf("|   		     Menu   	               |\n");
	printf("|----------------------------------------------|\n");
	printf("|1.	Fill the base	 		       |\n");
	printf("|2.     Add new element		  	       |\n");
	printf("|3.	Remove the N-th element		       |\n");
	printf("|4.	Remove all element with the same name  |\n");
	printf("|5.	Option                                 |\n");
	printf("|6.	Delete the base                        |\n");
	printf("|7.     Quit                                   |\n");
	printf("|----------------------------------------------|\n");
}
void generate_a_base(FILE *f){



}
void read_a_base(FILE *f){



}
