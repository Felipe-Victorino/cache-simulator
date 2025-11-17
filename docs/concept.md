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

from wikipedia:

## To place a block in the cache

    - The set is determined by the index bits derived from the address of the memory block.
    - The memory block is placed in an available cache line in the set identified, and the tag is stored in the tag field associated with the line. If all the cache lines in the set are occupied, then the new data replaces the block identified through the replacement policy.

## To locate a word in the cache

    - The set is determined by the index bits derived from the address of the memory block.
    - The tag bits are compared with the tags of all cache lines present in selected set. If the tag matches any of the cache lines, it is a cache hit and the appropriate line is returned. If the tag does not match any of the lines, then it is a cache miss and the data is requested from next level in the memory hierarchy.