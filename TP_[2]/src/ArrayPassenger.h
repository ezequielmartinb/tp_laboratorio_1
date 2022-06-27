#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

typedef struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flyCode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}Passenger;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);
/** \brief add in a existing list of passengers the values received as parameters
* in the first empty position
* \param list passenger*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param price float
* \param typePassenger int
* \param flycode[] char
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
/** \brief find a Passenger by Id en returns the index position in array.
*
* \param list Passenger*
* \param len int
* \param id int
* \return Return passenger index position or (-1) if [Invalid length or
NULL pointer received or passenger not found]
*
*/
int findPassengerById(Passenger* list, int len,int id);
int modifyPassenger(Passenger* list, int len, int id);
/** \brief Remove a Passenger by Id (put isEmpty Flag in 1)
*
* \param list Passenger*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a passenger] - (0) if Ok
*
*/
int removePassenger(Passenger* list, int len, int id);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengers(Passenger* list, int len, int order);
/// @fn void mostrarUnPasajeros(Passenger) Muestra un pasajero
/// @brief
///
/// @pre
/// @post
/// @param list
void mostrarUnPasajeros(Passenger list);
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length);
/** \brief Sort the elements in the array of passengers, the argument order
indicate UP or DOWN order
*
* \param list Passenger*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int sortPassengersByCode(Passenger* list, int len, int order);
/// @brief Imprime la lista de pasajeros por el estado de vuelo ACTIVO
///
/// @param list Passenger*
/// @param length int
/// @return retorna 0 en caso de EXITO y -1 en caso de ERROR
int printPassengerByStatusFlight(Passenger* list, int length);
/// @brief Calcula el promedio de los precios de los pasajes
///
/// @param list Passenger*
/// @param len int
/// @return retorna el promedio obtenido
float promedioPreciosPasaje(Passenger* list, int len);
/// @fn int contarPasajerosPorPrecio(Passenger*, int, float)
/// @brief Cuenta la cantidad de pasajeros que superan el precio promedio
///
/// @pre
/// @post
/// @param list Passenger*
/// @param len int
/// @param promedio float
/// @return retorna la cantidad de pasajeros, en caso de EXITO y -1 en caso de ERROR
int contarPasajerosPorPrecio(Passenger* list, int len, float promedio);
/// @brief Realiza la carga forzada de datos en la lista de pasajeros
///
/// @pre
/// @post
/// @param list Passenger*
/// @param listaHardcodeada Passenger*
/// @param lenList int
/// @param lenListaHarcodeada int
/// @return Retorna 0 en caso de EXITO y retorna -1 en caso de ERROR
int cargaForzada(Passenger* list, Passenger* listaHardcodeada, int lenList, int lenListaHarcodeada);
/// @brief Busca el ultimo ID ingresado en la lista y lo devuelve
///
/// @pre
/// @post
/// @param list Passenger*
/// @param len int
/// @return Retorno -1 en caso de error y el ultimo id en caso de exito
int ultimoId(Passenger* list, int len);


#endif /* ARRAYPASSENGER_H_ */
