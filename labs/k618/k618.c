#include <stdio.h>
#include "DT.h"

int main(int args,char* arg[]){

	print_menu();
	char nam[10]="mike";
	//for(int i=0;i<17;i++)
	//	printf("%s\n",inits[i]);
	//generate_a_base();
	print_a_base("Generated_base");
	printf("------------------\n");
	//add_new_elements("Generated_base");
	//remove_nth_element("Generated_base",0);
	//delete_with_same_name("Generated_base",&nam);
	solution_18("Generated_base");
	print_a_base("Generated_base");
 	//print_a_base("Generated_base");
	//print_a_base("Generated_base");
	return 0;
}

