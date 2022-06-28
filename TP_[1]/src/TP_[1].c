/*
 ============================================================================
 Name        : TP_[1].c
 Author      : Matias Sposaro  1°DIV C
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#include "funciones.h"
#include "validaciones.h"

int main(void)
{
	setbuf(stdout,NULL);

		int opcion;

		int km = 0;

		//Aerolineas
		float precioAerolineas = 0;
		float resultadoDebitoAerolineas = 0;
		float resultadoCreditoAerolineas = 0;
		float resultadoBitcoinAerolineas = 0;
		float resultadoUnitarioAerolineas = 0;
		//Latam
		float precioLatam = 0;
		float resultadoDebitoLatam = 0;
		float resultadoCreditoLatam = 0;
		float resultadoBitcoinLatam = 0;
		float resultadoUnitarioLatam = 0;

		float resultadoDiferencia = 0;

		int flag = 0; //BANDERA 0(SIN CARGA) 1(CARGA)

		do
		{
			printf("***BIENVENIDOS A LA AGENCIA***\n \n");
						printf("1. Ingresar Kilometros: (KM = %d)\n", km);
						printf("2. Ingresar Precio de Vuelos: (Aerolineas = %f,Latam = %f)\n", precioAerolineas,precioLatam);
						printf("3. Calcular todos los costos: \n");
						printf("4. Informar resultados \n");
						printf("5. Carga forzada de datos\n");
						printf("6. Salir \n");



						getEntero(&opcion, "Ingrese opcion: ", "Error!,Reingrese Opcion: ", 1, 6);

			switch(opcion)
			{

				case 1:
					getEntero(&km, "Ingrese los kilometros: ", "Error,Reingrese los kilometros: ", 1,300000);
					break;

				case 2:
					if(km>0)
					{
						getFloat("Ingrese el precio de vuelo Aerolineas: ",&precioAerolineas);
						getFloat("Ingrese el precio de vuelo Latam: ",&precioLatam);

						while(precioAerolineas < 0 || precioLatam <0)
						{
							printf("ERROR!,Reingrese Precio\n");
							printf("-Precio vuelo Aerolineas: \n");
							scanf("%f",&precioAerolineas);
							printf("-Precio vuelo Latam: \n");
							scanf("%f",&precioLatam);
						}
					}
					else
					{
						printf("Ingrese primero los Kilometros \n");
						system("pause");
					}
					break;

				case 3:
					if(precioAerolineas > 0 && precioLatam > 0)
					{
						printf("CALCULANDO COSTOS..\n");
						system("pause");


						//Aerolineas
						resultadoDebitoAerolineas   = Calculardebito(precioAerolineas);
						resultadoCreditoAerolineas  = Calcularinteres(precioAerolineas);
						resultadoBitcoinAerolineas  = Calcularbitcoin(precioAerolineas);
						resultadoUnitarioAerolineas = Calcularunitario(precioAerolineas,km);
						//Latam
						resultadoDebitoLatam   = Calculardebito(precioLatam);
						resultadoCreditoLatam  = Calcularinteres(precioLatam);
						resultadoBitcoinLatam  = Calcularbitcoin(precioLatam);
						resultadoUnitarioLatam = Calcularunitario(precioLatam,km);

						resultadoDiferencia = Calculardiferencia(precioAerolineas,precioLatam);

						flag = 1;
					}
					else
					{
						printf("ERROR! Ingrese precios para poder calcular costos\n");
						system("pause");
					}
					break;
				case 4:
					if(flag == 1)
					{
						printf("Kilometros Ingresados: %d\n",km);

						printf("Precio Aerolineas: $%.2f \n"
						"\t a)Precio con tarjeta de debito:$ %.2f \n"
						"\t b)Precio con tarjeta de credito:$ %.2f \n"
						"\t c)Precio pagando con bitcoin: %f BTC \n"
						"\t d)Mostrar precio unitario: $ %.2f \n",precioAerolineas,resultadoDebitoAerolineas,resultadoCreditoAerolineas,resultadoBitcoinAerolineas,resultadoUnitarioAerolineas);

						printf("Precio Latam:$%.2f \n"
						"\t a)Precio con tarjeta de debito:$ %.2f  \n"
						"\t b)Precio con tarjeta de credito:$ %.2f \n"
						"\t c)Precio pagando con bitcoin:%f BTC \n"
						"\t d)Mostrar precio unitario: $ %.2f \n",precioLatam,resultadoDebitoLatam,resultadoCreditoLatam,resultadoBitcoinLatam,resultadoUnitarioLatam);


						printf("La diferencia de precio es: $ %.2f \n",resultadoDiferencia);
						flag = 0;
						system("pause");
					}
					else
					{
						printf("Cargue primero precios para calcular el costo \n");
						system("pause");
					}

					break;

				case 5:

					//Datos Harcodeados
					km = 7090;
					precioAerolineas = 162965;
					precioLatam = 159339;

					printf("CARGA FORZADA... \n");
					printf("--------------------\n");

					//Aerolineas
					resultadoDebitoAerolineas   = Calculardebito(precioAerolineas);
					resultadoCreditoAerolineas  = Calcularinteres(precioAerolineas);
					resultadoBitcoinAerolineas  = Calcularbitcoin(precioAerolineas);
					resultadoUnitarioAerolineas = Calcularunitario(precioAerolineas,km);
					//Latam
					resultadoDebitoLatam   = Calculardebito(precioLatam);
					resultadoCreditoLatam  = Calcularinteres(precioLatam);
					resultadoBitcoinLatam  = Calcularbitcoin(precioLatam);
					resultadoUnitarioLatam = Calcularunitario(precioLatam,km);

					printf("Kilometros Ingresados: %d\n",km);

					printf("Precio Aerolineas: $%.2f \n"
					"\t a)Precio con tarjeta de debito:$ %.2f \n"
					"\t b)Precio con tarjeta de credito:$ %.2f \n"
					"\t c)Precio pagando con bitcoin: %f BTC \n"
					"\t d)Mostrar precio unitario: $ %.2f \n",precioAerolineas,resultadoDebitoAerolineas,resultadoCreditoAerolineas,resultadoBitcoinAerolineas,resultadoUnitarioAerolineas);

					printf("Precio Latam:$%.2f \n"
					"\t a)Precio con tarjeta de debito:$ %.2f  \n"
					"\t b)Precio con tarjeta de credito:$ %.2f \n"
					"\t c)Precio pagando con bitcoin:%f BTC \n"
					"\t d)Mostrar precio unitario: $ %.2f \n",precioLatam,resultadoDebitoLatam,resultadoCreditoLatam,resultadoBitcoinLatam,resultadoUnitarioLatam);

					system("pause");

				break;
				case 6:
					printf("Saliendo..\n");
					break;

				default:
					printf("Opcion invalida!! \n");
					system("pause");

			}

		} while(opcion != 6);


	return EXIT_SUCCESS;
}
