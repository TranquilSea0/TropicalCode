#include <stdio.h>
#include <stdlib.h>

typedef struct{
	int nroCuenta;
	int saldo;
	char nbre[51];
	char direccion[51];}  clienteBanco;

/*int busqueda(clienteBanco *arreglo, int cuenta, int sup){
	int inf, mit,casilla;
	inf = 0;
	while(inf<=sup){
		mit = ((sup-inf)/2)+inf;
		if(arreglo[mit].nroCuenta == cuenta){
			casilla=mit;
			break;
		}
		
		else if(arreglo[mit].nroCuenta < cuenta){
					inf = mit;
					mit = (inf + sup)/2;


		}
		else if(arreglo[mit].nroCuenta > cuenta){
					sup = mit;
					mit = (sup + inf)/2;
		}
		if(inf==sup){casilla=-1;
			break;

		}
	printf("hola\n");				
	}
	printf("hola\n");
	return casilla;}*/

void actualizarSaldos(char *clientes, char *transacciones){
	FILE *cliente,*final,*trans;;
	int i, linea,c=0;//casilla;
	int monto, cuenta1, cuenta2_monto;
	char signo;
	clienteBanco *array,**farray;
	cliente = fopen(clientes,"r");
	farray=(clienteBanco **)malloc(sizeof(clienteBanco*)*10000000);
	//array = (clienteBanco *)malloc(sizeof(clienteBanco)*10000000);
	i=0;
	array=(clienteBanco *)malloc(sizeof(clienteBanco));
	c=fread(&array,sizeof(clienteBanco),1,cliente);
	while(c!=0){
		i++;
		array=(clienteBanco *)malloc(sizeof(clienteBanco));
		c=fread(&array,sizeof(clienteBanco),1,cliente);
	}
	/*for(i=0;i<10000000;i++){
		c+=fread(&aux,sizeof(clienteBanco),1,cliente);
	}*/
	printf("%d\n",i );
	fclose(cliente);
	trans=fopen(transacciones,"r");
	while((linea=fscanf(trans, "%c %d %d %d\n", &signo,&cuenta1,&cuenta2_monto, &monto))!=EOF){
		//linea = fscanf(trans, "%c %d %d %d", &signo,&cuenta1,&cuenta2_monto, &monto);
		//printf("%d\n", linea);
		if(linea ==3){
			//printf("%c\n",signo );
			if(signo =='+'){
				//casilla= busqueda(array,cuenta1,c-1);
				//printf("%d\n",array[casilla].saldo );
				//if(casilla==-1){continue;}
				farray[cuenta1-1].saldo += cuenta2_monto;
				//printf("el monto %d\n",cuenta2_monto );
			}
			else if(signo == '-'){
				//casilla = busqueda(array, cuenta1, c-1);
				//if(casilla==-1){continue;}
				farray[cuenta1-1].saldo -= cuenta2_monto;
			}
		}
			
		else if(linea == 4){
			/*casilla= busqueda(array, cuenta1, c-1);
			if(casilla==-1){continue;}*/
			farray[cuenta1-1].saldo -= monto;
			/*casilla= busqueda(array, cuenta2_monto, c-1);
			if(casilla==-1){continue;}*/
			farray[cuenta2_monto-1].saldo += monto;
		}
	}
	final=fopen("wea.dat","w");
	fwrite(array,sizeof(clienteBanco),10000000,final);
	fclose(final);
	free((void *)array);}

int main(int argc, char *argv[]){
	actualizarSaldos(argv[1],argv[2]);
	return 0;}
	
	










