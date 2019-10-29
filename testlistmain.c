#include <stdio.h>
#include <string.h>
#include "char_header.h"
#include <process.h>

int main (){
	FILE *fp;
	char word[101];
	fp=fopen("d:\\data\\flower.txt","rt");
	
	if(fp==NULL){/* open ½ÇÆÐ */
		printf("File open error!/n");
		exit(0);
	}
	while(1){
		if(fscanf(fp,"%s", word)==-1)
			break;
		printf("%s\n", word);
	}
	fclose(fp);
	return 0;
}