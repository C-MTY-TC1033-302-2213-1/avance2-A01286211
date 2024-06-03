/*
Nombre: Sebastian Zaragoza Diaz
Matricula: A01286211
Carrera: IDM
Fecha: 20/05/2024
*/

#ifndef SERIE_H
#define SERIE_H
#include "Video.h"
#include "Episodio.h"

class Serie : public Video{
    
    private:
        Episodio episodios[5];
        int cantidad;
    
    public:
    //Metodo Constructor
        Serie();

        Serie(string _iD, string _titulo, int _temporada, string _genero, double _calificacion);
        void calculaDuracion();

    //Metodos Modificadores
        void setEpisodio(int posicion, Episodio episodio);
        void setCantidad(int _cantidad);

    //Metodos de Acceso
        Episodio getEpisodio(int posicion);
        int getCantidad();

    //Otros Metodos
        double calculaPromedio();
        string str();
        void agregaEpisodio(Episodio *episodio);
};

#endif /* SERIE_H */