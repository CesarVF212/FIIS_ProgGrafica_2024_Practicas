#include <iostream>
#include "libprgr/vectorMath.h"

using namespace libPRGR;
using namespace std;

int main(int argc, char** argv)
{
	//// Ej0 trasl
	//float X = 10, Y = 0, Z = 0;

	//matrix4x4f m1 = {
	//	.rows =				{{1,0,0,X},
	//						 {0,1,0,Y},
	//						 {0,0,1,Z},
	//						 {0,0,0,1}}
	//};
	//
	//vector4f v1 = { 10, 10, 10, 1 };
	//vector4f v2 = { 0, 0, 0, 0 };

	//v2 = m1 * v1;


	//std::cout << v2 << std::endl;


	// EJERCICIO 1 ESCALADO

	/*vector4f P1 = { -0.5, -0.5, 0.0, 1 };
	vector4f P2 = {  0.0,  0.5, 0.0, 1 };
	vector4f P3 = {  0.5, -0.5, 0.0, 1 };

	matrix4x4f scale = {
		.rows =					{{2,0,0,0},
								 {0,2,0,0},
								 {0,0,2,0},
								 {0,0,0,1}}
	};

	vector4f P1p = scale * P1;
	vector4f P2p = scale * P2;
    vector4f P3p = scale * P3;


	std::cout << P1p << std::endl;
	std::cout << P2p << std::endl;
	std::cout << P3p << std::endl;*/


	//EJERCICIO 3 ROTACION

	

	/*float alpha = toRadians(45.0f);

	matrix4x4f rotX = {
		.rows =					{{1,0,0,0},
								 {0,cos(alpha),-sin(alpha),0},
								 {0,sin(alpha),cos(alpha),0},
								 {0,0,0,1}}
	};

	vector4f v1 = { 10, 10, 10, 1 };

	vector4f vrot = rotX * v1;

	cout << vrot << endl;

	return 0;*/

	Render render(20, 20);

	vector4f punto = { 3, 3, 0, 0 };

	cout << "punto original: " << punto << endl;


	/*render.resetBuffer();
	render.markBorders();
	render.putPixel(punto.data[0], punto.data[1]);
	render.draw();*/


	render.resetBuffer();
	render.markBorders();

	// Traslacion del punto 6 unidades a la derecha.

	matrix4x4f matriz_tras = make_translate(6, 0, 0);
	cout << "Matriz de transposicion" << endl;
	cout << matriz_tras.rows[0] << endl;
	cout << matriz_tras.rows[1] << endl;
	cout << matriz_tras.rows[2] << endl;
	cout << matriz_tras.rows[3] << endl;
	vector4f puntoTras = { 0,0,0,0 };
	puntoTras = matriz_tras*punto;

	
	cout << "Punto traspuesto: " << puntoTras << endl;
	render.putPixel(puntoTras.data[0], puntoTras.data[1]);
	render.draw();
	



}