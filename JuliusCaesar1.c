//
//  JuliusCaesar1.c
//  System Level Assignments
//
//  Created by Minh Nguyen on 7/12/20.
//  Copyright © 2020 Minh Nguyen. All rights reserved.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char * argv[]) {
    if (argc != 4) {
        printf("Please provide 3 inputs (space seperate) for this program:\n");
        printf("   1. An integer key (1 - 26).\n");
        printf("   2. A name of input file.\n");
        printf("   3. A name of output file.\n");
        printf("Please run the program again.\n");
    }
    int key = atoi(argv[1]); // 23
    while (key < 1 || key > 26) {
        printf("\nYour key input: %d\n", key);
        printf("The number must be between 1 and 26. Please try again: ");
        scanf("%d", &key);
        getchar();
    }
    
    FILE *input;
    char *file = argv[2];
    input = fopen(argv[2], "r");
    int bufferLength = 255;
    char buffer[bufferLength];
    
    while (input == NULL) {
        printf("\n%s doesn't exist. Please try again: ", file);
        scanf("%99[0-9a-zA-Z ]", file);
        getchar();
        input = fopen(file, "r");
    }
    
    printf("Opening file %s...\n", file);
    
    FILE *output;
    output = fopen(argv[3], "w");
    printf("Opening file %s...\n", argv[3]);
    
    printf("Translating...\n");
    while(fgets(buffer, bufferLength, input)) {
        char *p = buffer;
        for ( ; *p; p++) {
            if (*p >= 'A' && *p <= 'Z') {
                *p = *p + 32;
            }
            if (*p >= 'a' && *p <= 'z') {
                *p = (*p - 'a' + key) % 26 + 'a';
            }
        }
        printf("%s", buffer);
        fprintf(output, "%s", buffer);
    }
    
    fclose(input);
    fclose(output);
    return 0;
}

