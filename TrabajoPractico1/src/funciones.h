/*
 * funciones.h
 *
 *
 *
 */

#ifndef FUNCIONES_H_
#define FUNCIONES_H_

/* \brief esta funcion sirve para hacer el descuento pagando con tarjea debito
 * \param  precio que ingresa
 * \return el resultado de la cuenta
*/
float debito(float precio);
/********************************************************************************/
/* \brief esta funcion sirve para hacer el interes pagando con tarjeta credito
 * \param precio que ingresa
 * \return el resultado de la cuenta
 */
float interes(float precio);
/********************************************************************************/
/* \brief esta funcion sirve para convertir pesos a bitcoin
 * \param precio que ingresa
 * \return el resultado de la conversion
 */
float bitcoin(float precio);
/********************************************************************************/
/* \brief esta funcion sirve para mostrar el precio unitario
 * \param precio que ingresa
 * \param km que ingresa
 * \return el resultado del precio unitario
 */
float unitario(float precio,float km);
/********************************************************************************/
/* \brief esta funcion sirve para sacar la diferencia entre los dos precios
 * \param precioA de aerolineas
 * \param precioL de latam
 * \return la diferencia de precios
 */
float diferencia(float precioA,float precioL);
#endif /* FUNCIONES_H_ */
