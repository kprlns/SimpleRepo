#include <stdio.h>
#include "DT.h"

int main(int args,char* arg[]){
	int print_menu_once=0;
	for (int i=0; i < args; i++) {
			if(cmp(arg[i],"-once")) {
				print_menu_once=1;
			}
	}
	if(print_menu_once) print_menu();
	while (1) {
		if (!print_menu_once) {
			print_menu();
		}
		int n;
		char base_name[25];
		char person_name[10];
		int looser;
		printf("Please chose an Option\n");
		scanf("%d",&n);
		switch (n) {
			case 1:
				printf("Please write a base name:\n");
				scanf("%s",base_name);
				create_a_base(base_name);
				printf("----------------------\n");
				break;
			case 2:
				printf("Please write a base name:\n");
				scanf("%s",base_name);
				add_new_elements(base_name);
				printf("----------------------\n");
				break;
			case 3:
			  printf("Please write a base name:\n");
				scanf("%s",base_name);
				add_random_elements(base_name);
				printf("----------------------\n");
				break;
			case 4:
				printf("Please write a base name:\n");
				scanf("%s",base_name);
				print_a_base(base_name);
				printf("----------------------\n");
				break;
			case 5:
				printf("Please write a base name:\n");
				scanf("%s%d",base_name,&looser);
				remove_nth_element(base_name,looser);
				printf("----------------------\n");
				break;
			case 6:
				printf("Please write a base name:\n");
				scanf("%s%s",base_name,person_name);
				delete_with_same_name(base_name,person_name);
				printf("----------------------\n");
				break;
			case 7:
				printf("Please write a base name:\n");
				scanf("%s",base_name);
				solution_18(base_name);
				printf("----------------------\n");
				break;
			case 8:
				printf("Please write a base name:\n");
				scanf("%s",base_name);
				erase_the_base(base_name);
				printf("----------------------\n");
				break;
			case 9:
				quit();
				break;
			default:
				printf("Wrong input\n");
		}
	}
	/*print_menu();
	printf("|----------------------------------------------|\n");
	printf("|   		     Menu   	               |\n");
	printf("|----------------------------------------------|\n");
	printf("|1.     Create a base			       |\n"); //DONE
	printf("|2.     Add new elements		       |\n"); //DONE
	printf("|3.     Add new random elements		   |\n"); //DONE
	printf("|4.     Print the base		  	       |\n"); //DONE
	printf("|5.	Remove the N-th element		       |\n"); //DONE
	printf("|6.	Remove all element with the same name  |\n");//DONE
	printf("|7.	Option 18                              |\n");//DONE
	printf("|8.	Delete the base                        |\n"); //DONE
	printf("|9.     Quit                                   |\n");//DONE
	printf("|----------------------------------------------|\n");
	//char nam[10]="mike";
	create_a_base("Generated");
	//for(int i=0;i<17;i++)
	//	printf("%s\n",inits[i]);
	//generate_a_base();
	print_a_base("Generated");
	//add_random_elements("Generated");
	solution_18("Generated");
	//printf("------------------\n");
	//add_new_elements("Generated_base");
	//remove_nth_element("Generated_base",0);
	//delete_with_same_name("Generated_base",&nam);
	//solution_18("Generated_base");
	//print_a_base("Generated");
 	//print_a_base("Generated_base");
	//print_a_base("Generated_base");*/
	return 0;
}
