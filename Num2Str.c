#include <stdio.h>
#include <stdlib.h>

void Num2Str(int num, char* str, int s){
	int count = s;
	if(num<0){
		str[0] = '-';
		num *= -1;
		count--;
	}
	for(int i=1; i<=count; i++){
		str[s-i] = num%10+48;
		num = num/10;
	}

	str[s] = '\0';
}

void PrintNum(int num){
	int s = 1;
	int temp = num;
	if(num<0){
		temp *= -1;
		s++;
	}
	while(1){
		temp /= 10;
		if(temp<=0) break;
		s++;
	}
	char *buffer = (char*)malloc(sizeof(char)*(s+1));

	Num2Str(num, buffer, s);

	// print by USART
	printf("%s!\n", buffer);

	free(buffer);
}

int main(){
	int num;
	printf("Num To String: ");
	scanf("%d", &num);
	
	PrintNum(num);
	
	return 0;
}
