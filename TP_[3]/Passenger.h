/*
 * Passenger.h
 *
 *  Created on: 19 may. 2022
 *
 */

#ifndef PASSENGER_H_
#define PASSENGER_H_

typedef struct
{
	int id;
	char nombre[50];
	char apellido[50];
	float precio;
	char tipoPasajero[50];
	char codigoVuelo[40];
	char estadoVuelo[50];
}Passenger;

Passenger* Passenger_new();
Passenger* Passenger_newParametros(char* idStr,char* nombreStr,char* apellidoStr,char* tipoPasajeroStr,char* precioStr,char* codigoVueloStr,char* estadoVuelo);

void Passenger_delete(Passenger* this);

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
int Passenger_getPrecio(Passenger* this,float *precio);

int Passenger_setEstadoVuelo(Passenger* this,char* estadoVuelo);
int Passenger_getEstadoVuelo(Passenger* this,char* estadoVuelo);

/////////////////////////////////////////////////////
int maxId(LinkedList* listaPasajeros);
int buscarPasajerosId(LinkedList* lista, int id);
int ordenarPorNombre(void* a, void* b);
int ordenarPorApellido(void* a, void* b);
int ordenarPorPrecio(void* a, void* b);
int ordenarPorCodigoVuelo(void* a, void* b);
int ordenarPorEstadoVuelo(void* a, void* b);
int ordenarPorTipoPasajero(void* a, void* b);

#endif /* PASSENGER_H_ */
