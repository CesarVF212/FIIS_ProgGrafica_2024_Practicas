#pragma once
#define _USE_MATH_DEFINES
#include <math.h>
#include <iostream>
using namespace std;


namespace libPRGR {

	// -------------ESTRUCTURA TIPO VECTOR4F---------------
	typedef struct {

		union{ // Se usa una union para tener varias maneras de obtener esta strust. x, r son el mismo elemento pero con nombre distinto
			struct{
				float x, y, z, w; // Para vectores
			};
			struct{
				float r, g, b, a; // Para colores RGBalpha, son porcentajes
			};
			float data[4];
		};

	} vector4f;
	//------------------------------------------------------
	
	// -------------ESTRUCTURA TIPO MATRIX4X4F---------------
	typedef struct {
		union {
			float mat2D[4][4];	// [2][3]
			float mat1[16];		// [14]
			vector4f rows[4];	// formato de 4 vectores4f
		};

	} matrix4x4f;
	//------------------------------------------------------
	inline matrix4x4f operator*(matrix4x4f m1, matrix4x4f m2);

	

	inline std::ostream& operator<<(std::ostream& os, vector4f v) {
		os << "{" << v.data[0] << "," << v.data[1] << "," <<
			v.data[2] << "," << v.data[3] << "}\n";
		return os;
	}

	inline std::ostream& operator<<(std::ostream& os, matrix4x4f m) {
		os << m.rows[0] << m.rows[1] << m.rows[2] << m.rows[3] << "\n";
		return os;
	}

	inline float toRadians(float angle) {
		return angle*M_PI/(180.0f);
	}

	// METODOS SOBRE ESTRUCTURAS DE TIPO VECTOR4F
	// ------------------------------------------------
	
	// Metodo de inicializacion a partir de 4 floats
	inline vector4f make_vector(float x, float y, float z, float w) {

		vector4f vectorRes = { x, y, z, w };
		return vectorRes;
	}

	// Metodo para normalizar un vector. OJO, solo se usan las componentes X, Y, Z
	inline vector4f normalize(vector4f v) {
		float aux = sqrt(v.x * v.x + v.y * v.y + v.z * v.z);
		vector4f vectorRes = { v.x / aux, v.y / aux, v.z / aux, v.w };
		return vectorRes;
	}

	// Operadores

	// Suma de vectores
	inline vector4f operator+(vector4f v1, vector4f v2) {
		vector4f vectorRes = { v1.x + v2.x, v1.y + v2.y, v1.z + v2.z, 1 };
		return vectorRes;
	}

	// Resta de vectores
	inline vector4f operator-(vector4f v1, vector4f v2) {
		vector4f vectorRes = { v1.x - v2.x, v1.y - v2.y, v1.z - v2.z, 1};
		return vectorRes;
	}

	// Multiplicacion escalar (dot product)
	inline float operator*(vector4f v1, vector4f v2) {
		float res = 0;
		res = v1.x * v2.x + v1.y * v2.y + v1.z * v2.z;
		return res;
	}

	// Multiplicacion vectorial (cross product). OJO, solo se usan las componentes X, Y, Z
	inline vector4f operator^(vector4f v1, vector4f v2) {
		vector4f vectorRes = {
			v1.y* v2.z - v1.z * v2.y,
			v1.z* v2.x - v1.x * v2.z,
			v1.x* v2.y - v1.y * v2.x,
			1
		};
		return vectorRes;
	}

	// METODOS SOBRE ESTRUCTURAS DE TIPO MATRIX4X4F
	// ------------------------------------------------
	
	// Metodo de creacion de matrices de tipo identidad
	inline matrix4x4f make_identity() {
		matrix4x4f matrixRes = {
			.rows = {
				{1,0,0,0},
				{0,1,0,0},
				{0,0,1,0},
				{0,0,0,1}
			}
		};
		return matrixRes;
	}

	// Metodo que crea una matriz de traslacion de N unidades en los ejes X, Y, Z respectivamente
	inline matrix4x4f make_translate(float X, float Y, float Z) {
		matrix4x4f matrixRes = {
			.rows = {
				{1,0,0,X},
				{0,1,0,Y},
				{0,0,1,Z},
				{0,0,0,1}
			}
		};
		return matrixRes;
	}

