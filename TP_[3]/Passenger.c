#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Passenger.h"

Passenger* Passenger_new()
{
	Passenger* auxiliar=NULL;

	auxiliar=(Passenger*) malloc(sizeof(Passenger));

	if (auxiliar!=NULL)
	{
		Passenger_setId(auxiliar, 0);
		Passenger_setNombre(auxiliar, " ");
		Passenger_setApellido(auxiliar, " ");
		Passenger_setPrecio(auxiliar, 0);
		Passenger_setTipoPasajero(auxiliar, 0);
		Passenger_setCodigoVuelo(auxiliar, " ");
	}

	return auxiliar;
}
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* tipoPasajeroStr, char* codigoVueloStr)
{
	Passenger* auxiliar=NULL;

	auxiliar=Passenger_new();

	if(auxiliar!=NULL && idStr!=NULL && nombreStr!=NULL && apellidoStr!=NULL && precioStr!=NULL && tipoPasajeroStr!=NULL && codigoVueloStr!=NULL)
	{
		Passenger_setId(auxiliar, atoi(idStr));
		Passenger_setNombre(auxiliar, nombreStr);
		Passenger_setApellido(auxiliar, apellidoStr);
		Passenger_setPrecio(auxiliar, atof(precioStr));
		Passenger_setTipoPasajero(auxiliar, atoi(tipoPasajeroStr));
		Passenger_setCodigoVuelo(auxiliar, codigoVueloStr);
	}

	return auxiliar;
}
void Passenger_delete(Passenger* this)
{
	if(this!=NULL)
	{
		free(this);
	}
}
int Passenger_setId(Passenger* this,int id)
{
	int retorno=-1;

	if (this!=NULL && id>0)
	{
		this->id=id;
		retorno=0;
	}

	return retorno;
}
int Passenger_getId(Passenger* this,int* id)
{
	int retorno=-1;

	if(this!=NULL && id!=NULL)
	{
		*id=this->id;
		retorno=0;
	}

	return retorno;
}

int Passenger_setNombre(Passenger* this,char* nombre)
{
	int retorno=-1;

	if (this!=NULL && nombre!=NULL)
	{
		strcpy(this->nombre, nombre);
		retorno=0;
	}

	return retorno;
}
int Passenger_getNombre(Passenger* this,char* nombre)
{
	int retorno=-1;

	if(this!=NULL && nombre!=NULL)
	{
		strcpy(nombre, this->nombre);
		retorno=0;
	}

	return retorno;
}

int Passenger_setApellido(Passenger* this,char* apellido)
{
	int retorno=-1;

	if (this!=NULL && apellido!=NULL)
	{
		strcpy(this->apellido, apellido);
		retorno=0;
	}

	return retorno;
}
int Passenger_getApellido(Passenger* this,char* apellido)
{
	int retorno=-1;

	if(this!=NULL && apellido!=NULL)
	{
		strcpy(apellido, this->apellido);
		retorno=0;
	}

	return retorno;
}

int Passenger_setPrecio(Passenger* this,float precio)
{
	int retorno=-1;

	if (this!=NULL && precio>0)
	{
		this->precio= precio;
		retorno=0;
	}

	return retorno;
}
int Passenger_getPrecio(Passenger* this,float* precio)
{
	int retorno=-1;

	if(this!=NULL && precio!=NULL)
	{
		*precio=this->precio;
		retorno=0;
	}

	return retorno;
}

int Passenger_setTipoPasajero(Passenger* this,int tipoPasajero)
{
	int retorno=-1;

	if (this!=NULL && tipoPasajero>0)
	{
		this->tipoPasajero=tipoPasajero;
		retorno=0;
	}

	return retorno;
}
int Passenger_getTipoPasajero(Passenger* this,int* tipoPasajero)
{
	int retorno=-1;

	if(this!=NULL && tipoPasajero!=NULL)
	{
		*tipoPasajero=this->tipoPasajero;
		retorno=0;
	}

	return retorno;
}

int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;

	if (this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(this->codigoVuelo, codigoVuelo);
		retorno=0;
	}

	return retorno;
}
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo)
{
	int retorno=-1;

	if(this!=NULL && codigoVuelo!=NULL)
	{
		strcpy(codigoVuelo, this->codigoVuelo);
		retorno=0;
	}

	return retorno;
}

