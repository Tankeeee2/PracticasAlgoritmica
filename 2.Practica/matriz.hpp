#ifndef MATRIZ_HPP
#define MATRIZ_HPP

#include <vector>
#include <cassert>
#include <cmath>
#include <iostream>
#include <iomanip>
#include <cstdlib>

using namespace std;
class Matriz 
{
 
    private:
    
        vector < vector < double > > _m;
        unsigned int _f, _c;
    
    public:
    
        Matriz(unsigned int f, unsigned int c) : _f(f), _c(c)
        {
            for (unsigned int i = 0; i < _f; i++) {
                vector<double> nueva_fila(c);
                _m.push_back(nueva_fila);
            }
        };

        Matriz(){};
        ~Matriz(){};  // Destructor de la clase

        unsigned int getFilas() const
        {
            return _f;
        };

        unsigned int getColumnas() const
        {
            return _c;
        };

        void setElemento(unsigned int i, unsigned int j, double x);
        double getElemento(unsigned int i, unsigned int j) const;
        void rellenarMatrizAleatoria();
        void rellenarMatrizUnidad();
    
        friend ostream& operator << (ostream &salida, Matriz &z); //sobrecarga del operador <<
        //friend istream& operator >> <> (istream &entrada, Matriz &z); //sobrecarga del operador >>
        friend bool operator  ==(const Matriz &x, const Matriz &y); //sobrecarga al operador == para comparar matrices
        friend Matriz operator +(const Matriz &x, const Matriz &y); //sobrecarga al operador + para sumar matrices
        friend Matriz operator  *(const Matriz &x, const Matriz &y); //sobrecarga al operador * para multiplicar matrices
        Matriz potencia(const unsigned int &n)const; //Potencia sin divide y vencerás.
        Matriz potenciaDyV1(const unsigned int &n)const; //Potencia usando DyV versión 1.
        Matriz potenciaDyV2(const unsigned int &n)const;
};

void Matriz::setElemento(unsigned int i, unsigned int j, double x)
{
    assert(i < _f and j < _c);
    _m[i][j] = x;
};

double Matriz::getElemento(unsigned int i, unsigned int j) const
{
    assert(i < _f and j < _c);
    return _m[i][j];
};


void Matriz::rellenarMatrizAleatoria()
{
    assert(_f > 0 and _c > 0);
    double signo = -1.0;
    
    for (unsigned int i = 0; i < getFilas(); i++)
        for (unsigned int j = 0; j < getColumnas(); j++)
        {
            if (rand() % 2 == 1)
                signo = -signo;
            setElemento(i, j, signo * (signo * (((1.0 * std::rand()) / RAND_MAX) * 0.000001) + 1.0));
        }
};

void Matriz::rellenarMatrizUnidad()
{
    assert(_f == _c); // Una matriz identidad debe ser cuadrada
    for (unsigned int i = 0; i < _f; i++) {
        for (unsigned int j = 0; j < _c; j++) {
            if (i == j) {
                setElemento(i, j, 1.0);
            } else {
                setElemento(i, j, 0.0);
            }
        }
    }
};

ostream &operator << (ostream &salida, Matriz &z)
{
    salida.setf(ios::fixed);
    salida.precision(4);    
 
    for (unsigned int i = 0; i < z.getFilas(); i++)
    {
        for (unsigned int j = 0; j < z.getColumnas() ; j++) 
            salida << setw(20) << z.getElemento(i, j) << " ";
        salida << "\n";
    }
    return salida;
};

Matriz operator + (const Matriz &x, const Matriz &y)
{
 
    assert(x.getFilas() == y.getFilas() and x.getColumnas() == y.getColumnas());
 
    Matriz suma(x.getFilas(), x.getColumnas());

    for (unsigned int i = 0; i < x.getFilas(); i++)
        for (unsigned int j = 0; j < x.getColumnas() ; j++) 
            suma.setElemento(i, j, x.getElemento(i, j) + y.getElemento(i, j)); 
    
    return suma;
 
};

Matriz operator * (const Matriz &x, const Matriz &y)
{
    assert(x.getColumnas() == y.getFilas());

    Matriz resultado(x.getFilas(), y.getColumnas());

    for (unsigned int i = 0; i < x.getFilas(); i++) {
        for (unsigned int j = 0; j < y.getColumnas(); j++) {

            double suma = 0.0;
            for (unsigned int k = 0; k < x.getColumnas(); k++) {
                suma += x.getElemento(i, k) * y.getElemento(k, j);

            }

            resultado.setElemento(i, j, suma);
        }
    }

    return resultado;
};

Matriz Matriz::potencia(const unsigned int &n)const
{
    //Completar

};


Matriz Matriz::potenciaDyV1(const unsigned int &n)const
{
    //Completar
};

Matriz Matriz::potenciaDyV2(const unsigned int &n)const
{
    //Completar
};

bool operator == (const Matriz &x, const Matriz &y)
{
 
    assert(x.getFilas() == y.getFilas() and x.getColumnas() == y.getColumnas());
 
    for (unsigned int i = 0; i < x.getFilas(); i++)
        for (unsigned int j = 0; j < x.getColumnas() ; j++)
            if (fabs(x.getElemento(i, j)- y.getElemento(i, j)) > 0.0000001)
                return false; 
    
    return true;
};


#endif



