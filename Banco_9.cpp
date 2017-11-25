#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*Comentario
Programa para un banco.
Fecha:14 Noviembre 2017
Elaborado por: Leyder Londoño Mejia*/

struct Banco{
	char nombre_banco[20];
	char direccion[15];
	int telefono;
	char ciudad[15];
	int nit;	
};

struct fecha{
	int dia,mes,anio;
};

struct cliente{
	fecha nacimiento;
	char nombre_cliente[30];
	int clave;
	char tramite[30];
	char estado[30];
};

cliente v[100];
Banco p[10];
int tam,longt=1;

void Menu();
void datos_clientes(cliente v[]);
void editar_clientes(cliente v[]);
void lista_atendidos();
void lista_no_atendidos(int tam);
void atender_cliente();
void cliente_asesoria(int tam);
void cliente_consignar(int tam);
void datos_banco(Banco p[],int longt);
void editar_banco(Banco p[],int longt);
void Mostrar_banco(int longt);

int QuitarEspacio=0;
int main(){	
	if(QuitarEspacio==0){
		datos_banco(p,longt);
		a++;
	}	  
	Menu();	 
	return 0;
}

void Menu(){
	int opcion;
	do{
		Mostrar_banco(longt);
	
		printf("----- Bienvenidos al Banco ----- \n\n");
		printf("1 Insertar Clientes \n");
		printf("2 Editar Clientes \n");
		printf("3 Atender Clientes \n");
		printf("4 Lista de clientes Atendidos \n");
		printf("5 Lista de clientes NO Atendidos \n");
		printf("6 Lista de clientes para Consignaciones \n");
		printf("7 Lista de clientes para Asesoria Comercial \n");
		printf("8 Editar Datos del Banco \n");
		printf("9 Mostrar Datos del Banco \n");
		printf("0 Salir \n");
		printf(" Ingrese una Opcion \n");
		scanf("%d",&opcion);
		switch(opcion){
		case 0:
			exit(0);
		case 1:
			datos_clientes(v);
			break;
		case 2:
			editar_clientes(v);
			break;
		case 3:
			atender_cliente();
			break;
		case 4:
			lista_atendidos();
			break;
		case 5:
			lista_no_atendidos(tam);
			break;
		case 6:
			cliente_consignar(tam);
			break;
		case 7:
			cliente_asesoria(tam);
			break;
		case 8:
			editar_banco(p,longt);
			break;
		case 9:
			datos_banco(p,longt);
			break;
		default:
			printf("Opcion Invalida\n");
		}		
	}while(opcion!=0);
}

void datos_banco(Banco p[],int lon){
	for(int i=0;i<lon;i++){
		strcpy(p[i].nombre_banco," Banco del Estado ");
		strcpy(p[i].ciudad," Bogota D.C ");
		strcpy(p[i].direccion," Carrera 2 # 28-58 Centro ");
		p[i].telefono=2345670;
		p[i].nit=7654321;
	}	
}

void Mostrar_banco(int longt){
	for(int i=0;i<longt;i++){
		printf("%s\n%s\n%s\nTel:%d \n Nit:%d \n\n",p[i].nombre_banco,p[i].ciudad,p[i].direccion,p[i].telefono,p[i].nit);		
	}
	printf(" \n ");
}

void editar_banco(Banco p[],int longt){
	char nuevo_banco[30],nuevo_ciudad[30],nuevo_direccion[30];
	int nuevo_telefono,nuevo_nit;
	char *pch;
	printf(" Ingrese Nuevos datos del Banco \n");
	for(int i=0;i<1;i++){
		printf("Nombre \n ");
		fflush(stdin);
		fgets(nuevo_banco,30,stdin);
		strcpy(p[i].nombre_banco,nuevo_banco);
		pch = strchr(p[i].nombre_banco, 10);
		if (pch != NULL){
			*pch = '\0';
		}
		printf("Ciudad \n");
		fflush(stdin);
		fgets(nuevo_ciudad,30,stdin);
		strcpy(p[i].ciudad,nuevo_ciudad);
		pch = strchr(p[i].ciudad, 10);
		if (pch != NULL){
			*pch = '\0';
		}
		printf("Direccion:");
		fflush(stdin);
		fgets(nuevo_direccion,30,stdin);
		strcpy(p[i].direccion,nuevo_direccion);
		pch = strchr(p[i].direccion, 10);
		if (pch != NULL){
			*pch = '\0';
		}
		printf("Telefono \n");
		scanf("%d",&nuevo_telefono);
		p[i].telefono=nuevo_telefono;
		printf("NIT \n");
		scanf("%d",&nuevo_nit);
		p[i].nit=nuevo_nit;
		printf(" \n\n ");
	}
	printf(" \n ");
}

