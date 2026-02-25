#ifndef USUARIO_HPP
#define USUARIO_HPP

#include <string>

class Usuario
{
private:
    int id;
    std::string nome;
public:
    Usuario(int id, std::string nome);
    std::string getNome() const;
    int getId() const;
};


#endif