	// Metodo que crea una matriz de rotacion de N radianes en X, Y, Z respectivamente
	inline matrix4x4f make_rotate(float angleX, float angleY, float angleZ) {
		angleX = toRadians(angleX);
		angleY = toRadians(angleY);
		angleZ = toRadians(angleZ);
		matrix4x4f matrixResX = {
			.rows = {
				{1,0,0,0},
				{0,cos(angleX),-sin(angleX),0},
				{0,sin(angleX),cos(angleX),0},
				{0,0,0,1}
			}
		};
		cout << "MATRIZ DE ROTACION EN X: " << endl;
		cout << matrixResX << endl;

		matrix4x4f matrixResY = {
			.rows = {
				{cos(angleY),0,sin(angleY),0},
				{0,1,0,0},
				{-sin(angleY),0,cos(angleY),0},
				{0,0,0,1}
			}
		};
		cout << "MATRIZ DE ROTACION EN Y: " << endl;
		cout << matrixResY << endl;

		matrix4x4f matrixResZ = {
			.rows = {
				{cos(angleZ),-sin(angleZ),0,0},
				{sin(angleZ),cos(angleZ),0,0},
				{0,0,1,0},
				{0,0,0,1}
			}
		};
		cout << "MATRIZ DE ROTACION EN Z: " << endl;
		cout << matrixResZ << endl;

		matrix4x4f matrixRes = make_identity();
		matrixRes = matrixResX * matrixResY * matrixResZ;
		return matrixRes;
	}

	// Metodo que crea una matriz de escalado de N unidades en los ejes X, Y, Z respectivamente
	inline matrix4x4f make_scale(float X, float Y, float Z) {
		matrix4x4f matrixRes = {
			.rows = {
				{X,0,0,0},
				{0,Y,0,0},
				{0,0,Z,0},
				{0,0,0,1}
			}
		};
		return matrixRes;
	}

	// METODOS DE OPERACIONES
	// ------------------------------------------------

	//Multiplicacion matriz-matriz
	inline matrix4x4f operator*(matrix4x4f m1, matrix4x4f m2) {
		matrix4x4f matrixRes = make_identity();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrixRes.mat2D[i][j] = m1.rows[i] * m2.rows[j];
			}
		}
		return matrixRes;
	}

	//Multiplicacion matriz-vector
	inline vector4f operator*(matrix4x4f m, vector4f v) {
		vector4f res{};
		for (int i = 0; i < 4; i++) {
			res.data[i] = 0;
			for (int j = 0; j < 4; j++) {
				res.data[i] += m.mat2D[i][j] * v.data[j];
			}
		}
		return res;
	}


	//Multiplicacion escalar-matriz
	inline matrix4x4f operator*(float s, matrix4x4f m) {
		matrix4x4f matrixRes = make_identity();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrixRes.mat2D[i][j] = s * m.mat2D[i][j];
			}
		}
		return matrixRes;
	}

	// Suma de matrices
	inline matrix4x4f operator+(matrix4x4f m1, matrix4x4f m2) {
		matrix4x4f matrixRes = make_identity();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrixRes.mat2D[i][j] = m1.mat2D[i][j] + m2.mat2D[i][j];
			}
		}
		return matrixRes;
	}

	// Resta de matrices
	inline matrix4x4f operator-(matrix4x4f m1, matrix4x4f m2) {
		matrix4x4f matrixRes = make_identity();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrixRes.mat2D[i][j] = m1.mat2D[i][j] - m2.mat2D[i][j];
			}
		}
		return matrixRes;
	}

	
	// Transpuesta
	inline matrix4x4f transpose(matrix4x4f m) {
		matrix4x4f matrixRes = make_identity();
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				matrixRes.mat2D[i][j] = m.mat2D[j][i];
			}
		}
		return matrixRes;
	}
	
	// Inversa
	//TODO

	// CLASE RENDER
	// ------------------------------------------------

	class Render {
		// Atributos
	private:
		int ancho;
		int alto;
		char buffer[100][100];

		void cartToIndex(int x, int y, int& row, int& column) {
			int origenX = ancho / 2;
			int origenY = alto / 2;
			row = origenY - y;
			column = origenX + x;
		}

		bool isInside(int x, int y) {
			return x >= -ancho / 2 && x < ancho / 2 && y >= -alto / 2 && y < alto / 2;
		}

	public:
		// Metodos
		Render(int ancho, int alto) {
			this->ancho = ancho;
			this->alto = alto;
			buffer[100][100] = { '0' };
			
		}

		void putPixel(int x, int y) {
			int row, column;
			if (isInside(x, y)) {
				cartToIndex(x, y, row, column);
				buffer[row][column] = '1';
			}
		};

		void resetBuffer() {
			for (int i = 0; i < ancho; i++) {
				for (int j = 0; j < alto; j++) {
					buffer[i][j] = '0';
				}
			}
		}

		void markBorders() {

			for (int i = 0; i < ancho; i++) {
				buffer[0][i] = '2';
				buffer[alto - 1][i] = '2';
			}
			for (int i = 0; i < alto; i++) {
				buffer[i][0] = '3';
				buffer[i][ancho - 1] = '3';
			}
		}

		void draw() const {
			for (int i = 0; i < ancho; i++) {
				for (int j = 0; j < alto; j++) {
					if (buffer[i][j] == '1')
						cout << "*";
					else if (buffer[i][j] == '2')
						cout << "-";
					else if (buffer[i][j] == '3')
						cout << "|";
					else
						cout << " ";
				}
				cout << endl;
			}
		}
	};
};