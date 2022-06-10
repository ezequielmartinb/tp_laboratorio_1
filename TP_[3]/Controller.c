#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LinkedList.h"
#include "Passenger.h"
#include "parser.h"
#include "inputs.h"


/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_loadFromText(char* path, LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	FILE* pArchivo=NULL;

	if(path!=NULL && pArrayListPassenger!=NULL)
	{
		retorno=parser_PassengerFromText(pArchivo, pArrayListPassenger, path);
	}
	return retorno;
}

/** \brief Carga los datos de los pasajeros desde el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_loadFromBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}
static int createId(void)
{
    static int createId = 1000;

    createId++;

    return createId;

}

/** \brief Alta de pasajero
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 *
 * \return int
 */
int controller_addPassenger(LinkedList* pArrayListPassenger)
{
	int retorno=-1;
	Passenger* nuevoPasajero;
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoDeVuelo[50];
	int tipoPasajero;
	int estadoVuelo;
	char auxiliarTipoPasajero[50];
	char auxiliarEstadoVuelo[50];

	if(pArrayListPassenger!=NULL)
	{
		nuevoPasajero=Passenger_new();
		id=createId();// PROVISORIO!!!
		if(utn_getNombre(nombre, 50, "Ingrese el nombre del pasajero: ", "ERROR. NOMBRE INVALIDO. ", 3)==0 &&
		   utn_getNombre(apellido, 50, "Ingrese el apellido del pasajero: ", "ERROR. APELLIDO INVALIDO. ", 3)==0 &&
		   utn_getNumeroFlotante(&precio, "Ingrese el precio: ", "ERROR. PRECIO INVALIDO. ", 1, 3000000, 3)==0 &&
		   utn_getString(codigoDeVuelo, 50, "Ingrese el codigo de vuelo: ", "ERROR. CODIGO DE VUELO INVALIDO. ", 3)==0 &&
		   utn_getNumeroEntero(&tipoPasajero, "Ingrese el tipo de pasajero: \n\t1-FirstClass\n\t2-Executive\n\t3-EconomyClass\n", "ERROR. TIPO DE PASAJERO INVALIDO. ", 1, 3, 3)==0 &&
		   utn_getNumeroEntero(&estadoVuelo, "Ingrese el estado del vuelo: \n\t1-Aterrizado\n\t2-En Horario\n\t3-Demorado\n", "ERROR. ESTADO DE VUELO INVALIDO. ", 1, 3, 3)==0)
		{
			if(nuevoPasajero!=NULL)
			{
				switch(tipoPasajero)
				{
					case 1:
						strcpy(auxiliarTipoPasajero, "FirstClass");
						break;
					case 2:
						strcpy(auxiliarTipoPasajero, "Executive");
						break;
					case 3:
						strcpy(auxiliarTipoPasajero, "EconomyClass");
						break;
				}
				switch(estadoVuelo)
				{
					case 1:
						strcpy(auxiliarEstadoVuelo, "Aterrizado");
						break;
					case 2:
						strcpy(auxiliarEstadoVuelo, "En Horario");
						break;
					case 3:
						strcpy(auxiliarEstadoVuelo, "Demorado");
						break;
				}
				nuevoPasajero=Passenger_newParametrosCorrectos(id, nombre, apellido, precio, codigoDeVuelo, auxiliarTipoPasajero, auxiliarEstadoVuelo);
				Passenger_showOnePassenger(nuevoPasajero);
				ll_add(pArrayListPassenger, nuevoPasajero);
				retorno=0;
			}
		}

	}

    return retorno;
}

/** \brief Modificar datos de pasajero
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_editPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}
/** \brief Listar pasajeros
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_ListPassenger(LinkedList* pArrayListPassenger)
{
	Passenger* pasajerosAuxiliar=NULL;
	int retorno=-1;
	int tam;
	tam=ll_len(pArrayListPassenger);

	if(pArrayListPassenger!=NULL)
	{
		for(int i=0;i<tam;i++)
		{
			pasajerosAuxiliar=ll_get(pArrayListPassenger, i);
			Passenger_showOnePassenger(pasajerosAuxiliar);
			retorno=0;
		}
	}
	return retorno;
}

/** \brief Baja de pasajero
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_removePassenger(LinkedList* pArrayListPassenger)
{
	int index=-1;
	int idIngresado;
	int len;
	char opcion;
	Passenger* auxiliarPasajeros;
	auxiliarPasajeros=Passenger_new();

	if(pArrayListPassenger!=NULL && auxiliarPasajeros!=NULL && controller_ListPassenger(pArrayListPassenger)==0)
	{
		len=ll_len(pArrayListPassenger);
		// BUSCAR ID MAXIMO PARA SABER HASTA DONDE PUEDO RECORRER
		if(utn_getNumeroEntero(&idIngresado, "Ingrese el ID que desea eliminar: ", "ERROR. ID INVALIDO", 1, 90000, 3)==0)
		{
			index=Passenger_findByIdInTheLinkedList(pArrayListPassenger, idIngresado);
			for(int i=0;i<len;i++)
			{
				auxiliarPasajeros=ll_get(pArrayListPassenger, index);
			}
			Passenger_showOnePassenger(auxiliarPasajeros);
			if(utn_getUnCaracter(&opcion, "Esta seguro que desea eliminar este pasajero? Y/N", "ERROR. OPCION INVALIDA", 'A', 'Z', 3)==0 && opcion=='Y')
			{
				if(ll_remove(pArrayListPassenger, index)==0)
				{
					printf("Se eliminó con exito\n");
				}
				else
				{
					printf("Error en la baja\n");
					index=-1;
				}
			}
		}

	}
    return index;
}

/** \brief Ordenar pasajeros
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_sortPassenger(LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo texto).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_saveAsText(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

/** \brief Guarda los datos de los pasajeros en el archivo data.csv (modo binario).
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 */
int controller_saveAsBinary(char* path , LinkedList* pArrayListPassenger)
{
    return 1;
}

