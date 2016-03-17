#include <stdio.h>
#include "DT.h"

int main(int args,char* arg[]){
	
	while(1){
	char base[30],name[10];
	print_menu();
	int n;
	int k;
	scanf("%d",&n);
	switch(n){
	case 1:
		scanf("%s",&base);
		create_a_base(&base);		
		break;
	case 2:
		scanf("%s",&base);
		add_new_elements(&base);		
		break;
	case 3:
		scanf("%s",&base);
		print_a_base(&base);		
		break;
	case 4:
		scanf("%s %d",&base,&k);
		remove_nth_element(&base,n);		
		break;
	case 5:
		scanf("%s%s",&base,&name);
		delete_with_same_name(&base,&name);		
		break;
	case 6:
		scanf("%s",&base);
		solution_18(&base);		
		break;
	case 7:
		scanf("%s",&base);
		erase_the_base(&base);
		break;
	case 8:
		printf("Bye");
		quit();		
		break;
	}
	//char nam[10]="mike";
	//for(int i=0;i<17;i++)
	//	printf("%s\n",inits[i]);
	//generate_a_base();
	//print_a_base("Generated_base");
	//printf("------------------\n");
	//add_new_elements("Generated_base");
	//remove_nth_element("Generated_base",0);
	//delete_with_same_name("Generated_base",&nam);
	//solution_18("Generated_base");
	//print_a_base("Generated_base");
 	//print_a_base("Generated_base");
	//print_a_base("Generated_base");
	}	
	return 0;
}

