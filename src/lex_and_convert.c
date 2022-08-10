#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main() {
    int c;
    FILE* md_file;
    char* input = argv[1];
    int state; /* 0 for string literal, 1 for part of HTML tag, 2 for part of comment */
    char* current_word; /* current word that is being parsed */
    char* current_tag; /* current tag (so it is easier to close the current HTML tag that is open) */
    
    input_file = fopen(input, "r"); /* Open input file */
    
    if(!input_file) { /* fopen returned NULL */
        perror("Could not open input file\n");
        exit(-1);
        return -1;
    }
    
    else {
        int found_word = 0;
        while((c = fgetc(input_file)) != 0) { /* parse through file for HTML and string literals */
            if(isalpha(c) && (state == 0 || state == 1)) /* c is an alphabet, and is thus part of a string literal or markdown-flavored HTML */
                putchar(c); /* put the string back in the file unharmed */
            else if(c == '<') { /* Beginning of tag in markdown */
                state == 1;
                puts("<"); /* Start HTML tag */
            }
            else if(c == '>' && state == 2) { /* End of comment in markdown and character is not part of string */
                /* Not very useful, considering there is no way to open a comment. */
                state == 0; /* reset state (no longer in comment) */
                puts(" -->");
            }
            else if(c == '>') { /* End of HTML tag */
                state == 0; /* reset state (no longer in tag) */
                puts(">");
            }
            /* todo: add syntax highlighting, highlighting, strikethough, bold, italics, other stuff */
        }
        
        rewind(input_file); /* re-open input file for parsing */
        
        while(fscanf(s, "%s", current_word)) {
            if(current_word[1] == current_word[2]) {
                switch(current_word[1]) {
                    case '*':
                        current_tag = "b";
                    case
    }
}
