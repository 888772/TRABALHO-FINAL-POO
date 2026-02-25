#ifndef EMPRESTIMO_HPP
#define EMPRESTIMO_HPP

#include <string>
#include "livro.hpp"
#include "usuario.hpp"

class Emprestimo {
private:
    Livro* refLivro; //ponteiro para objeto
    Usuario* refUsuario; //ponteiro para objeto
    bool ativo;
    std::string dataEmprestimo;
    std::string dataDevolucao;

public:
    Emprestimo(Livro* livro, Usuario* usuario, bool ativo, const std::string& dataEmprestimo);

    void finalizar(const std::string& dataDevolucao);
    bool isAtivo() const;

    Livro* getLivro() const;
    Usuario* getUsuario() const;
};

#endif
