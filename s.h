#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void DelayWelcome(){
	char msg[14]="Enter Records";  //20
	int i,count=0,j;
	for(i=0;i<120;i++){
		for(j=0;j<10000000;j++){
		}
		if(i>50&&count<14)printf("%c",msg[count++]);
		else printf("*");
	}
}
