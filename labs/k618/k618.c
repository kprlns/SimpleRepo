#include <stdio.h>
#include "DT.h"

int main(int args,char* arg[]){
	print_menu();
	char c[20];
	for(int i=0;i<20;i++){
	printf("%s\n",names[i]);
	}
	generate_a_base();
	read_a_person("Generated_base");
	return 0;
}

