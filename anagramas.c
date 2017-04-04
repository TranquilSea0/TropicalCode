#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void error(char n[]){
	printf("%s",n);
	exit(1)
}
void cambio(char *palabra){
	int i=0;
	while(palabra[i] !="\0"){
		if((65<=palabra[i]) && (palabra[i]<95)){
			palabra[i]+=32;
		}
		if else(()){

		}
		i++;
	}
}
char **array(FILE *texto){
    char **array_p,*tropical;
    int numero,i,j;
    fscanf(texto,"%d",&numero);
    array_p=(char **)malloc(sizeof(char*)*numero);
    for(i=0;i<numero;i++){
        array_p[i]=(char *) malloc(sizeof(char)*201);
        fscanf(texto,"%s",array_p[i]);
        cambio(array_p[i]);
    }
    tropical=array_p[0];
    for(i=0;i<numero;i++){
        printf("%s\n",array_p[i]);
    }
    return array_p;
}
int main(){

}
	return 0;
}
