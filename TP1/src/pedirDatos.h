
#ifndef PEDIRDATOS_H_
#define PEDIRDATOS_H_

/// @fn int getInt(int*, char*, char*, int, int, int)
/// @brief La funcion pide un entero por referencia entre los rangos minimos y maximos
/// 	   y retorno 0 en caso de exito y -1 en caso de error
///
/// @param pNumeroIngresado puntero al entero
/// @param mensaje mensaje para pedir el entero
/// @param mensajeError mensaje de error en caso de fallo en el ingreso del entero
/// @param minimo valor minimo que puede tomar el entero
/// @param maximo valor maximo que puede tomar el entero
/// @param reintentos cantidad de reintentos que tiene el usuario para ingresar un entero correcto
/// @return retorna 0 en caso de exito y -1 en caso de error
int getInt(int* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);
/// @fn int getFloat(float*, char*, char*, int, int, int)
/// @brief La funcion pide un flotante por referencia entre los rangos minimos y maximos
/// 	   y retorno 0 en caso de exito y -1 en caso de error
///
/// @param pNumeroIngresado puntero al flotante
/// @param mensaje mensaje para pedir el flotante
/// @param mensajeError mensaje de error en caso de fallo en el ingreso del flotante
/// @param minimo valor minimo que puede tomar el flotante
/// @param maximo valor maximo que puede tomar el flotante
/// @param reintentos cantidad de reintentos que tiene el usuario para ingresar un flotante correcto
/// @return retorna 0 en caso de exito y -1 en caso de error
int getFloat(float* pNumeroIngresado, char* mensaje, char* mensajeError, int minimo, int maximo, int reintentos);


#endif /* PEDIRDATOS_H_ */
