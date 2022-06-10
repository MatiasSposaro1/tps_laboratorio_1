/*
 * funciones.h
 *
 *  Created on: 17 sep. 2021
 *      Author: matia
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


/** \brief sirve para validar entero*/
int getInt(char* mensaje, int* pResultado);
/** \brief
 *
 * \param mensaje char*
 * \param pResultado float*
 * \return int
 *
 */
int getFloat(char* mensaje, float* pResultado);

/** \brief
 *
 * \param mensaje char*
 * \param pResultado[] char
 * \return int
 *
 */
int getString(char* mensaje, char pResultado[]);


/**
 * @brief para validar que una cadena de string contenga solo numeros
 * @param mensaje
 * @param pResultado
 * @return int
 */
int getStringDigit(char* mensaje,char pResultado[]);

/**
 * @brief sirve para validar una cadena de enteros con mensaje de error y min y max.
 */
int getEntero(int* integer, char* message, char* messageMistake, int min, int max);

/** \brief funciton that set mayus to the first letter of a name or lastName
 *
 * \param char vec
 * \param  large of vec
 * \return  int return 0 if errorr or 1 if ok
 *
 */
int setMayus(char vec[], int len);


#endif /* FUNCIONES_H_ */
