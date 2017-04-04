#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char* A, char* B){
    int counterArray[256] ={0}, length, counter, index;
    length = strlen(A);
    for(counter = 0; counter < length; counter++){
        counterArray[inputString[counter]]++;
    }
    for(counter = 0, index = 0; counter < 256; counter++){
        if(counterArray[counter] != 0){
            while(counterArray[counter] > 0){
                B[index++] = counter;
                counterArray[counter]--;
            }
        }
    }
    B[index] = '\0';
}
void error(char n[]){
	printf("%s",n);
	exit(1)
}
void cambio(char *palabra){
	int i=0;
	while(palabra[i] !="\0"){
		if((97<=palabra[i]) && (palabra[i]<=122))
			continue;
		if else((65<=palabra[i]) && (palabra[i]<95))
			palabra[i]+=32;
		if else((palabra[i]==160) || (palabra[i]==181))
			palabra[i]="a";
		i++;
	}
}
char **array(FILE *texto,numero){
    char **array_p,*tropical,copia[201];
    int i,j;
    array_p=(char **)malloc(sizeof(char*)*numero);
    for(i=0;i<numero;i++){
        array_p[i]=(char *) malloc(sizeof(char)*201);
        fscanf(texto,"%s",array_p[i]);
        cambio(array_p[i]);
	sort(array_p[i],copia)
    }
    tropical=array_p[0];
    for(i=0;i<numero;i++){
        printf("%s\n",array_p[i]);
    }
    return array_p;
}
int main(){
	FILE*archivo;
	archivo=fopen("strings.txt","r");
	FILE*salida;
	salida=fopen("salida.txt","w");
	int numero,anagrama,i=0;
	char *p;
	char leido[201];
	while(fscanf(archivo,"%d",numero)==1){
		p=array(archivo,numero);
		fscanf(archivo,"%d",anagrama);
		for(i=0;i<anagrama;i++){
			fscanf(archivo,"%s",leido);
			anaframas=anagramas(p,numero,leido);
			fprintf(salida,"%d",anagrama);
		}
	free((void *)p);
	}
	fclose(archivo);
	fclose(salida);
	
	return 0;
}
