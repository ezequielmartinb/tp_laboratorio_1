#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "inputs.h"
#include "ArrayPassenger.h"

#define TAM_PASAJEROS 2000
#define TAM_PASAJEROS_HARCODEADOS 5
#define ACTIVO 1
#define DEMORADO 2
#define CANCELADO 3
#define ECONOMICA 1
#define EJECUTIVA 2
#define PRIMERA_CLASE 3
#define VACIO 1
#define CARGADO 0

int main(void)
{
	Passenger listaPasajeros[TAM_PASAJEROS];
	Passenger auxiliarListaPasajeros[TAM_PASAJEROS]= { {1001, "Juan Carlos", "Zeballos", 600.50, "EZE3600Z", PRIMERA_CLASE, ACTIVO, CARGADO},
													   {1002, "Anastacio", "Kirchner", 30000, "AAA7777A", ECONOMICA, DEMORADO, CARGADO},
													   {1003, "Juan Carlos", "Zeballos", 600.50, "AAA2222B", EJECUTIVA, ACTIVO, CARGADO},
													   {1004, "Ricardo", "Sanchez", 115000.50, "BBB7520C", PRIMERA_CLASE, ACTIVO, CARGADO},
													   {1005, "Ezequiel", "Barrios", 35000, "TTT5555B", ECONOMICA, CANCELADO, CARGADO}};
	int opcionIngresada;
	int opcionIngresadaInformes;
	int idIngresado;
	int orden;
	int banderaCargaExitosa=0;
	float promedio;
	int cantidadDePasajerosSuperanPrecioPromedio;
	char confirmarCargaForzada;
	int ultimoID;
	setbuf(stdout, NULL);

	initPassengers(listaPasajeros, TAM_PASAJEROS);

	while(opcionIngresada!=6)
	{
		printf("===========================================================================\n"
			   "		   	BIENVENIDO A LA APP VUELOS UTN								 \n"
			   "===========================================================================\n");
		printf("1) Alta de pasajeros\n"
			   "2) Modificar pasajeros\n"
			   "3) Baja de pasajeros\n"
			   "4) Informar:\n"
			   "\t1. Listado de pasajeros ordenados alfabeticamente por apellido y tipo de pasajero\n"
			   "\t2. Total y promedio de los precios de los pasajeros y cuantos pasajeros superan el precio promedio\n"
			   "\t3. Listado de pasajeros por codigo de vuelo y estados de vuelo 'Activos'\n"
			   "5) Carga forzada de datos\n"
			   "6) Salir\n\n\n");
		if(utn_getNumeroEntero(&opcionIngresada, "Ingrese una opcion valida: ", "ERROR. OPCION INVALIDA. ", 1, 6, 3)==0)
		{
			switch(opcionIngresada)
			{
				case 1:
					if(addPassenger(listaPasajeros, TAM_PASAJEROS, listaPasajeros->id, listaPasajeros->name, listaPasajeros->lastName, listaPasajeros->price, listaPasajeros->typePassenger, listaPasajeros->flyCode)==0)
					{
						printf("El pasajero fue cargado con exito\n");
						banderaCargaExitosa=1;
					}
					else
					{
						printf("\n\n\n***********************ERROR AL CARGAR PASAJEROS***********************\n\n\n");
					}
					break;
				case 2:
					if(banderaCargaExitosa==0)
					{
						printf("\n\n\n***********************ANTES DE MODIFICAR, PRIMERO HAY QUE CARGAR PASAJEROS***********************\n\n\n");
					}
					else
					{
						printPassenger(listaPasajeros, TAM_PASAJEROS);
						ultimoID=ultimoId(listaPasajeros, TAM_PASAJEROS);
						if(utn_getNumeroEntero(&idIngresado, "Ingrese el ID que desea modificar: ", "ERROR. ID ERRONEO", 1001, ultimoID, 3)==-1)
						{
							printf("\tMODIFICACION DENEGADA\n");
						}
						if(modifyPassenger(listaPasajeros, TAM_PASAJEROS, idIngresado)==0)
						{
							printf("\tLa MODIFICACION fue realizada con EXITO\n\n");
						}
					}

					break;
				case 3:
					if(banderaCargaExitosa==0)
					{
						printf("\n\n\n***********************ANTES DE DAR DE BAJA, PRIMERO HAY QUE CARGAR PASAJEROS***********************\n\n\n");
					}
					else
					{
						printPassenger(listaPasajeros, TAM_PASAJEROS);
						ultimoID=ultimoId(listaPasajeros, TAM_PASAJEROS);
						if(utn_getNumeroEntero(&idIngresado, "Ingrese el ID que desea dar de baja: ", "ERROR. ID ERRONEO. ", 1001, ultimoID, 3)==-1)
						{
							printf("\tBAJA DENEGADA\n");
						}
						if(removePassenger(listaPasajeros, TAM_PASAJEROS, idIngresado)==0)
						{
							printf("\tLa BAJA fue realizada con EXITO\n\n");
						}
					}

					break;
				case 4:
					if(banderaCargaExitosa==0)
					{
						printf("\n\n\n***********************ANTES DE INFORMAR, PRIMERO HAY QUE CARGAR PASAJEROS***********************\n\n\n");
					}
					else
					{
						if(printPassenger(listaPasajeros, TAM_PASAJEROS)==-1)
						{
							printf("\tNO HAY PASAJEROS CARGADOS\n\n");
						}
						printf("4) Informar:\n"
							   "\t1- Listado de pasajeros ordenados alfabeticamente por Apellido y Tipo de Pasajero\n"
							   "\t2- Total y promedio de los precios de los pasajes y cuantos pasajeros superan el precio promedio\n"
							   "\t3- Listado de pasajeros por Codigo de Vuelo y Estado de Vuelo 'ACTIVO'\n"
							   "\t4- VOLVER AL MENU ANTERIOR\n");
						if(utn_getNumeroEntero(&opcionIngresadaInformes, "Ingrese una opcion valida: ", "ERROR. OPCION INVALIDA. ", 1, 4, 3)==0)
						{
							switch(opcionIngresadaInformes)
							{
								case 1:
									printf("\t\tIngrese la opción 1 si quiere ordenar de manera ascendente o 0 si quiere ordenar de formar descendente: \n");
									if(utn_getNumeroEntero(&orden, "Ingrese una opcion valida: ", "ERROR. OPCION INVALIDA. ", 0, 1, 3)==0)
									{
										if(sortPassengers(listaPasajeros, TAM_PASAJEROS, orden)==0 && printPassenger(listaPasajeros, TAM_PASAJEROS)==0)
										{
											printf("\n\n\n***EL ORDENAMIENTO FUE EXITOSO***\n\n\n");
										}
									}
									break;
								case 2:
									promedio=promedioPreciosPasaje(listaPasajeros, TAM_PASAJEROS);
									printf("El promedio es: %.2f. ", promedio);
									cantidadDePasajerosSuperanPrecioPromedio=contarPasajerosPorPrecio(listaPasajeros, TAM_PASAJEROS, promedio);
									if(cantidadDePasajerosSuperanPrecioPromedio!=-1)
									{
										printf("y la cantidad de pasajeros que superan el precio promedio es de %d\n", cantidadDePasajerosSuperanPrecioPromedio);
									}
									break;
								case 3:
									printf("\t\tIngrese la opción 1 si quiere ordenar de manera ascendente o 0 si quiere ordenar de formar descendente: \n");
									if(utn_getNumeroEntero(&orden, "Ingrese una opcion valida: ", "ERROR. OPCION INVALIDA. ", 0, 1, 3)==0)
									{
										if(sortPassengersByCode(listaPasajeros, TAM_PASAJEROS, orden)==0 && printPassenger(listaPasajeros, TAM_PASAJEROS)==0)
										{
											printf("\n\n\n***EL ORDENAMIENTO FUE EXITOSO***\n\n\n");
										}
									}
									printPassengerByStatusFlight(listaPasajeros, TAM_PASAJEROS);
									break;
								case 4:
									printf("VOLVIENDO AL MENU ANTERIOR\n\n");
									break;
							}
						}
					}
					break;
				case 5:
					if(banderaCargaExitosa==1)
					{
						utn_getUnCaracter(&confirmarCargaForzada, "Hay datos cargados en la lista. Está seguro que desea sobreescribirla? Y/N", "ERROR. ", 'A', 'Z', 3);
					}
					if(cargaForzada(listaPasajeros, auxiliarListaPasajeros, TAM_PASAJEROS, TAM_PASAJEROS_HARCODEADOS)==0)
					{
						banderaCargaExitosa=1;
						printf("LA CARGA FORZADA SE REALIZO CON EXITO\n");
					}
					break;
				case 6:
					printf("\n\t\t***********************GRACIAS POR UTILIZAR LA APP VUELOS UTN***********************\n");
					break;
			}
		}
	}



	return EXIT_SUCCESS;
}
