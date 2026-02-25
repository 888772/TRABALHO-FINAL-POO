#include "../include/usuario.hpp"
#include <iostream>
#include <string>

Usuario::Usuario(int id, std::string nome): id(id), nome(nome) {}

std::string Usuario::getNome() const{
    return nome;
}

int Usuario::getId() const{
    return id;
}