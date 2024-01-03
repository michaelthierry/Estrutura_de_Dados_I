/**
 * @file constantes.h
 * @author Michael Thierry (michaelthierry86@gmail.com)
 * @brief Constantes usadas
 * @version 0.1
 * @date 2024-01-02
 * 
 * @copyright Copyright (c) 2024
 * 
 */


//Efeitos
#define NONE        "\033[0m"
#define BOLD        "\033[1m"
#define HALFBRIGHT  "\033[2m"
#define UNDERSCORE  "\033[4m"
#define BLINK       "\033[5m"
#define REVERSE     "\033[7m"

//Cores
#define BLACK     "\033[30m"
#define RED       "\033[31m"
#define GREEN     "\033[32m"
#define YELLOW    "\033[33m"
#define BLUE      "\033[34m"
#define MAGENTA   "\033[35m"
#define CYAN      "\033[36m"
#define GRAY      "\033[37m"

// Mensagens
#define SUCESSO BOLD GREEN "@> SUCESSO: " NONE
#define FALHA BOLD RED "@> FALHA: " NONE

// Codigo de Operações
#define INSERIR 1
#define REMOVER 2
