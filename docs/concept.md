# Como fazer esse troço

Niveis de memória, onde o último é equivalente a memória principal e todos os outros são cache.

Processador que simula loads e stores.

Cada memória deve ter
- nome 
- latência (em ciclos)
- associatividade 
- tamanho de cada conjunto associativo
- tamanho da linha 
- política de escrita.
- as linhas



A memória principal só tem nome e latência.

O processador manda um sinal para a hierarquia, seja load ou write, com um endereço de procura. esse endereço é procurado na cache, se não for achado é uma 'cache miss', se for encontrado é uma 'cache hit'.