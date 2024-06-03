/*
Nombre: Sebastian Zaragoza Diaz
Matricula: A01286211
Carrera: IDM
Fecha: 20/05/2024
*/

#ifndef EPISODIO_H
#define EPISODIO_H

#include "Video.h"

class Episodio{
    private:
        string titulo;
        int temporada;
        int calificacion;

    public:
        // Metodos Constructores
        Episodio();
        Episodio(string _titulo, int _temporada, int _calificacion);

        // Metodos Modificadores
        void setTitulo(string _titulo);
        void setTemporada(int _temporada);
        void setCalificacion(int _calificacion);

        // Metodos de Acceso
        string getTitulo();
        int getTemporada();
        int getCalificacion();

        // Otros Metodos
        string str();

};

#endif // EPISODIO_H