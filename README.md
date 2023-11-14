# GestaoCasaShow


Projeto da Disciplina de Programação - 2023.2 

Universidade Federal do Rio Grande do Norte - CERES - Departamento de Computação e Tecnologia.

Projeto desenvolvido para obtenção de conhecimento e nota na disciplina de Programação.

Tema do projeto: Um programa que simula a gestão de uma casa de shows. 

Linguagem utilizada no projeto: C.

Desenvolvido por: Luiz Miguel Santos Silva.


# Informações Para Compilação:


## Linux:

- Para compilar e rodar o programa, abra o terminal, vá até a pasta do programa e digite o seguinte comando: 'make'. Caso não esteja reconhecendo o comando 'make' use o seguinte comando no terminal: 'apt-get install make'. Depois disso, digite o comando 'make' novamente.

- Caso ainda não funcione, cole o comando a seguir: 'gcc -c -Wall *///*.c; gcc -c -Wall main.c; gcc -o GestaoCasaShow *.o; ./GestaoCasaShow'. 

## Replit:

- Abra o site, crie um arquivo de linguagem C, vá no Shell (ao lado do console), clone o repositório (git clone https://github.com/LuizMiguel4444/GestaoCasaShow.git), vá até a pasta (cd GestaoCasaShow) e digite o comando 'make' na linha de comando do Shell. 

- É recomendável maximizar/expandir a tela do Shell para que haja uma melhor expeciência ao utilizar o programa.

## Windows (não recomendável, pois ocorrem erros de otimização e layout):

- Para compilar e rodar o programa, abra o terminal, vá até a pasta do programa e digite os seguintes comandos em sequência:

1.  gcc -c -Wall *\\\*.c main.c
2.  gcc -o GestaoCasaShow *.o
3.  .\GestaoCasaShow

- Se após isso ainda não funcionar... Mude para Linux URGENTEMENTE!

# Informações Para Uso:

- Para cadastrar uma venda é necessário que já exista ao menos um show cadastrado no sistema.

- Existe um cliente fantasma para vendas sem identificação de cpf. O "cpf" do cliente fantasma é 000.
Use quando necessário.