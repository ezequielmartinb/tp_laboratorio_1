#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Passenger.h"
#include "inputs.h"

/****************************************************
    Menu:
     1. Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).
     2. Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).
     3. Alta de pasajero
     4. Modificar datos de pasajero
     5. Baja de pasajero
     6. Listar pasajeros
     7. Ordenar pasajeros
     8. Guardar los datos de los pasajeros en el archivo data.csv (modo texto).
     9. Guardar los datos de los pasajeros en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/



int main()
{
    int opcionIngresada;
    LinkedList* listaPasajeros=ll_newLinkedList();
    setbuf(stdout, NULL);

    while(opcionIngresada!=10)
	{
		printf("\t**********************MENU DE OPCIONES**********************\n\n");
		printf("1- Cargar los datos de los pasajeros desde el archivo data.csv (modo texto).\n"
			   "2- Cargar los datos de los pasajeros desde el archivo data.csv (modo binario).\n"
			   "3- Alta de pasajero\n"
			   "4- Modificar datos de pasajero\n"
			   "5- Baja de pasajero\n"
			   "6- Listar pasajero\n"
			   "7- Ordenar pasajero\n"
			   "8- Guardar los datos de los pasajeros en el archivo data.csv (modo texto)\n"
			   "9- Guardar los datos de los pasajeros en el archivo data.csv (modo binario)\n"
			   "10- SALIR \n\n");
		if(utn_getNumeroEntero(&opcionIngresada, "Ingrese una opcion: ", "ERROR. OPCION INVALIDA. ", 1, 10, 3)==0)
		{
			switch(opcionIngresada)
			{
				case 1:
					if(controller_loadFromText("data.csv",listaPasajeros)!=-1)
					{
						printf("\n\n\n**********************LA CARGA DE DATOS SE REALIZO CON EXITO**********************\n\n\n");
					}

					break;
				case 2:
					printf("ACA VA LA CARGA DE DATOS BINARIA\n");
					break;
				case 3:
					if(controller_addPassenger(listaPasajeros)==0)
					{
						printf("\n\n\n**********************ALTA EXITOSA**********************\n\n\n");
					}
					else
					{
						printf("\n\n\n**********************ALTA DENEGADA**********************\n\n\n");
					}
					break;
				case 4:
					printf("ACA VA LA MODIFICACION\n");
					break;
				case 5:
					if(controller_removePassenger(listaPasajeros)!=-1)
					{
						printf("\n\n\n**********************BAJA EXITOSA**********************\n\n\n");
					}
					else
					{
						printf("\n\n\n**********************BAJA DENEGADA**********************\n\n\n");
					}
					break;
				case 6:
					if(controller_ListPassenger(listaPasajeros)!=0)
					{
						printf("\n\n\n**********************LA LISTA NO SE MOSTRO CON EXITO**********************\n\n\n");
					}
					break;
				case 7:
					printf("ACA VA EL ORDENAR\n");
					break;
				case 8:
					printf("ACA VA GUARDAR LOS DATOS EN MODO TEXTO\n");
					break;
				case 9:
					printf("ACA VA GUARDAR LOS DATOS EN MODO BINARIO\n");
					break;
				case 10:
					printf("SALIR\n");
					break;


			}
		}

	}

    return 0;
}

