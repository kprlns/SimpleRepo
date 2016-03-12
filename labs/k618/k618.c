#include <stdio.h>
#include "DT.h"

int main(int args,char* arg[]){
	print_menu();
	//for(int i=0;i<17;i++)
	//	printf("%s\n",inits[i]);
	generate_a_base();
	write_a_base("Generated_base");
	return 0;
}

