#include <iostream>
#include <string>
#include <cstdlib>

#include "include/biblioteca.hpp"
#include "include/livro.hpp"
#include "include/usuario.hpp"

// compilar g++ main.cpp src/biblioteca.cpp src/emprestimo.cpp src/livro.cpp src/usuario.cpp -o biblioteca.exe

int contador_livro = 0;
int contador_usuario = 0;
// usei esse metodo porque me senti mais seguro de utilizar ele ;)

int main() {
    Biblioteca biblioteca;

    int opcao;

    do {
        std::cout << "\n===== SISTEMA DE BIBLIOTECA =====" << std::endl;
        std::cout << "1 - Adicionar livro" << std::endl;
        std::cout << "2 - Adicionar usuario" << std::endl;
        std::cout << "3 - Listar livros" << std::endl;
        std::cout << "4 - Emprestar livro" << std::endl;
        std::cout << "5 - Devolver livro" << std::endl;
        std::cout << "6 - Listar livros emprestados" << std::endl;
        std::cout << "7 - Listar usuarios" << std::endl;
        std::cout << "0 - Sair" << std::endl;
        std::cout << "Escolha: ";
        std::cin >> opcao;
        std::cin.ignore(); // limpa buffer
        std::cout << "================================\n";

        if (opcao == 1) {
            int id, ano;
            std::string titulo, autor;
            contador_livro++;
            // std::cout << "ID do livro: ";
            // std::cin >> id;
            // std::cin.ignore();
            id = contador_livro;

            std::cout << "Titulo: ";
            std::getline(std::cin, titulo);

            std::cout << "Autor: ";
            std::getline(std::cin, autor);

            std::cout << "Ano: ";
            std::cin >> ano;
            // if (!biblioteca.buscarLivroPorId(id))
            // {
            biblioteca.adicionarLivro(new Livro(id, titulo, autor, ano));
            std::cout << "Livro adicionado com sucesso!" << std::endl;
            //}
            // else{
            //     std::cout << "O livro ja existe\n";
            // }
        }

        else if (opcao == 2) {
            int id;
            std::string nome;
            contador_usuario++;
            id = contador_usuario;

            // std::cout << "ID do usuario: ";
            // std::cin >> id;
            // std::cin.ignore();

            std::cout << "Nome: ";
            std::getline(std::cin, nome);
            
            // if (!biblioteca.buscarUsuarioPorId(id))
            // {
            biblioteca.adicionarUsuario(new Usuario(id, nome));
            std::cout << "Usuario adicionado com sucesso!" << std::endl;
            //}
        }

        else if (opcao == 3) {
            biblioteca.listarLivros();
        }

        else if (opcao == 4) {
            int idLivro, idUsuario;
            std::string data;

            std::cout << "ID do livro: ";
            std::cin >> idLivro;

            std::cout << "ID do usuario: ";
            std::cin >> idUsuario;
            std::cin.ignore();

            std::cout << "Data do emprestimo (xx/xx/xxxx): ";
            std::getline(std::cin, data);

            Livro* livro = biblioteca.buscarLivroPorId(idLivro);
            Usuario* usuario = biblioteca.buscarUsuarioPorId(idUsuario);

            if (livro and usuario) {
                if (biblioteca.emprestarLivro(livro, usuario, data)) {
                    std::cout << "Emprestimo realizado!" << std::endl;
                } else {
                    std::cout << "Livro indisponivel." << std::endl;
                }
            } else {
                std::cout << "Livro ou usuario nao encontrado." << std::endl;
            }
        }

        else if (opcao == 5) {
            int idLivro;
            std::string data;

            std::cout << "ID do livro: ";
            std::cin >> idLivro;
            std::cin.ignore();

            std::cout << "Data da devolucao (xx/xx/xxxx): ";
            std::getline(std::cin, data);

            Livro* livro = biblioteca.buscarLivroPorId(idLivro);

            if (livro) {
                if (biblioteca.devolverLivro(livro, data)) {
                    std::cout << "Livro devolvido com sucesso!" << std::endl;
                } else {
                    std::cout << "Emprestimo nao encontrado." << std::endl;
                }
            } else {
                std::cout << "Livro nao encontrado." << std::endl;
            }
        }
        else if (opcao == 6)
        {
            biblioteca.listarLivrosEmprestados();
        }
        else if (opcao == 7)
        {
            biblioteca.listarUsuarios();
        }
        

    } while (opcao != 0);

    std::cout << "Encerrando sistema..." << std::endl;

    system("pause");
    return 0;
}
