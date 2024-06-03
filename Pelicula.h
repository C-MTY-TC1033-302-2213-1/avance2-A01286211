/*
Nombre: Sebastian Zaragoza Diaz
Matricula: A01286211
Carrera: IDM
Fecha: 20/05/2024
*/

#ifndef PELICULA_H
#define PELICULA_H
#include "Video.h"

// Clase Pelicula es derivada de Video
class Pelicula : public Video {
    private:
        int oscares;

    public:
    // Metodo Constructor, Default y con Parametros
        Pelicula();
        Pelicula(string _iD, string _titulo, int _duracion, string _genero, double _calificacion, int _oscares);

    // Metodo Modificador
        void setOscares(int _oscares);

    // Metodo de Acceso
        int getOscares();
    
    // Otros Metodos
        string str();

};

#endif /* PELICULA_H */