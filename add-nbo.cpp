#include <stdio.h>
#include <stdint.h>
#include <netinet/in.h>
#include <iostream>

#define MAX 4

uint32_t readFile(char* file){
	int state;
	uint32_t a;

	FILE* fp = fopen(file, "rb");
	if(fp == NULL){
		printf("fopen error\n");
		exit(1);
	}

	int len = fread(&a, 1, MAX, fp);
	a = ntohl(a);
	
	state = fclose(fp);
	if (state != 0){
		printf("fclose error\n");
		exit(1);
	}

	return a;

}
int main(int argc, char** argv){
	if (argc == 3){
		
		uint32_t value1 = readFile(argv[1]);
		uint32_t value2 = readFile(argv[2]);
		uint32_t sum = value1 + value2;
		printf("%d(0x%x) + %d(0x%x) = %d(0x%x)\n", value1, value1, value2, value2, sum, sum);
		

	}
	else {
		printf("argc error\n");
		return 1;
	}

	return 0;

}
