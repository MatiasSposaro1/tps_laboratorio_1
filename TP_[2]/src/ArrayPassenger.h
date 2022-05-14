/*
 * ArrayPassenger.h
 *
 */

#ifndef ARRAYPASSENGER_H_
#define ARRAYPASSENGER_H_

struct
{
	int id;
	char name[51];
	char lastName[51];
	float price;
	char flycode[10];
	int typePassenger;
	int statusFlight;
	int isEmpty;
}typedef Passenger;

/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Passenger* Pointer to array of passenger
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initPassengers(Passenger* list, int len);
/*********************************************************************************/
/**\brief add in a existing list of passengers the values received as parameters
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
*
*/
int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[]);
/*********************************************************************************/
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
/*********************************************************************************/
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
/*********************************************************************************/
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
/*********************************************************************************/
/** \brief print the content of passengers array
*
* \param list Passenger*
* \param length int
* \return int
*
*/
int printPassenger(Passenger* list, int length);
/*********************************************************************************/
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
/*********************************************************************************/
/**
 * @fn int agregarPasajeros(Passenger*, int, int*)
 * @pre pide los datos para hacer el alta de pasajeros
 * @post
 * @param list
 * @param tamList
 * @param id
 * @return -1 ERROR! // 0 OK!
 */
int agregarPasajeros(Passenger* list,int tamList,int* id);
/*********************************************************************************/
/**
 * @fn int modificarPasajeros(Passenger*, int)
 * @pre sirve para modificar los datos de un pasajero
 * @post
 * @param list
 * @param tamList
 * @return -1 ERROR! // 0 OK!
 */
int modificarPasajeros(Passenger* list,int tamList);
int eliminarPasajero(Passenger* list,int tamList);
int SubmenuOrden();
int informarPromedio(Passenger* list,int tamList);
int hardcodeoPasajeros(Passenger* list, int* id, int* contador);

#endif /* ARRAYPASSENGER_H_ */