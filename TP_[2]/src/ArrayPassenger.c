/*
 * ArrayPassenger.c
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "ArrayPassenger.h"
#include "Bibliotecas.h"



int initPassengers(Passenger* list, int len)
{
	int retorno = -1;

	if(list !=NULL && len>0)
	{
		for(int i = 0;i<len;i++)
		{
			list[i].id = -1;
			list[i].isEmpty = 1;
			list[i].statusFlight = 0; //OCUPADO
		}
		retorno = 0;
	}
	return retorno;
}

int addPassenger(Passenger* list, int len, int id, char name[],char lastName[],float price,int typePassenger, char flycode[])
{
	int retorno = -1;

	if(list!=NULL && len>0 && name!=NULL && lastName!=NULL && price>0 && typePassenger > 0 && flycode!=NULL)
	{
		for(int i = 0; i<len;i++)
		{
			if(list[i].isEmpty == 1)
			{
				list[i].id = id;
				strcpy(list[i].name,name);
				strcpy(list[i].lastName,lastName);
				list[i].price  = price;
				list[i].typePassenger = typePassenger;
				strcpy(list[i].flycode,flycode);
				list[i].statusFlight = 1; //ACTIVO
				list[i].isEmpty = 0;
			    retorno = 0;
			    break;
			}

		}
	}
	return retorno;
}

int agregarPasajeros(Passenger* list,int tamList,int* id)
{
	int retorno = -1;

	char nombre[51];
	char apellido[51];
	float precio;
	int tipoPasajero;
	char codigoVuelo[10];

	if(list != NULL && tamList > 0 && id != NULL)
	{
		printf("ID: %d\n", *id);
		getString("Ingrese nombre: ",nombre);
		getString("Ingrese apellido: ",apellido);
		getFloat("Ingrese precio: ",&precio);
		getInt("Ingrese un tipo de pasajero\n1.Primera clase\n2.Clase Ejecutiva\n3.Clase turistica:",&tipoPasajero,1,3);
		getString("Ingrese el codigo de vuelo: ",codigoVuelo);

		addPassenger(list, tamList, *id, nombre, apellido, precio, tipoPasajero, codigoVuelo);

		*id  = *id + 1;
		printf("Se creo exitosamente\n");
		retorno = 0;
	}
	return retorno;
}

int printPassenger(Passenger* list, int length)
{
	char estadoVuelo[10];
	char tipoPasajero[20];

	 printf("+======+===============+===============+=============+=====================+=====================+==========================+\n");
	 printf("|  ID  |    Nombre     |   Apellido    |   Precio    |   Codigo de Vuelo   | 	Tipo de Pasajero  |	 Estado de Vuelo	      \n");
	 printf("+======+===============+===============+=============+=====================+=====================+==========================+\n");

	for(int i = 0;i<length;i++)
	{
		if(list[i].isEmpty == 0)
		{
			switch(list[i].statusFlight)
			{
			case 1:
				strcpy(estadoVuelo,"ACTIVO");
				break;
			case 0:
				strcpy(estadoVuelo,"INACTIVO ");
				break;
			}

			switch(list[i].typePassenger)
			{
			case 1:
				strcpy(tipoPasajero,"Primera clase");
				break;
			case 2:
				strcpy(tipoPasajero,"Clase Ejecutiva");
				break;
			case 3:
				strcpy(tipoPasajero,"Clase turistica");
				break;
			}
					printf("| %4d | %13s | %13s | %11.2f | %19s | %20s |  %20s  \n",

					list[i].id,list[i].name,list[i].lastName,list[i].price,list[i].flycode,tipoPasajero,estadoVuelo);
		}
	}

	return 0;
}

int findPassengerById(Passenger* list, int len,int id)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i=0;i<len;i++)
		{
			if(list[i].id == id)
			{
				retorno = i;
				break;
			}
		}
	}
	return retorno;
}

int modificarPasajeros(Passenger* list,int tamList)
{
	int retorno = -1;
	int id;
	Passenger nuevoPasajero;
	int modificar;
	int i = -1;


	if(list!=NULL && tamList > 0)
	{
		printPassenger(list, tamList);

		getInt("Escriba el ID que desea modificar:", &id,1,2000);

		i = findPassengerById(list, tamList, id);

		if( i != -1)
		{
			nuevoPasajero = list[i];

				getInt("Que desea modificar:\n1.Nombre\n2.Apellido\n3.Precio\n4.Tipo de pasajero\n5.Codigo de vuelo:",&modificar,1,5);
				while(modificar > 5 || modificar < 1)
				{
					getInt("ERROR!,Que desea modificar:\n1.Nombre\n2.Apellido\n3.Precio\n4.Tipo de pasajero\n5.Codigo de vuelo:", &modificar,1,5);
				}

			switch(modificar)
			{
			case 1:
				getString("Ingrese nuevo nombre: ",nuevoPasajero.name);
				break;
			case 2:
				getString("Ingrese nuevo apellido: ",nuevoPasajero.lastName);
				break;
			case 3:
				getFloat("Ingrese nuevo precio: ",&nuevoPasajero.price);
				break;
			case 4:
				getInt("Ingrese un nuevo tipo de pasajero(\n1.Primera clase\n2.Clase Ejecutiva\n3.Clase turistica): ",&nuevoPasajero.typePassenger,1,3);
				break;
			case 5:
				getString("Ingrese un nuevo  codigo de vuelo: ",nuevoPasajero.flycode);
				break;
			}
			list[i] = nuevoPasajero;
			retorno = 0;
			printf("Se modifico con exito \n");
		}
		else
		{
			printf("No existe el ID ingresado \n");
		}
	}
	return retorno;
}

int removePassenger(Passenger* list, int len, int id)
{
	int retorno = -1;

	if(list != NULL && len > 0)
	{
		for(int i = 0; i<len;i++)
		{
			if(list[i].id == id)
			{
				list[i].isEmpty = 1;
				retorno = 0;
				break;
			}
		}
	}

	return retorno;
}

int eliminarPasajero(Passenger* list,int tamList)
{
	int retorno = -1;
	int id;

	if(list != NULL && tamList > 0)
	{
		getInt("Escriba el ID que desea eliminar:", &id,1,2000);
		removePassenger(list, tamList,id);

		if(removePassenger(list,tamList,id)==-1)
		{
			printf("El id no existe \n");
		}
		else
		{
			printf("Se elimino con exito \n");
			retorno = 0;
		}
	}
	return retorno;
}

int sortPassengers(Passenger* list, int len, int order)
{
	int retorno = -1;

	Passenger auxPassenger;

	if(list != NULL && len > 0)
	{
		switch(order)
		{
		case 1:
			for(int i = 0; i<len -1;i++)
			{
				for(int j =i+1;j<len;j++)
				{
					if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
					{
						if((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName,list[j].lastName) == 1) || list[i].typePassenger > list[j].typePassenger)
						{
							auxPassenger = list[i];
							list[i] = list[j];
							list[j] = auxPassenger;

						}
					}
				}
				retorno = 0;
			}
			break;
		case 2:
			for(int i = 0; i<len -1;i++)
						{
							for(int j =i+1;j<len;j++)
							{
								if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
								{
									if((list[i].typePassenger == list[j].typePassenger && strcmp(list[i].lastName,list[j].lastName) == -1) || list[i].typePassenger < list[j].typePassenger)
									{
										auxPassenger = list[i];
										list[i] = list[j];
										list[j] = auxPassenger;

									}
								}
							}
							retorno = 1;
						}
		}
	}

	return retorno;
}

int informarPromedio(Passenger* list,int tamList)
{
	int retorno = -1;

	float Total = 0;
	int contadorPasajeros = 0;
	int superanPromedio = 0;
	float promedio;

	if(list  != NULL && tamList > 0)
	{
		for(int i = 0;i<tamList;i++)
		{
			if(list[i].isEmpty == 0)
			{
				Total += list[i].price;
				contadorPasajeros++;
			}
		}

		promedio = Total / contadorPasajeros;

		printf("El total es:%.2f\n",Total);
		printf("El promedio es:%.2f\n",promedio);

		for(int i = 0; i<tamList;i++)
		{
			if(list[i].isEmpty == 0 && list[i].price > promedio)
			{
				superanPromedio++;
			}
		}

		printf("La cantidad de pasajeros que superan el promedio son:%d\n",superanPromedio);
		retorno = 0;
	}
	return retorno;
}

int sortPassengersByCode(Passenger* list, int len, int order)
{
	int retorno = -1;

		Passenger auxPassenger;

		if(list != NULL && len > 0)
		{
			switch(order)
			{
			case 1:
				for(int i = 0; i<len -1;i++)
				{
					for(int j =i+1;j<len;j++)
					{
						if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
						{
							if((list[i].statusFlight== list[j].statusFlight && strcmp(list[i].flycode,list[j].flycode) == 1) || list[i].statusFlight > list[j].statusFlight)
							{
								auxPassenger = list[i];
								list[i] = list[j];
								list[j] = auxPassenger;

							}
						}
					}
					retorno = 0;
				}
				break;
			case 2:
				for(int i = 0; i<len -1;i++)
							{
								for(int j =i+1;j<len;j++)
								{
									if(list[i].isEmpty == 0 && list[j].isEmpty == 0)
									{
										if((list[i].statusFlight== list[j].statusFlight && strcmp(list[i].flycode,list[j].flycode) == -1) || list[i].statusFlight < list[j].statusFlight)
										{
											auxPassenger = list[i];
											list[i] = list[j];
											list[j] = auxPassenger;

										}
									}
								}
								retorno = 1;
							}
			}
		}

		return retorno;
}

int hardcodeoPasajeros(Passenger* list, int* id, int* contador)
{
    int ret = -1;
    Passenger ePasajeroHarcodeado [] = {
        {0, "Martin", "Perez", 12, "CABH", 3, 1, 0},
        {0, "Elias", "Gayan", 500, "MINER", 1, 1, 0},
        {0, "Lautaro", "Esposito", 400, "MAN", 2, 1, 0},
        {0, "Matias", "Sposaro", 1000, "CABJ", 1, 1, 0},
        {0, "Mauricio", "Borgonovo", 158888, "LAPIX", 1, 1, 0},
        {0, "Pilar", "Hernesta", 4122, "ABSA", 2, 1, 0},
        {0, "Daniela", "Pina", 400, "BLEM", 3, 1, 0},
        {0, "Carlos", "Piaggio", 900, "MINA", 1, 1, 0},
        {0, "Mariano", "Dotez", 4990, "BAJA", 2, 1, 0},
        {0, "Martin", "Palermo", 9, "GOL", 1, 1, 0},
    };

    if(list != NULL && id != NULL)
    {
        for(int i=0; i < 10; i++)
        {
          list[i] = ePasajeroHarcodeado[i];
          list[i].id = *id;
          *id = *id + 1;
          contador =contador +1;
        }
        ret = 0;
    }
    return ret;
}
