#ifndef DEBUG_H
#define DEBUG_H

#define DEBUG

#ifdef DEBUG
#define dprint(x) std::cout << x << std::endl;
#else 
#define dprint(x) do{} while(0)
#endif

#endif