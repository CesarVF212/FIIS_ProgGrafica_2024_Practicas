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

	//COMIENZO DEL PROGRAMA

	Render render(20, 20);

	vector4f punto = { 3, 3, 0, 1 };

	cout << "punto original: " << punto << endl;


	render.resetBuffer();
	render.markBorders();
	render.putPixel(punto.data[0], punto.data[1]);
	render.draw();


	render.resetBuffer();
	render.markBorders();

	// Traslacion del punto 6 unidades a la derecha.

	matrix4x4f matriz_tras = make_translate(3, 0, 0);
	cout << "Matriz de transposicion" << endl;
	cout << matriz_tras << endl;
	punto = matriz_tras * punto;
	cout << "Punto traspuesto: " << punto << endl;
	render.putPixel(punto.data[0], punto.data[1]);
	render.draw();

	cout << "------------------------------------------------------------" << endl;
	cout << "--------------------CREACION DE VECTORES--------------------" << endl;
	cout << "------------------------------------------------------------" << endl;
	vector4f v1 = make_vector(1, 2, 3, 1);
	cout <<"Vector 1 original: " << v1 << endl;
	vector4f v2 = make_vector(1, 1, 1, 1);
	cout << "Vector 2 original: " << v2 << endl;

	cout << "--------------------NORMALIZACION DE VECTORES--------------------" << endl;
	vector4f v1Norm = normalize(v1);
	cout << "Vector 1 normalizado: " << v1Norm << endl;

	cout << "--------------------SUMA DE VECTORES--------------------" << endl;
	vector4f vSum = v1 + v2;
	cout << "Vector suma: " << vSum << endl;

	cout << "--------------------RESTA DE VECTORES--------------------" << endl;
	vector4f vRes = v1 - v2;
	cout << "Vector resta: " << vRes << endl;

	cout << "--------------------DOT PRODUCT/MULTIPLICACION ESCALAR DE VECTORES--------------------" << endl;
	float dot = v1 * v2;
	cout << "Dot product: " << dot << endl;

	cout << "--------------------CROSS PRODUCT/MULTIPLICACION VECTORIAL DE VECTORES--------------------" << endl;
	vector4f cross = v1 ^ v2;
	cout << "Cross product: " << cross << endl;

	cout << "------------------------------------------------------------" << endl;
	cout << "--------------------CREACION DE MATRICES--------------------" << endl;
	cout << "------------------------------------------------------------" << endl;

	matrix4x4f m = make_identity();
	cout << "Matriz identidad: " << endl;
	cout << m << endl;

	cout << "--------------------MATRIZ DE TRASLACION--------------------" << endl;
	matrix4x4f mTras = make_translate(1, 2, 3);
	cout << "Matriz de traslacion en 1,2,3: " << endl;
	cout << mTras << endl;

	cout << "--------------------MATRIZ DE ROTACION--------------------" << endl;
	matrix4x4f mRot = make_rotate(45, 90, 0);
	cout << "Matriz de rotacion en 45,90,0: " << endl;
	cout << mRot << endl;

	cout << "--------------------MATRIZ DE ESCALADO--------------------" << endl;
	matrix4x4f mScale = make_scale(5, 4, 3);
	cout << "Matriz de escalado en 2,2,2: " << endl;
	cout << mScale << endl;

	cout << "------------------------------------------------------------" << endl;
	cout << "--------------------OPERACION DE MATRICES--------------------" << endl;
	cout << "------------------------------------------------------------" << endl; 

	cout << "--------------------MULTIPLICACION DE MATRICES--------------------" << endl;
	matrix4x4f m1 = make_scale(2, 3, 5);
	matrix4x4f m2 = make_scale(1, 2, 3);

	matrix4x4f mMult = m1 * m2;
	cout << "Matriz 1: " << endl;
	cout << m1 << endl;
	cout << "Matriz 2: " << endl;
	cout << m2 << endl;
	cout << "Matriz multiplicada: " << endl;
	cout << mMult << endl;

	cout << "--------------------MULTIPLICACION DE MATRIZ Y VECTOR--------------------" << endl;
	vector4f v = make_vector(1, 2, 3, 1);
	matrix4x4f mV = make_scale(2, 3, 4);
	vector4f vMult = mV * v;
	cout << "Vector original: " << v << endl;
	cout << "Matriz: " << endl;
	cout << mV << endl;
	cout << "Vector multiplicado: " << vMult << endl;

	cout << "--------------------MULTIPICACION ESCALAR DE MATRIZ--------------------" << endl;
	matrix4x4f mEsc = make_scale(2, 3, 4);
	matrix4x4f mEscMult = 2 * mEsc;
	cout << "Matriz original: " << mEsc << endl;
	cout << "Matriz multiplicada por 2: " << mEscMult << endl;

	cout << "--------------------SUMA DE MATRICES--------------------" << endl;
	matrix4x4f mSum1 = make_scale(2, 3, 4);
	matrix4x4f mSum2 = make_scale(1, 2, 3);
	matrix4x4f mSum = mSum1 + mSum2;
	cout << "Matriz 1: " << endl;
	cout << mSum1 << endl;
	cout << "Matriz 2: " << endl;
	cout << mSum2 << endl;
	cout << "Matriz suma: " << endl;
	cout << mSum << endl;

	cout << "--------------------RESTA DE MATRICES--------------------" << endl;
	matrix4x4f mRes1 = make_scale(2, 3, 4);
	matrix4x4f mRes2 = make_scale(1, 2, 3);
	matrix4x4f mRes = mRes1 - mRes2;
	cout << "Matriz 1: " << endl;
	cout << mRes1 << endl;
	cout << "Matriz 2: " << endl;
	cout << mRes2 << endl;
	cout << "Matriz resta: " << endl;
	cout << mRes << endl;

	cout << "--------------------TRANSPUESTA DE MATRIZ--------------------" << endl;
	matrix4x4f mTrans = make_scale(2, 3, 4);
	matrix4x4f mTransp = transpose(mTrans);
	cout << "Matriz original: " << endl;
	cout << mTrans << endl;
	cout << "Matriz transpuesta: " << endl;
	cout << mTransp << endl;

	cout << "--------------------DETERMINANTE--------------------" << endl;
	matrix4x4f mDet = make_scale(2, 3, 4);
	float det = determinant(mDet);
	cout << "Matriz original: " << endl;
	cout << mDet << endl;
	cout << "Determinante: " << det << endl;

	cout << "--------------------INVERSA DE MATRIZ--------------------" << endl;
	matrix4x4f mInv = make_scale(2, 3, 4);
	matrix4x4f mInvRes = inverse(mInv);
	cout << "Matriz original: " << endl;
	cout << mInv << endl;
	cout << "Matriz inversa: " << endl;
	cout << mInvRes << endl;

	cout << "--------------------QUATERNION--------------------" << endl;
	vector4f q = make_quaternion(1, 2, 3, 45);
	cout << "Quaternion: " << q << endl;

	cout << "--------------------ROTACION CON QUATERNION--------------------" << endl;
	matrix4x4f mRotQuat = make_rotate(q);
	cout << "Matriz de rotacion con quaternion: " << endl;
	cout << mRotQuat << endl;





}