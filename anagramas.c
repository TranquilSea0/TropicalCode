#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void sort(char* inputString, char* outputArray){
    int counterArray[256] ={0}, length, counter, index;
    length = strlen(inputString);
    for(counter = 0; counter < length; counter++){
        counterArray[inputString[counter]]++;
    }
    for(counter = 0, index = 0; counter < 256; counter++){
        if(counterArray[counter] != 0){
            while(counterArray[counter] > 0){
                outputArray[index++] = counter;
                counterArray[counter]--;
            }
        }
    }
    outputArray[index] = '\0';
}
void error(char n[]){
	printf("%s",n);
	exit(1);
}
void cambio(char *palabra){
	int i=0;
	while(palabra[i] !="\0"){
		if((97<=palabra[i]) && (palabra[i]<=122)){
			continue;}
		else if((65<=palabra[i]) && (palabra[i]<95)){
			palabra[i]+=32;}
		i++;
	}
}
char **array(FILE *texto,int numero){
    char **array_p,*tropical,copia[201];
    int i;
    array_p=(char **)malloc(sizeof(char*)*numero);
    for(i=0;i<numero;i++){
        array_p[i]=(char *) malloc(sizeof(char)*201);
        fscanf(texto,"%s",array_p[i]);
        cambio(array_p[i]);
	sort(array_p[i],copia);
    }
	tropical=array_p[0];
    for(i=0;i<numero;i++){
        printf("%s\n",array_p[i]);
    }
    return array_p;
}
int anagramas(char **s,int n, char *q){
	int i,contador=0;
	char copia[201];
	cambio(q);
	sort(q,copia);
	for(i=0;i<n;i++){
		if(strcmp(s[i],q)==0)
			contador+=1;
	}
	return contador;
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
			anagrama=anagramas(p,numero,leido);
			fprintf(salida,"%d",anagrama);
		}
	free((void *)p);
	}
	fclose(archivo);
	fclose(salida);
	
	return 0;
}