void datos_clientes(cliente v[]){
	printf("Ingrese Cantidad de Clientes \n");
	scanf("%d",&tam);
	if (tam<=100){
		for(int i=0;i<tam;i++){
			printf(" \n %i.Nombre ");
			fflush (stdin);
			fgets(v[i].nombre_cliente,30,stdin);
			
			printf("\nFecha de Nacimiento \n");
			printf("Dia ");
			scanf("%d",&v[i].nacimiento.dia);
			printf("Mes ");
			scanf("%d",&v[i].nacimiento.mes);
			printf("Año ");
			scanf("%d",&v[i].nacimiento.anio);			
			printf("Clave ");
			scanf("%d",&v[i].clave);
			printf(" \n ");
		}
	}else{
		printf("ERROR Limite del Banco es de 100 Personas \n");
	}
	printf(" \n ");
}
void editar_clientes(cliente v[]){
	char buscar_nombre[30];
	int dato,nueva_clave;
	int pos=0;
	int nuevo_dia,nuevo_mes,nuevo_anio;
	
	printf(" Ingrese Nombre del Cliente \n");
	fflush(stdin);
	fgets(buscar_nombre,30,stdin);
	for(int i=0;i<tam;i++){
		if(strcmp(buscar_nombre,v[i].nombre_cliente)==0){
			pos=i;
			printf("Que desea editar \n");
			printf("1 Nombre \n");
			printf("2 Clave \n");
			printf("3 Fecha de Nacimiento \n");
			scanf("%d",&dato);
			
			switch(dato){
			case 1:
				char nuevo_nombre[30];
				printf("Ingrese Nuevo Nombre \n");
				fflush(stdin);
				fgets(nuevo_nombre,30,stdin);
				strcpy(v[pos].nombre_cliente,nuevo_nombre);
				break;
			case 2:
				printf("Ingrese nueva Clave \n");
				scanf("%d",&nueva_clave);
				v[pos].clave=nueva_clave;
				break;

			case 3:
				printf("Ingrese Nueva Fecha de Nacimiento \n");
				printf("\n Dia ");
				scanf("%d",&nuevo_dia);
				v[pos].nacimiento.dia=nuevo_dia;				
				printf("\n Mes ");
				scanf("%d",&nuevo_mes);
				v[pos].nacimiento.mes=nuevo_mes;
				printf("\n Año ");
				scanf("%d",&nuevo_anio);
				v[pos].nacimiento.anio=nuevo_anio;
				break;
			}
			
		}
	}
	printf(" \n ");
}
void lista_atendidos(){
	int contador=0;
	char c[30]=" Cliente Atendido ";
	int comparacion;
	printf("\n<<<<<-------- Listado de Clientes Atendidos -------->>>>>\n\n");
	for(int i=0;i<tam;i++){
		comparacion=strcmp(v[i].estado,c);
		if(comparacion==0){
			contador=i;
			printf("Nombre:%s\n",v[contador].nombre_cliente);
		}		
	}
	printf(" \n ");
}
void lista_no_atendidos(int tam){
	int contador=0;
	int comparacion;
	char n[30]=" Cliente No Atendido ";
	
	printf("\n<<<<<<-------- Listado de Clientes NO Atendidos -------->>>>>>>>\n\n");
	for(int i=0;i<tam;i++){
		comparacion=strcmp(v[i].estado,n);
		if(comparacion==0){
			contador=i;
			printf("%i.Nombre:%s",i+1,v[contador].nombre_cliente);
		}		
	}
	printf(" \n ");
}
void atender_cliente(){
	char nombre[30];
	int tramite,opcion_tramite,comparacion,resultado1,resultado2,i,resultado3;
	char c[30]=" Consignacion ";
	char a[30]=" Asesoria Comercial ";
	char n[30]=" Ninguno ";
	
	printf("Ingrese Nombre del Cliente \n");
	fflush(stdin);
	fgets(nombre,30,stdin);
	for(i=0;i<tam;i++){
		comparacion=strcmp(nombre,v[i].nombre_cliente);		
		tramite=i;
		if (comparacion==0){
			printf("\nIngrese Tramite a Realizar:\n 1.Consignacion\n 2.Asesoria Comercial\n 3.Ninguna de las Anteriores \n");
			scanf("%d",&opcion_tramite);
			switch(opcion_tramite){
			case 1:
				strcpy(v[tramite].tramite, " Consignacion ");
				break;
			case 2:
				strcpy(v[tramite].tramite, " Asesoria Comercial ");
				break;
			case 3:
				strcpy(v[tramite].tramite, " Ninguno ");
				break;
			}			
		}
		resultado1=strcmp(v[tramite].tramite,c);
		resultado2=strcmp(v[tramite].tramite,a);
		resultado3=strcmp(v[tramite].tramite,n);
		
		if(resultado1==0 or resultado2==0){
			strcpy(v[tramite].estado, " Cliente Atendido \n");
		}else if(resultado3==0){
			strcpy(v[tramite].estado, " Cliente NO Atendido \n");
		}
	}
}
void cliente_consignar(int tam){
	int contador=0;
	char c[30]="Consignacion";
	int comparacion;
	printf("Clientes que consignan \n");
	for(int i=0;i<tam;i++){
		comparacion=strcmp(v[i].tramite,c);
		if(comparacion==0){
			contador=i;
			printf("%i.Nombre %s",i+1,v[contador].nombre_cliente);
		}		
	}
	printf(" \n ");	
}
void cliente_asesoria(int tam){
	int contador=0;
	int comparacion;
	char a[30]="Asesoria Comercial";
	printf("Clientes para Asesoria Comercial\n");
	for(int i=0;i<tam;i++){
		comparacion=strcmp(v[i].tramite,a);
		if(comparacion==0){
			contador=i;
			printf("%i.Nombre: %s",i+1,v[contador].nombre_cliente);
		}		
	}
	printf(" \n ");	
}

