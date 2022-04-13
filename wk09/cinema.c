
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "cinema.h"

#define MAX_STR_LENGTH 256

#define SUCCESS 0
#define NOT_FOUND 1

#define TRUE 1
#define FALSE 0
struct movie {
    char title[MAX_STR_LENGTH];
    int length;
    double rating;

    struct movie *next; // pointer to the next movie
};

struct genre {
    char name[MAX_STR_LENGTH];

    struct movie *movies; // pointer to the start of the list of movies in that genre
    struct genre *next; // pointer next genre
};

struct cinema {
    struct genre *genres; // pointer to the start of the genres list
};

struct cinema *create_cinema() {
    struct cinema *new = malloc(sizeof(struct cinema));
    new->genres = NULL;

    return new;
}

// insert genre at HEAD (start) of the list of genres
void add_genre(
  struct cinema *cinema, char *genre_name) {
  
    struct genre *new = malloc(sizeof(struct genre));
    strcpy(new->name, genre_name);
    new->movies = NULL;
    new->next = NULL;

    new->next = cinema->genres;
    cinema->genres = new;
}

struct movie *create_movie(char *movie_name,
    int length,
    double rating) {
    
    struct movie *new_movie = malloc(sizeof(struct movie));
    strcpy(new_movie->title, movie_name);
    new_movie->length = length;
    new_movie->rating = rating;
    new_movie->next = NULL;
    return new_movie;
}


// Add movie to HEAD of the list of movies
int add_movie(
    struct cinema *cinema,
    char *genre_name,
    char *movie_name,
    int length,
    double rating) {
    
    // Create the new movie
    struct movie *new_movie = create_movie(movie_name, length, rating);
    
    // Find genre to add to
    struct genre *curr_genre = cinema->genres;
    while (curr_genre != NULL && strcmp(curr_genre->name, genre_name) != 0) {
        curr_genre = curr_genre->next;
    }
    
    // genre does not exist
    if (curr_genre == NULL) {
        printf("Genre doesn't exist!\n");
        return NOT_FOUND;
    }
    
    // add movie to start of genres!
    new_movie->next = curr_genre->movies;
    curr_genre->movies = new_movie;
    

    return SUCCESS;
}

void print_genre(
  struct cinema *cinema, char *genre_name) {
   // Find genre to print
    struct genre *curr_genre = cinema->genres;
    while (curr_genre != NULL && strcmp(curr_genre->name, genre_name) != 0) {
        curr_genre = curr_genre->next;
    }
    
    // genre does not exist
    if (curr_genre == NULL) {
        printf("Genre doesn't exist!\n");
        return;
    }
  
    // loop through movie list and print details
    struct movie *curr_movie = curr_genre->movies;
    while (curr_movie != NULL) {
    
        printf("%s, %lf/100 (%d minutes)\n", curr_movie->title, curr_movie->rating, curr_movie->length);
        curr_movie = curr_movie->next; 
    }
  
}