int Passenger_showOnePassenger(Passenger* this)
{
	int retorno = 1;
	int idAuxiliar;
	char nombreAuxiliar[50];
	char apellidoAuxiliar[50];
	float precioAuxiliar;
	int tipoPasajeroAuxiliar;
	char codigoVueloAuxiliar[50];

	if(this!=NULL)
	{
		if(Passenger_getId(this, &idAuxiliar)==0 &&	Passenger_getNombre(this, nombreAuxiliar)==0 &&
		   Passenger_getApellido(this, apellidoAuxiliar)==0 && Passenger_getPrecio(this, &precioAuxiliar)==0 &&
		   Passenger_getTipoPasajero(this, &tipoPasajeroAuxiliar)==0 &&	Passenger_getCodigoVuelo(this, codigoVueloAuxiliar)==0 &&
		   Passenger_setId(this, idAuxiliar)==0 && Passenger_setNombre(this, nombreAuxiliar)==0 && Passenger_setApellido(this, apellidoAuxiliar)==0 &&
		   Passenger_setPrecio(this, precioAuxiliar)==0 && Passenger_setTipoPasajero(this, tipoPasajeroAuxiliar)==0 &&
		   Passenger_setCodigoVuelo(this, codigoVueloAuxiliar)==0)// HACER UNA FUNCION QUE VALIDE SETTERS Y GETTERS
		{
			printf("%4d %-15s %-15s %4.2f %4d %-15s\n",idAuxiliar, nombreAuxiliar,	apellidoAuxiliar, precioAuxiliar, tipoPasajeroAuxiliar, codigoVueloAuxiliar);
			retorno=0;
		}

	}

	return retorno;
}
int Passenger_showListPassenger(Passenger* this[], int len)
{
	int retorno=1;

	if(this!=NULL && len>0)
	{
		for (int i=0; i<len; i++)
		{
			if(this[i]!=NULL)// SI LA POSICION EN EL ARRAY NO ESTA VACIA, MUESTRO EL ARRAY
			{
				Passenger_showOnePassenger(this[i]);
			}
		}
	}

	return retorno;
}

int Passenger_findFreeSpace(Passenger* this[], int len)
{
	int retorno=-1;
	if (this != NULL && len > 0)
	{
		for (int i = 0; i < len; i++)
		{
			//*(this + i) = NULL; NOTACION DE PUNTEROS
			if(this[i] == NULL)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}
int Passenger_findById(Passenger* this[], int len, int id)
{
	int retorno=-1;
	if (this != NULL && len > 0 && id>0)
	{
		for (int i = 0; i < len; i++)
		{
			//*(this + i) = NULL; NOTACION DE PUNTEROS
			if(this[i] != NULL && Passenger_getId(this[i], &id) == id)
			{
				retorno=i;
				break;
			}
		}
	}
	return retorno;
}

int Passenger_addPassenger(Passenger* this[], int len, char* id, char* nombre, char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo)
{
	int retorno=-1;
	int index;
	if (this != NULL && len > 0)
	{
		index=Passenger_findFreeSpace(this, len);
		if (this[index] == NULL)
		{
			this[index] = Passenger_newParametros(id, nombre, apellido, precio, tipoPasajero, codigoVuelo);
			retorno = 0;
		}
	}
	return retorno;
}
int Passenger_removePassenger(Passenger* this[], int len, int id)
{
	int retorno = -1;
	int index;

	if (this != NULL && len > 0 && id>0)
	{
		index=Passenger_findById(this, len, id);
		if (index!=-1 && Passenger_getId(this[index], &id) == id)
		{
			Passenger_showOnePassenger(this[index]);
			Passenger_delete(this[index]);
			this[index]=NULL;
			retorno=0;
		}
	}

	return retorno;
}
int Passenger_modifyPassenger(Passenger* this[], int len, int id, char* nuevoApellido)
{
	int retorno = -1;
	int index;
	if (this != NULL && len > 0)
	{
		index=Passenger_findById(this, len, id);
		Passenger_showOnePassenger(this[index]);
		if (index!=-1 && Passenger_getId(this[index], &id) == id)
		{
			Passenger_setApellido(this[index], nuevoApellido);
			retorno = 0;
		}
	}

	return retorno;
}
