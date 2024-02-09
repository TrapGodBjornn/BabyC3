#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

double fahrenomics(double fahren){
        return (fahren - 32)*5/9;
}

double celsius(double celsius){
        return (celsius*9/5)+32;
}

int numbachecka(char bohem[]) {
	int length = strlen(bohem);
	int girth = 0;

	for (int i=0; i < length; i++) {
		if (bohem[i] == '.') {
			girth++;
		if (girth > 1) {
			return 0;
		}
	}
}

	for (int i=1; i<length; i++) {
		if (!isdigit(bohem[i]) && (bohem[i] != '.' || (i>1 && (bohem[i-1] == 'F' || bohem[i-1] == 'C')))) {
			return 0;
}
}
	
	
	for (int i=0;i<length;i++){
		if (bohem[i]=='.' && bohem[i+1]=='-'){
			return 0;
}		

}
		

	for (int i = 1; i< length; i++) {
		if(bohem[i] == '-'){
		return 0;
		}
	}
return 1;
}
		
int main (int argc, char *argv[]) {

        if (argc < 2 || (argv[1][0]!= 'F' && argv[1][0]!= 'C'))
	{
                printf("usage: convert_temp F|C temp (temp ...)\n");
		return 1;
}
	if ((argv[1][0]=='F' || argv[1][0]=='C') && argv[2]=='\0'){
		printf("usage: convert_temp F|C temp (temp ...)\n");
}
	for (int i=2; i< argc; i++) {
		double temp = atof(argv[i]);
		if (numbachecka(argv[i])==0){
			printf("%s is not a valid temperature\n",argv[i]);		
}
                	else {
				if(argv[1][0]== 'F' && argv[2]!='\0')
		{
                        		double celsiuss= fahrenomics(temp);
                        		printf("%gF = %gC\n",temp, celsiuss);
}		
  
				if(argv[1][0]== 'C' && argv[2]!='\0')
		{
                        		double fahrenheit = celsius(temp);
                        		printf("%gC = %gF\n",temp, fahrenheit);
}
			
}
        	
}
	return 0;
}
