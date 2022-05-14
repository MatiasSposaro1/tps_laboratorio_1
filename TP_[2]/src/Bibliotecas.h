/*
 * Bibliotecas.h
 *
 *  Created on: 7 may. 2022
 *      Author: matia
 */

#ifndef BIBLIOTECAS_H_
#define BIBLIOTECAS_H_
/**
 * @fn int getInt(char*, int*)
 * @pre sirve para validar un dato de tipo entero
 * @param mensaje
 * @param pResultado
 * @return -1 ERROR / 0 OK!
 */
	int getInt(char* mensaje, int* pResultado,int min,int max);
/****************************************************/
/**
 * @fn int getFloat(char*, float*)
 * @pre sirve para validar un dato de tipo flotante
 * @param mensaje
 * @param pResultado
 * @return -1 ERROR / 0 OK!
 */
	int getFloat(char* mensaje, float* pResultado);
/****************************************************/
/**
 * @fn int getString(char*, char[])
 * @pre sirve para validar un dato de tipo de caracteres
 * @param mensaje
 * @param pResultado
 * @return -1 ERROR / 0 OK!
 */
	int getString(char* mensaje, char pResultado[]);
 /****************************************************/
/**
 * @fn int getStringDigit(char*, char[])
 * @pre sirve para validar un tipo de dato string o numerico
 * @param mensaje
 * @param pResultado
 * @return 0 ERROR / 1 OK!
 */
	int getStringDigit(char* mensaje,char pResultado[]);
/****************************************************/
	/**
	 * @fn int getEntero(int*, char*, char*, int, int)
	 * @pre sirve para validar un tipo de dato entero con un maximo y minimo
	 * @param integer
	 * @param message
	 * @param messageMistake
	 * @param min
	 * @param max
	 * @return
	 */
	int getEntero(int* integer, char* message, char* messageMistake, int min, int max);

#endif /* BIBLIOTECAS_H_ */
