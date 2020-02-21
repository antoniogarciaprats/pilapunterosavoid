#ifndef PILAVOID
#define PILAVOID

typedef void *pila;

pila p_nueva ( int tam );
int p_vacia ( pila p );
void p_mete ( pila p, void *e );
void p_saca ( pila p, void *e );
void p_dest ( pila* p );
pila p_copy ( pila p );

#endif

