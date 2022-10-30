# REPORT: Team 100 palavras (Trabalho 2)
Lucas Marins Ramalho de Lima  
Maria Luísa Riolino Guimarães  
Nicolas Soares Martins  

14 de agosto de 2022

---

- [Resumo da abordagem final](https://github.com/ufjf-dcc-josecamata/dcc012b-trab2-team-100-palavras/blob/main/REPORT.md#resumo-da-abordagem-final)  
- [Divisão de tarefas e desenvolvimento do trabalho](https://github.com/ufjf-dcc-josecamata/dcc012b-trab2-team-100-palavras/blob/main/REPORT.md#divis%C3%A3o-de-tarefas-e-desenvolvimento-do-trabalho)  
- [Principais desafios e mudanças de planos](https://github.com/ufjf-dcc-josecamata/dcc012b-trab2-team-100-palavras/blob/main/REPORT.md#principais-desafios-e-mudan%C3%A7as-de-planos)  
- [Resultados do teste das taxas de conversão](https://github.com/ufjf-dcc-josecamata/dcc012b-trab2-team-100-palavras/blob/main/REPORT.md#resultados-dos-testes)

## Resumo da abordagem final

Para a criação de um índice remissivo, implementamos uma Árvore de Busca Digital simples (Trie), que armazena no último nó correspondente à palavra as linhas nas quais se encontram suas ocorrências. O armazenamento é feito em um vector de inteiros. 

Na escrita dos arquivos finais, utilizamos estruturas criadas na Versão 1 deste trabalho para incluir as 50 palavras mais frequentes em um vector de hashVec - que é um par (contador, palavra) - e, posteriormente, ordená-lo em ordem alfabética. O vetor de linhas mencionado anteriormente é um atributo privado da classe TrieNode, e é acessado pela busca (na classe Trie, friend class de TrieNode), da palavra.

Para os testes de compressão, utilizamos o Algoritmo de Compressão de Huffman, mas encontramos certa dificuldade em alcançar os resultados esperados, como desenvolveremos mais na sessão "Principais Desafios e Mudanças de Planos".

## Divisão de tarefas e desenvolvimento do trabalho

Durante todo o período de elaboração deste trabalho, o grupo tentou dividir as tarefas entre os membros e, em alguns momentos, se reuniu para analisar estratégias e implementações. A parte final do código foi feita em conjunto, em uma chamada em grupo, utilizando o Live Share.

De forma simplificada, a divisão das tarefas foi a seguinte: 

- Marins: algoritmo de Huffman e respectivos testes unitários
- Maria: correção de inconsistências, índice remissivo e finalização do código
- Nicolas: implementação inicial da Trie, respectivos testes unitários e finalização do código

## Principais desafios e mudanças de planos

### Escolha da ABD
Inicialmente, planejamos utilizar uma Árvore Ternária de Busca para criar o índice remissivo. Porém, encontrarmos dificuldades na implementação da Árvore e suas rotinas, diminuindo o fluxo do dessenvolvimento do TAD.
Optamos por trocarmos a implementação para uma ABD mais simples, sendo a esta a implementação final com a Trie Básica.

### Algoritmo de Huffman
Para a implementação da compactação de dados utilizamos o código de Huffman, seguindo o que foi passado em aula e referências da internet. Como orientado, o algoritmo criado realiza a compressão em formato de texto, escrevendo os dígitos "0" e "1" em arquivos.

Os testes unitários demonstraram que a compactação estava funcionando corretamente, mas por algum tempo o nosso cálculo das taxas de compressão indicava que o arquivo de saída possuía tamanho maior. Por fim, realizamos o cálculo considerando o número de caracteres no arquivo de entrada e o número de bytes no arquivo de saída e finalmente obtivemos os resultados esperados, como exposto a seguir.

## Resultados dos testes 

### Cálculo das Taxas de Compressão

Além dos testes implementados na Versão 1 deste trabalho, incluímos, para esta versão, testes unitários da Trie, testes unitários de compressão e testes gerais.

Listamos abaixo os valores encontrados para a taxa de compressão de cada um dos arquivos inseridos na pasta de inputs.
O cálculo foi feito por meio da seguinte fórmula:

> inC -> entrada (qtd de caracteres no arquivo de entrada)
> outC -> saída (qtd de caracteres no arquivo de saída / 8)    
> TAXA DE COMPRESSÃO = ((inC - outC)/inC) * 100  

O código para execução deste teste pode ser encontrado em test12.cc.

> IRACEMA = 36.5145%;  
> ORPHEUS = 31.2039%;  
> O PRIMO BAZÍLIO = 38.287%;  
> OS JESUÍSTAS E O ENSINO = 38.146%;  
> NO PAIZ DOS YANKEES = 36.3699%;  
> O TRISTE FIM DE POLYCARPO QUARESMA = 38.8218%;  
> CINCO MINUTOS = 35.9568%;  
> OS LUSIADAS = 30.0965%;  
> MEMORIAS POSTUMAS DE BRAZ CUBAS = 40.5245%;  
> RECEITA DE BOLO = 14.2708%;  
> DOM CASMURRO = 39.6913%;