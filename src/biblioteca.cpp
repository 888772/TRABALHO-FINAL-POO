#include "../include/biblioteca.hpp"
#include <iostream>
#include <cstdio>
#include "../include/livro.hpp"

// Armazena um ponteiro para livro no vector<Livro*> livros
void Biblioteca::adicionarLivro(Livro* livro) {
    livros.push_back(livro);
}

void Biblioteca::adicionarUsuario(Usuario* usuario){
    usuarios.push_back(usuario);
}

bool Biblioteca::emprestarLivro(Livro* livro, Usuario* usuario, const std::string& data) {
    if (livro->isDiponivel())
    {
        emprestimos.push_back(new Emprestimo(livro, usuario, true, data));
        return true;
    }
    return false;
}

bool Biblioteca::devolverLivro(Livro* livro, const std::string& data)
{
    for (size_t i = 0; i < emprestimos.size(); ++i) {
        Emprestimo* emp = emprestimos[i];
        if (emp->getLivro() == livro && emp->isAtivo()) {
            emp->finalizar(data);
            return true;
        }
    }
    return false;
}

void Biblioteca::listarLivros() const {
    for (size_t i = 0; i < livros.size(); ++i) {
        const Livro* livro = livros[i];
        std::cout << "==================" << std::endl;
        std::cout << "Livro: " << livro->getTitulo() << std::endl;
        std::cout << "Autor: " << livro->getAutor() << std::endl;
        std::cout << "ID: " << livro->getId() << std::endl;
        std::cout << "Ano: " << livro->getAno() << std::endl;
        std::cout << "==================" << std::endl;
    }
}

void Biblioteca::listarUsuarios() const {
    for (size_t i = 0; i < usuarios.size(); ++i) {
        const Usuario* usuario = usuarios[i];
        std::cout << "==================" << std::endl;
        std::cout << "Usuarios: " << usuario->getNome() << std::endl;
        std::cout << "ID: " << usuario->getId() << std::endl;
        std::cout << "==================" << std::endl;
    }
}

void Biblioteca::listarLivrosEmprestados() const{
    bool encontrou = false;
    
    // Percorrer o vetor de empréstimos
    for (size_t i = 0; i < emprestimos.size(); ++i) {
        // Verificar se o empréstimo ainda está ativo
        if (emprestimos[i]->isAtivo()) {
            encontrou = true;
            // Pegar o livro e o usuário através do objeto Emprestimo
            Livro* livro = emprestimos[i]->getLivro();
            Usuario* usuario = emprestimos[i]->getUsuario();
            std::cout << "====================================" << std::endl;
            std::cout << "Livro: " << livro->getTitulo() << std::endl;
            std::cout << "ID: " << livro->getId() << std::endl;
            std::cout << "Autor: " << livro->getAutor() << std::endl;
            std::cout << "Emprestado para: " << usuario->getNome() << "ID: " << usuario->getId() << std::endl;
            std::cout << "====================================" << std::endl;
        }
    }

    if (!encontrou) {
        std::cout << "Nao ha livros emprestados" << std::endl;
    }
}

Livro* Biblioteca::buscarLivroPorId(int id) {
    for (size_t i = 0; i < livros.size(); ++i) {
        // Verifica se o ID do livro atual é igual ao ID procurado
        if (livros[i]->getId() == id) {
            return livros[i]; // Retorna o ponteiro do livro encontrado
        }
    }
    return nullptr; // Retorna NULL se não encontrar nada após percorrer tudo
    // Retorna NULL, porque como a minha versão do MINGW é antiga, não tinha nullptr
}

Usuario* Biblioteca::buscarUsuarioPorId(int id) {
    for (size_t i = 0; i < usuarios.size(); ++i) {
        // Verifica se o ID do usuário atual é igual ao ID procurado
        if (usuarios[i]->getId() == id) {
            return usuarios[i]; // Retorna o ponteiro do usuário encontrado
        }
    }
    return nullptr; // Retorna NULL, porque como a minha versão do MINGW é antiga, não tinha nullptr
}


// destrutor (Liberar a memoria)
Biblioteca::~Biblioteca() {
    for (size_t i = 0; i < livros.size(); ++i) delete livros[i];
    for (size_t i = 0; i < usuarios.size(); ++i) delete usuarios[i];
    for (size_t i = 0; i < emprestimos.size(); ++i) delete emprestimos[i];
}