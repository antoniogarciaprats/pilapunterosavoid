#include <stdlib.h>
#include <stdio.h>
#include "pilavoid.h"

struct p_ele {
	void* val;
	struct p_ele* sig;
}

struct tpila {
	int tam;
	struct p_ele* p;
}


pila p_nueva ( int tam ) {

	struct tpila* nueva;
	
	nueva = (struct tpila* ) malloc ( sizeof ( struct tpila ) );
	if ( !nueva ) {
		fprintf ( stderr, "p_nueva: No hay suficiente memoria\n" );
		exit (1);
	}
	
	nueva->tam = tam;
	nueva->p = NULL;
	
	
	return nueva;

}


int p_vacia ( pila p ) {

	if ( !p ) {
		fprintf ( stderr, "p_vacia: La pila  no existe\n" );
		exit (1);
	}
	
	return ((struct tpila*)p)->p == NULL;
	
}

void p_dest ( pila* p ) {

	struct p_ele* viejo;
	
	if ( !*p ) {
		fprintf ( stderr, "p_dest: La pila  no existe\n" );
		exit (1);
	}
	
	while ( ((struct tpila* )(*p))->p ) {
	
		viejo = ((struct tpila* ) (*p))->p;
		((struct tpila* ) (*p))->p = viejo->sig;
		free ( viejo->val );
		free ( viejo );
	
	}
	
	free ( *p );
	*p = NULL;
	
}

void p_mete ( pila p, void *e ) {

	struct p_ele* nuevo;
	
	if ( !*p ) {
		fprintf ( stderr, "p_mete: La pila no existe.\n" );
		exit (1);
	}
	
	nuevo = (struct p_ele*) malloc (sizeof (struct p_ele ));
	if ( !nuevo ) {
		fprintf ( stderr, "p_mete: no hay suficiente memoria|n");
		exit(1);
	}
	
	nuevo->val ( void* ) malloc (( struct tpila*)p)->tam);
	if ( !nuevo->val ) {
		fprintf ( stderr, "p_mete: no hay suficiente memoria|n");
		exit(1);
	}

	memcpy ( nuevo->val, e, (( struct tpila*)p)->tam);
	nuevo->sig = (( struct tpila*)p)->p;
	(( struct tpila*)p)->p = nuevo;

}


void p_saca ( pila p, void *e ) {
	
		struct p_ele* viejo;
		
		if ( !*p ) {
			fprintf ( stderr, "p_saca: La pila no existe.\n" );
			exit (1);
		}
		
		if ( p_vacia ( p ) ) {
			fprintf ( stderr, "p_saca: La pila está vacía.\n" );
			exit (1);
		}
		
		viejo = (( struct tpila*)p)->p;
		memcpy ( e, viejo->val, (( struct tpila*)p)->tam );
		(( struct tpila*)p)->p = viejo->sig;
		free ( viejo->val );
		free ( viejo );

}

pila p_copy ( pila p ) {
	
	pila b;
	struct p_ele *corr, *nuevo, *corrp;
	
	if ( !*p ) {
		fprintf ( stderr, "p_copy: La pila no existe.\n" );
		exit (1);
	}
	
	 b = p_nueva ( (( struct tpila*)p)->tam );
	 if ( !p_vacia ( p ) ) {
		 nuevo = ( struct p_ele * ) malloc ( sizeof ( struct p_ele ));
		 if ( !nuevo ) {
			fprintf ( stderr, "p_copy: no hay memoria suficiente.\n" );
			exit (1);
		 }
		 nuevo->val  = (void *) malloc ( struct tpila* )p)->tam);
		 if ( !nuevo->val ) {
			fprintf ( stderr, "p_copy: no hay memoria suficiente.\n" );
			exit (1);
		 }
		 
		 memcpy ( nuevo->val, ((struct tpila *)p)->p->val, ((struct tpila *)p)->tam );
		 ((struct tpila *)b)->p = corr = nuevo;
		 corrp = ((struct tpila *)p)->p->sig;
		 
		 while ( corrp ) {
			nuevo = ( struct p_ele* ) malloc ( sizeof ( struct p_ele ));
			if ( !nuevo ){
				fprintf ( stderr, "p_copy: no hay memoria suficiente.\n" );
				exit (1);
			}
			memcpy ( nuevo->val, corrp->val, ((struct tpila* )p)->tam );
			corr = corr->sig =  nuevo;
			corrp = corrp->sig;
		}
		 
		 corrp->sig = NULL;
		 
	 }
		 
	 return b; 
	
	
}
