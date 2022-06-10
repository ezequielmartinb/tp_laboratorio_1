#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Passenger.h"

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromText(FILE* pFile , LinkedList* pArrayListPassenger, char* path)
{
	Passenger* auxiliarPasajeros=NULL;
	int retornoFscanf;
	int retorno=-1;
	char idAuxiliar[50];
	char nombreAuxiliar[50];
	char apellidoAuxiliar[50];
	char precioAuxiliar[50];
	char tipoPasajeroAuxiliar[50];
	char codigoDeVueloAuxiliar[50];
	char estadoDeVueloAuxiliar[50];

	pFile=fopen(path, "r");
	if(pFile!=NULL)
	{
		fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAuxiliar,nombreAuxiliar,apellidoAuxiliar,precioAuxiliar, tipoPasajeroAuxiliar, codigoDeVueloAuxiliar, estadoDeVueloAuxiliar);// falsa lectura
		do
		{
			retornoFscanf=fscanf(pFile,"%[^,],%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]\n",idAuxiliar,nombreAuxiliar,apellidoAuxiliar, precioAuxiliar, tipoPasajeroAuxiliar, codigoDeVueloAuxiliar, estadoDeVueloAuxiliar);
			if(retornoFscanf==7)
			{
				auxiliarPasajeros=Passenger_newParametros(idAuxiliar, apellidoAuxiliar, nombreAuxiliar,precioAuxiliar, tipoPasajeroAuxiliar, codigoDeVueloAuxiliar, estadoDeVueloAuxiliar);
				if(auxiliarPasajeros!=NULL)
				{
					ll_add(pArrayListPassenger,auxiliarPasajeros);
					//printf("ENTRE AL IF DEL ADD\n");
					retorno=0;
				}
			}
			else
			{
				break;
			}

		}while(!feof(pFile));

		fclose(pFile);
	}

    return retorno;
}

/** \brief Parsea los datos los datos de los pasajeros desde el archivo data.csv (modo binario).
 *
 * \param path char*
 * \param pArrayListPassenger LinkedList*
 * \return int
 *
 */
int parser_PassengerFromBinary(FILE* pFile , LinkedList* pArrayListPassenger)
{

    return 1;
}
