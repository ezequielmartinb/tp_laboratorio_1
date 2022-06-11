#ifndef PASSENGER_H_
#define PASSENGER_H_
#include "LinkedList.h"

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char codigoVuelo[20];
	char tipoPasajero[50];
	char estadoVuelo[50];


}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr, char* precioStr, char* codigoVueloStr, char* tipoPasajeroStr, char* estadoVueloStr);
Passenger* Passenger_newParametrosCorrectos(int id,char* nombre,char* apellido, float precio, char* codigoVuelo, char* tipoPasajero, char* estadoVuelo);
void Passenger_delete();

int Passenger_setId(Passenger* this,int id);
int Passenger_getId(Passenger* this,int* id);

int Passenger_setNombre(Passenger* this,char* nombre);
int Passenger_getNombre(Passenger* this,char* nombre);
int Passenger_setApellido(Passenger* this,char* apellido);
int Passenger_getApellido(Passenger* this,char* apellido);
int Passenger_setCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_getCodigoVuelo(Passenger* this,char* codigoVuelo);
int Passenger_setTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_getTipoPasajero(Passenger* this,char* tipoPasajero);
int Passenger_setPrecio(Passenger* this,float precio);
int Passenger_getPrecio(Passenger* this,float* precio);
int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

int Passenger_showOnePassenger(Passenger* this);
int Passenger_showListPassenger(Passenger* Passenger[], int len);

int Passenger_findFreeSpace(Passenger* this[], int len);
int Passenger_findById(Passenger* this[], int len, int id);
int Passenger_findByIdInTheLinkedList(LinkedList* listaPasajeros,int id);

int Passenger_addPassenger(Passenger* this[], int len, char* id, char* nombre, char* apellido, char* precio, char* tipoPasajero, char* codigoVuelo, char* estadoVuelo);
int Passenger_removePassenger(Passenger* this[], int len, int id);
int Passenger_modifyPassenger(Passenger* this, int index, int id, int opcion);

int Passenger_compareByID(void* unPasajero, void* otroPasajero);
int Passenger_compareByApellido(void* unPasajero, void* otroPasajero);
int Passenger_compareByNombre(void* unPasajero, void* otroPasajero);
int Passenger_compareByPrecio(void* unPasajero, void* otroPasajero);
int Passenger_compareByCodigoDeVuelo(void* unPasajero, void* otroPasajero);
int Passenger_compareByTipoPasajero(void* unPasajero, void* otroPasajero);
int Passenger_compareByEstadoVuelo(void* unPasajero, void* otroPasajero);


#endif /* PASSENGER_H_ */
