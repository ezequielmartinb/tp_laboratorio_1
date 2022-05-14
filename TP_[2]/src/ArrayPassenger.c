#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "ArrayPassenger.h"

#define VACIO 1
#define CARGADO 0

#define ACTIVO 1
#define DEMORADO 2
#define CANCELADO 3

#define PRIMERA_CLASE 1
#define EJECUTIVA 2
#define ECONOMICA 3


int initPassengers(Passenger* list, int len)
{
	int retorno=-1;

	if(list!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			retorno=0;
			list[i].isEmpty=VACIO;
		}
	}

	return retorno;
}
int incrementarIdPassenger()
{
	static int idPassenger=1000;

	idPassenger++;

	return idPassenger;
}
int buscarEspacioLibre(Passenger list[], int len)
{
	int retorno=-1;
	if (list!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if (list[i].isEmpty==VACIO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flyCode[])
{
	int retorno=-1;
	int indexLibre;

	if(list!=NULL && len>0)
	{
		indexLibre=buscarEspacioLibre(list, len);
		if(indexLibre!=-1)
		{
			list[indexLibre].id=incrementarIdPassenger();
			if(utn_getNombre(list[indexLibre].name, 51, "Ingrese el nombre del pasajero: ", "ERROR. NOMBRE INVALIDO. ", 3)==-1)
			{
				printf("El nombre NO fue cargado con exito\n");
			}
			if(utn_getNombre(list[indexLibre].lastName, 51, "Ingrese el apellido del pasajero: ", "ERROR. APELLIDO INVALIDO. ", 3)==-1)
			{
				printf("El apellido NO fue cargado con exito\n");
			}
			if(utn_getNumeroFlotante(&list[indexLibre].price, "Ingrese el precio del vuelo: ", "ERROR. PRECIO INVALIDO. ", 1, 10000000, 3)==-1)
			{
				printf("El precio NO fue cargado con exito\n");
			}
			if(utn_getNumeroEntero(&list[indexLibre].typePassenger, "Ingrese el tipo de pasajero (1-Primera clase; 2-Ejecutiva; 3-Economica): ", "ERROR. TIPO DE PASAJERO INVALIDO. ", 1, 3, 3)==-1)
			{
				printf("El tipo de pasajero NO fue cargado con exito\n");
			}
			if(utn_getString(list[indexLibre].flyCode, 10, "Ingrese el codigo del vuelo: ", "ERROR. CODIGO ERRONEO. ", 3)==-1)
			{
				printf("El codigo de vuelo NO fue cargado con exito\n");
			}
			if(utn_getNumeroEntero(&list[indexLibre].statusFlight, "Ingrese el estado del vuelo (1-Activo; 2-Demorado; 3-Cancelado): ", "ERROR. ESTADO DE VUELO INVALIDO. ", 1, 3, 3)==-1)
			{
				printf("El estado del vuelo NO fue cargado con exito\n");
			}
			list[indexLibre].isEmpty=CARGADO;
			retorno=0;
		}
	}

	return retorno;
}
int findPassengerById(Passenger* list, int len,int id)
{
	int retorno=-1;
	if (list!=NULL && len>0 && id>0)
	{
		for (int i=0; i<len; i++)
		{
			if (list[i].id==id && list[i].isEmpty==CARGADO)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int modifyPassenger(Passenger* list, int len, int id)
{
	int retorno=-1;
	int index;
	int opcion;
	char deseaSeguirModificando;

	if(list!=NULL && len>0 && id>0)
	{
		printPassenger(list, len);
		index=findPassengerById(list, len, id);
		if(index!=-1)
		{
			while(deseaSeguirModificando!='N')
			{
				if(utn_getNumeroEntero(&opcion, "Que desea modificar?\n \t1-NOMBRE\n\t2-APELLIDO\n\t3-PRECIO\n\t4-TIPO DE PASAJERO\n\t5-CODIGO DE VUELO\n Ingrese una opcion: ", "ERROR. OPCION INVALIDA. ", 1, 5, 3)==0)
				{
					switch(opcion)
					{
						case 1:
							if(utn_getNombre(list[index].name, 51, "Ingrese el NUEVO nombre del pasajero: ", "ERROR. NOMBRE INVALIDO. ", 3)==-1)
							{
								printf("El nombre NO fue cargado con exito\n");
							}
							break;
						case 2:
							if(utn_getNombre(list[index].lastName, 51, "Ingrese el NUEVO apellido del pasajero: ", "ERROR. APELLIDO INVALIDO. ", 3)==-1)
							{
								printf("El apellido NO fue cargado con exito\n");
							}
							break;
						case 3:
							if(utn_getNumeroFlotante(&list[index].price, "Ingrese el NUEVO precio del vuelo: ", "ERROR. PRECIO INVALIDO. ", 1, 10000000, 3)==-1)
							{
								printf("El precio NO fue cargado con exito\n");
							}
							break;
						case 4:
							if(utn_getNumeroEntero(&list[index].typePassenger, "Ingrese el NUEVO tipo de pasajero (1-Primera clase; 2-Ejecutiva; 3-Economica): ", "ERROR. TIPO DE PASAJERO INVALIDO. ", 1, 3, 3)==-1)
							{
								printf("El tipo de pasajero NO fue cargado con exito\n");
							}
							break;
						case 5:
							if(utn_getString(list[index].flyCode, 10, "Ingrese el NUEVO codigo del vuelo: ", "ERROR. CODIGO ERRONEO. ", 3)==-1)
							{
								printf("El codigo de vuelo NO fue cargado con exito\n");
							}
							break;
					}
				}

				if(utn_getUnCaracter(&deseaSeguirModificando, "Desea realizar alguna otra modificacion? Y/N ", "ERROR. INGRESE UNA OPCION VALIDA. ", 'A', 'Z', 3)==-1)
				{
					printf("ERROR.\n");
				}

			}
			retorno=0;
		}
	}

	return retorno;
}
int removePassenger(Passenger* list, int len, int id)
{
	int retorno=-1;
	int index;
	char estaSeguro;
	if (list!=NULL && len>0 && id>0)
	{
		printPassenger(list, len);
		index=findPassengerById(list, len, id);

		if (index!=-1)
		{
			if(utn_getUnCaracter(&estaSeguro, "Está seguro que desea eliminar este pasajero? Y/N ", "ERROR. INGRESE UNA OPCION VALIDA. ", 'A', 'Z', 3)==0 && estaSeguro=='Y')
			{
				list[index].isEmpty=VACIO;
				retorno = 0;
			}
		}
	}
	return retorno;
}
int sortPassengers(Passenger* list, int len, int order)
{
	int retorno=-1;
	int i;
	Passenger auxiliar;
	int estaOrdenado;

	if(list!=NULL && len>0)
	{
		do
		{
			estaOrdenado=1;
			len--;
			if(order==1)
			{
				for(i=0;i<len;i++)
				{
					if(strcmp(list[i].lastName, list[i+1].lastName)>0 && list[i].typePassenger>=list[i+1].typePassenger)
					{
						auxiliar=list[i];
						list[i]=list[i+1];
						list[i+1]=auxiliar;
						estaOrdenado=0;
					}
				}
			}
			else
			{
				for(i=0;i<len;i++)
				{
					if(strcmp(list[i].lastName, list[i+1].lastName)<0 && list[i].typePassenger<=list[i+1].typePassenger)
					{
						auxiliar=list[i];
						list[i]=list[i+1];
						list[i+1]=auxiliar;
						estaOrdenado=0;
					}
				}
			}

		}while(estaOrdenado==0);
		retorno=0;
	}
	return retorno;
}
void mostrarUnPasajeros(Passenger list)
{

}
int printPassenger(Passenger* list, int length)
{
	int retorno=-1;
	char auxiliarTipoPasajero[50];
	char auxiliarEstadoVuelo[50];

	if(list!=NULL && length>0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].isEmpty==CARGADO)
			{
				switch(list[i].typePassenger)
				{
					case PRIMERA_CLASE:
						strcpy(auxiliarTipoPasajero, "PRIMERA CLASE");
						break;
					case EJECUTIVA:
						strcpy(auxiliarTipoPasajero, "EJECUTIVA");
						break;
					case ECONOMICA:
						strcpy(auxiliarTipoPasajero, "ECONOMICA");
						break;
				}
				switch(list[i].statusFlight)
				{
					case ACTIVO:
						strcpy(auxiliarEstadoVuelo, "ACTIVO");
						break;
					case DEMORADO:
						strcpy(auxiliarEstadoVuelo, "DEMORADO");
						break;
					case CANCELADO:
						strcpy(auxiliarEstadoVuelo, "CANCELADO");
						break;
				}
				printf("%4d %-15s %-15s %4.2f %-7s %-15s %-15s\n", list[i].id, list[i].lastName, list[i].name, list[i].price, list[i].flyCode, auxiliarTipoPasajero, auxiliarEstadoVuelo);
			}
		}
		retorno=0;
	}

	return retorno;
}
int printPassengerByStatusFlight(Passenger* list, int length)
{
	int retorno=-1;

	if(list!=NULL && length>0)
	{
		for(int i=0;i<length;i++)
		{
			if(list[i].statusFlight==ACTIVO)
			{
				mostrarUnPasajeros(list[i]);
			}
		}
		retorno=0;
	}

	return retorno;
}
int sortPassengersByCode(Passenger* list, int len, int order)
{
	int retorno=-1;
	int i;
	Passenger auxiliar;
	int estaOrdenado;

	if(list!=NULL && len>0)
	{
		do
		{
			estaOrdenado=1;
			len--;
			if(order==1)
			{
				for(i=0;i<len;i++)
				{
					if(strcmp(list[i].flyCode, list[i+1].flyCode)>0 && list[i].statusFlight==ACTIVO)
					{
						auxiliar=list[i];
						list[i]=list[i+1];
						list[i+1]=auxiliar;
						estaOrdenado=0;
					}
				}
			}
			else
			{
				for(i=0;i<len;i++)
				{
					if(strcmp(list[i].flyCode, list[i+1].flyCode)<0 && list[i].statusFlight==ACTIVO)
					{
						auxiliar=list[i];
						list[i]=list[i+1];
						list[i+1]=auxiliar;
						estaOrdenado=0;
					}
				}
			}

		}while(estaOrdenado==0);
		retorno=0;
	}
	return retorno;
}
float promedioPreciosPasaje(Passenger* list, int len)
{
	float acumuladorPrecios=0;
	float promedioPreciosPasajes;
	int contador=0;

	if(list!=NULL && len>0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==CARGADO)
			{
				acumuladorPrecios=acumuladorPrecios+list[i].price;
				contador++;
			}
		}
		promedioPreciosPasajes=acumuladorPrecios/contador;
	}

	return promedioPreciosPasajes;
}
int contarPasajerosPorPrecio(Passenger* list, int len, float promedio)
{
	int contador=-1;

	if(list!=NULL && len>0)
	{
		contador=0;
		for(int i=0;i<len;i++)
		{
			if(list[i].isEmpty==CARGADO && list[i].price>promedio)
			{
				contador++;
			}
		}
	}

	return contador;
}
int cargaForzada(Passenger* list, Passenger* listaHardcodeada, int lenList, int lenListaHarcodeada)
{
	int retorno=-1;
	if(list!=NULL && listaHardcodeada!=NULL)
	{
		initPassengers(list, lenList);
		for(int i=0;i<lenListaHarcodeada;i++)
		{
			list[i].id=listaHardcodeada[i].id;
			strcpy(list[i].name, listaHardcodeada[i].name);
			strcpy(list[i].lastName, listaHardcodeada[i].lastName);
			list[i].price=listaHardcodeada[i].price;
			strcpy(list[i].flyCode, listaHardcodeada[i].flyCode);
			list[i].statusFlight=listaHardcodeada[i].statusFlight;
			list[i].typePassenger=listaHardcodeada[i].typePassenger;
			list[i].isEmpty=listaHardcodeada[i].isEmpty;
		}
		retorno=0;
	}
	return retorno;
}
