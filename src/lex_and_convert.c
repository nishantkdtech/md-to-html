#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <fcntl.h>
#include <errno.h>
#include <unistd.h>
#include <string.h>

int main() {
    int c;
    FILE* input_file; /* Markdown file */
    char* input = argv[1];
    int state; /* 0 for string literal, 1 for part of HTML tag, 2 for part of comment */
    char* current_word; /* current word that is being parsed */
    char* current_tag; /* current tag (so it is easier to close the current HTML tag that is open) */
    char* temp_array;
    int taglen; /* strlen for current_tag */
    
    input_file = fopen(input, "r"); /* Open input file */
    
    if(!input_file) { /* fopen returned NULL */
        perror("Could not open input file\n");
        exit(-1);
        return -1;
    }
    
    else {
        int found_word = 0;

        /* Copy HTML tags that already exist in the base document */
        while((c = fgetc(input_file)) != EOF) { /* parse through file for HTML and string literals */
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
        
        /* Convert markdown into HTML */
        while(fscanf(s, "%s", current_word)) {
            taglen = strlen(current_word)
            if(current_word[1] == current_word[taglen - 1]) {
                switch(current_word[1]) {
                    ASTERISK:case '*': /* bold and/or italic */
                        if(current_word[2] == current_word[1])
                            current_tag = "b";
                            if(current_word[2] == current_word[1] && current_word[3] == current_word[1]) { 
                                current_tag = "b i"; /* bold and italic */
                            }
                        /* because what kind of a sick mind would create an empty italic string? */
                        else
                            current_tag = "i";
                        break;
                    case '_': /* another way to embolden or italicize */
                        goto ASTERISK;
                    case '~': /* strikethrough */
                        current_tag = "s";
                        break;
                    case '`': /* code (inline and block) */
                        if(current_word[1] == current_word[2]) { /* code block */
                            current_tag = "code pre"; /* code-ifies and preserves formatting */
                            break;
                        }
                        current_tag = "code";
                        break;
                    case '\\': /* escape character is backslash */
    }
}

void copy_string_part(char* source, char* destination, int begin, int end) { /* copy a part of the string */
    int i = end - begin + 1;
    for(int j = 0; j <= i; j++)
        destination[begin + j] =  
}