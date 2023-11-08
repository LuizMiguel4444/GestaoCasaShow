# GestaoCasaShow
Projeto da Disciplina de Programação - 2023.2 

Universidade Federal do Rio Grande do Norte - CERES - Departamento de Computação e Tecnologia.

Projeto desenvolvido para obtenção de conhecimento e nota na disciplina de Programação.

Tema do projeto: Um programa que simula a gestão de uma casa de shows. 

Linguagem utilizada no projeto: C.

Desenvolvido por: Luiz Miguel Santos Silva.


# Informações De Uso:


- Para compilar e rodar o programa, abra o terminal, vá até a pasta do programa e digite o seguinte comando: 'make'. Caso não funcione, cole o comando a seguir: 'gcc -c -Wall atraction/atraction.c; gcc -c -Wall auxiliar/auxiliar.c; gcc -c -Wall buy/buy.c; gcc -c -Wall client/client.c; gcc -c -Wall report/report.c; gcc -c -Wall show/show.c; gcc -c -Wall util/util.c; gcc -c -Wall main.c; gcc -o GestaoCasaShow *.o; ./GestaoCasaShow'. 

Caso ainda não funcione, digite separadamente os seguintes comandos:

gcc -c -Wall atraction/atraction.c
gcc -c -Wall auxiliar/auxiliar.c
gcc -c -Wall buy/buy.c
gcc -c -Wall client/client.c
gcc -c -Wall report/report.c
gcc -c -Wall show/show.c
gcc -c -Wall util/util.c
gcc -o GestaoCasaShow *.o
GestaoCasaShow.exe

Se após isso não funcionar... Mude para Linux urgentemente.

- Para cadastrar uma venda é necessário que já exista ao menos um show cadastrado no sistema.

- Existe um cliente fantasma para vendas sem identificação de cpf. O "cpf" do cliente fantasma é 000.
Use quando necessário.
