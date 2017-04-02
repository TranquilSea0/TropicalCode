#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void error(char mensaje[]){
		printf("Ocurrio un error al %s\n",mensaje); """ esta wea es pa probar algo (:"""
int anagramas(char **S,int n,char *str){
}
int main(){
	FILE*archivo;
	archivo=fopen("strings.txt","r");
	int palabras,anagrama,i;
	while(fscanf(archivo,"%d",palabras)!="EOF");{
		char *ldpalabras[palabras];
		s=char malloc(palabras*201*sizeof(char *));
		for(i=0;i<palabras;i++);{
			char leido[201];fscanf("%s",leido);
			s[i]=leido;
			ldpalabras[i]=&s[i];
		}
		fscanf(archivo,"%d",&anagrama);
		FILE*salida;
		salida=fopen("salida-1.txt","a");
		for(i=0;i<anagrama;i++){
			fscanf(archivo,"%s",leido);
			fprintf(salida,"%d\n",anagramas(ldpalabras,palabras,leido));
		}
		fclose(salida);
		free(s);
	}
	fclose(archivo);
	return 0;
}
