
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STR_LENGTH 256
#define SUCCESS 0
#define NOT_FOUND 1


struct cinema *create_cinema();

void add_genre(
  struct cinema *cinema, char *genre_name);

struct movie *create_movie(char *movie_name,
    int length,
    double rating) ;


int add_movie(
    struct cinema *cinema,
    char *genre_name,
    char *movie_name,
    int length,
    double rating) ;

void print_genre(
  struct cinema *cinema, char *genre_name) ;
