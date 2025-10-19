#include <stdlib.h>
#include <stdio.h>
#include "re.h"

arena_t create_arena(int size) { 
  arena_t arena = malloc(sizeof(struct arena));
  arena -> size = size;
  arena -> current = 0;
  arena -> elts = malloc(size * sizeof(Regexp));

  /* TODO */
  return NULL;
}

void arena_free(arena_t a) { 
  /* TODO */
  free(a->elts);
  free(a);
}

Regexp *re_alloc(arena_t a) { 
  /* TODO */
  if (a->size == a->current){
    return NULL;
  }else{
    return &a->elts[a->current++];
    
  }
}

Regexp *re_chr(arena_t a, char c) { 
  /* TODO */

  if (a->size == a->current){
    return NULL;
  }else{
    Regexp* next= &a->elts[a->current++];
    next ->type = CHR;
    next ->data.chr = c;
    return next;
  }
}

Regexp *re_alt(arena_t a, Regexp *r1, Regexp *r2) { 
  /* TODO */
  if (a->size == a->current){
    return NULL;
  }else{
    Regexp* next= &a->elts[a->current++];
    next ->type = ALT;
    next ->data.pair.fst = r1;
    next ->data.pair.snd = r2;
    return next;
  }
}

Regexp *re_seq(arena_t a, Regexp *r1, Regexp *r2) { 
  /* TODO */

  if (a->size == a->current){
    return NULL;
  }else{
    Regexp* next= &a->elts[a->current++];
    next ->type = SEQ;
    next ->data.pair.fst = r1;
    next ->data.pair.snd = r2;
    return next;
  }
}

int re_match(Regexp *r, char *s, int i) { 

  /* TODO */
  return -1;
}
/*
for CHR, if s[i] = it, then return i+1, otherwise return -1
for SEQ (concatenation of fst then snd), recursively match fst starting at i then recursively match snd starting at j 
If either fail return -1, otherwise return k
for ALT, resurively try fst starting at i. if it succeeds, return this 
otherwise try snd
if both fail, return -1

 */



void re_print(Regexp *r) { 
  if (r != NULL) { 
    switch (r->type) {
    case CHR: 
      printf("%c", r->data.chr);
      break;
    case SEQ:
      if (r->data.pair.fst->type == ALT) { 
	printf("(");
	re_print(r->data.pair.fst);
	printf(")");
      } else {
	re_print(r->data.pair.fst);
      }
      if (r->data.pair.snd->type == ALT) { 
	printf("(");
	re_print(r->data.pair.snd);
	printf(")");
      } else {
	re_print(r->data.pair.snd);
      }
      break;
    case ALT:
      re_print(r->data.pair.fst);
      printf("+");
      re_print(r->data.pair.snd);
      break;
    }
  } else { 
    printf("NULL");
  }
}    


      
  
