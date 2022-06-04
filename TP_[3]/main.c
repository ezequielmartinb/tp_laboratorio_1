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
    LinkedList* listaPasajeros = ll_newLinkedList();

    setbuf(stdout, NULL);

    while(opcionIngresada!=10)
	{
		printf("\t***MENU DE OPCIONES***\n\n");
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
					printf("ACA VA LA CARGA DE DATOS TEXTO\n");
					controller_loadFromText("data.csv",listaPasajeros);
					break;
				case 2:
					printf("ACA VA LA CARGA DE DATOS BINARIA\n");
					break;
				case 3:
					printf("ACA VA LA ALTA\n");
					break;
				case 4:
					printf("ACA VA LA MODIFICACION\n");
					break;
				case 5:
					printf("ACA VA LA BAJA\n");
					break;
				case 6:
					printf("ACA VA EL LISTAR\n");
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

