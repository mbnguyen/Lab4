//
//  JuliusCaesar2.c
//  System Level Assignments
//
//  Created by Minh Nguyen on 7/12/20.
//  Copyright © 2020 Minh Nguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    if (argc != 2) {
        printf("Please provide 3 inputs (space seperate) for this program:\n");
        printf("   1. A name of input file.\n");
        printf("Please run the program again.\n");
    }
    
    FILE *input;
    char *file = argv[1];
    input = fopen(argv[1], "r");
    int bufferLength = 255;
    char buffer[bufferLength];
    
    while (input == NULL) {
        printf("\n%s doesn't exist. Please try again: ", file);
        scanf("%99[0-9a-zA-Z ]", file);
        getchar();
        input = fopen(file, "r");
    }
    printf("Opening file %s...\n", file);
    
    printf("Reading...\n");
    int letters[26] = {0};
    while(fgets(buffer, bufferLength, input)) {
        char *p = buffer;
        for ( ; *p; p++) {
            if (*p >= 'A' && *p <= 'Z') {
                *p = *p + 32;
            }
            if (*p >= 'a' && *p <= 'z') {
                letters[*p - 'a']++;
            }
        }
        printf("%s", buffer);
    }
    
    printf("Counted Report:\n");
    int i;
    int max1 = 0, max2 = 0;
    int letter1 = -1, letter2 = -1;
    for (i = 0; i < 26; i++) {
        printf("%c: %d\n", i + 'a', letters[i]);
        if (letters[i] > max1) {
            letter1 = i;
            max1 = letters[i];
        } else if (letters[i] > max2 && i != letter1) {
            max2 = letters[i];
            letter2 = i;
        }
    }
    printf("Found the most common letter is %c (%d)\n", letter1 + 'a', max1);
    printf("Found the second most common letter is %c (%d)\n", letter2 + 'a', max2);
    
    int mostCommonLetter = 'e' - 'a';
    int secondCommonLetter = 't' - 'a';
    
    int key1 = 0, key2 = 0;
    
    key1 = mostCommonLetter - letter1;
    if (key1 < 0) key1 += 26;
    
    key2 = secondCommonLetter - letter2;
    if (key2 < 0) key2 += 26;
    
    printf("Key 1: %d\n", key1);
    printf("Key 2: %d\n", key2);
    if (key1 == key2) {
        printf("Possible key: %d\n\n", key1);
    }
    
    fclose(input);
    return 0;
}

