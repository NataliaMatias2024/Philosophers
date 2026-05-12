<h1 align="center">
    <img alt="philosophers" width="200px" src="https://raw.githubusercontent.com/NataliaMatias2024/42-project-badges/main/badges/philosopherse.png">
</h1>

# 🍝 Philosophers - @42SP
**Score:** 100/100 ✅

Este repositório contém a implementação do clássico **Dining Philosophers Problem**, um desafio de programação concorrente do currículo da [42 São Paulo](https://www.42sp.org.br/).
O projeto foca em gerenciar threads e mutexes em C, evitando condições de corrida (*data races*) e impasses (*deadlocks*).

<p align="center">
  <img width="316" height="316" alt="image" src="https://github.com/user-attachments/assets/51eb7ddd-7ad9-45da-aad7-fe42439cadb8" />
</p>

## 🚀 Visão Geral da Arquitetura
O projeto foi modularizado para garantir clareza e eficiência no gerenciamento de múltiplas threads:

>- **`main.c`**: Ponto de controle do projeto. Organiza a validação de argumentos, inicialização de variáveis, criação de threads e limpeza de memória.
>- **`parse.c`**: Lida com o parsing e validação dos argumentos da linha de comando, assegurando que o input é exclusivamente numérico e respeita os limites de segurança.
>- **`init.c`**: Inicializa as variáveis básicas das minhas structs (`t_info`, `t_philo`) e todos os mutexes (forks, write lock, death lock).
>  
>- **`routine.c`**: O coração da simulação. Contém a rotina das threads que os filosofos irão executar durante seu ciclo de vida (take forks, eat, sleep, think). E a lógica inicial de atraso inicial (*staggering*) para estabilizar a simulação.
>- **`monitoring.c`**: Um observador exclusivo que verifica constantemente se algum filósofo morreu ou se a meta de refeições foi atingida.
>- **`threads.c`**: Organiza a criação (`pthread_create`) e sincronização (`pthread_join`) de todos as threads dos filósofos.
>
>- **`time.c`**: Implementação de um `custom_usleep` preciso para contornar as imprecisões do `usleep` padrão do sistema.
>- **`utils.c`**: Funções auxiliares, incluindo a `print_action`, que sincroniza os logs de status para evitar que as mensagens saiam embaralhadas no terminal.
>- **`clean.c`**: Garante a destruição correta de todos os mutexes e a liberação de memória para evitar leaks.

## 🛠️ Tecnologias e Conceitos
<div align="left">
  <img src="https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white" alt="C" />
  <img src="https://img.shields.io/badge/Linux-FCC624?style=for-the-badge&logo=linux&logoColor=black" alt="Linux" />
</div>

> - **Multithreading:** Uso da biblioteca `pthread` para execução das threads dos filósofos.
> - **Mutexes:** Sincronização e proteção de acesso aos recursos compartilhados (garfos e logs).
> - **Concurrecy Control:** Lógica para evitar o "Thundering Herd" e garantir que a simulação seja fluida.

## 📁 Estrutura do Projeto

```bash
.
├── include/           # Header principal (philo.h)
├── src/               # Código-fonte (init, routine, monitoring, etc.)
├── Makefile           # Automação com regras extras de debug
├── README_42.md       # README obrigatório em ingles seguindo os padrões da 42
└── README.md          # Este arquivo
```

## ⚙️ Compilação e Uso
### 1. Compilação
```bash
$ make
```

### 2. Executar: 
```bash
$ ./philo number_of_philosophers time_to_die time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]
```

### 🧩 Legenda dos Argumentos
- **number_of_philosophers**: Numero de filósofos e de garfos (1 to 200).
- **time_to_die**: Tempo (ms) até um filósofo morrer de fome.
- **time_to_eat**: Tempo (ms) que leva para completar uma refeição (segurando dois garfos).
- **time_to_sleep**: Tempo (ms) gasto dormindo.
- **[number_of_times_each_philosopher_must_eat]** (Opcional): A simulação acaba quando **TODOS** os filósofos atingem **no mínimo** esse número de refeições.

## 🚨 Testes de Concorrência e Memória
Incluí regras automáticas no Makefile para facilitar a depuração do código:

- Check Memory Leaks:
```bash
$ make val (Executa com Valgrind)
```
- Check Data Races:
```bash
$ make hel (Executa com Helgrind para análise de threads)
```

## 🧠 Lições Aprendidas

**- Precisão Temporal:** O usleep padrão pode variar muito dependendo do escalonador do SO. O desenvolvimento de um loop de checagem temporal (custom_usleep) foi essencial para passar nos testes rigorosos da 42.

**- Sincronização Atômica:** Entender que até mesmo um printf precisa de um mutex para evitar que as mensagens de diferentes threads se misturem (garbled output) foi um grande aprendizado de concorrência.

**- Prevenção de Deadlocks:** A implementação da hierarquia de garfos e o gerenciamento do estado de morte garantiram que o programa nunca ficasse "travado" esperando por recursos que nunca seriam liberados.

**- Ferramentas de Análise:** O uso intensivo de Helgrind e Valgrind mudou minha forma de depurar código, tornando-me muito mais atenta a acessos simultâneos e liberação de memória.
