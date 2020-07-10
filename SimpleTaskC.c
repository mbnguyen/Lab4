//
//  Simple Task in C
//  System Level Assignments
//
//  Created by Minh Nguyen on 7/8/20.
//  Copyright © 2020 Minh Nguyen. All rights reserved.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int stringToInt (char *str) {
    int result = 0;
    int i;
    for (i = 0; i < strlen(str); i++) {
        if (str[i] >= '0' && str[i] <= '9') {
            result = result * 10 + (str[i] - '0');
        }
    }
    return result;
}

int isLeapYear (int year) {
    if (year % 400 == 0) {
        return 1;
    }
    if (year % 4 == 0 && year % 100 != 0) {
        return 1;
    }
    return 0;
}

int task4 () {
    int sum = 0;
    int i;
    for (i = 0; i < 1000; i++) {
        if (i % 3 == 0 || i % 5 == 0) {
            sum += i;
        }
    }
    return sum;
}

char* intToString (int number, char *str, int len) {
    int num = number;
    char *p = &str[len - 1];
    *p-- = '\0';
    do {
        *p-- = ((num % 10) + '0');
        num /= 10;
    } while (num);
    if (number < 0) {
        *p-- = '-';
    }
    return ++p;
}

int isPalindrome(char *str) {
    int len = (int)strlen(str);
    int i;
    for (i = 0; i < len / 2; i++) {
        if (str[i] != str[len - 1 - i]) {
            return 0;
        }
    }
    return 1;
}

int maxPalindrome (int from, int to) {
    int len = 20;
    char *str = malloc(sizeof(str) * len + 1);
    int a;
    for (a = to; a >= from; a--) {
        int b;
        for (b = a; b >= from; b--) {
            int product = a * b;
            char *s = intToString(product, str, len);
            if (isPalindrome(s)) {
                return product;
            }
        }
    }
    return 0;
}

char* numberToWord (int num) {
    char *result = malloc(sizeof(result) * 100 + 1);;
    *result = '\0';
    if (num <= 19) {
        char words[20][15] = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
            "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
        };
        strcat(result, words[num]);
    } else if (num < 100) {
        int first = num / 10;
        int second = num % 10;
        char wordsFirst[10][15] = {
            "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
        };
        char wordsSecond[10][15] = {
            "", "-one", "-two", "-three", "-four", "-five", "-six", "-seven", "-eight", "-nine"
        };
        strcat(result, wordsFirst[first]);
        strcat(result, wordsSecond[second]);
    }
    return result;
}

int wordsToNumber (char *s) {
    int result = 0;
    char *p = s;
    for ( ; *p; p++) {
        *p = tolower(*p);
    }
    char *first = strtok(s, "- ");
    char *second = strtok(NULL, "- ");
    if (second == NULL) {
        char words[20][15] = {
            "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", "ten",
            "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", "seventeen", "eighteen", "nineteen"
        };
        int i;
        for (i = 0; i < 20; i++) {
            if (strcmp(first, words[i]) == 0) {
                break;
            }
        }
        result = i;
    } else {
        char wordsFirst[10][15] = {
            "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
        };
        char wordsSecond[10][15] = {
            "", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"
        };
        int i;
        for (i = 0; i < 10; i++) {
            if (strcmp(first, wordsFirst[i]) == 0) {
                result = i * 10;
                break;
            }
        }
        for (i = 0; i < 10; i++) {
            if (strcmp(second, wordsSecond[i]) == 0) {
                result += i;
                break;
            }
        }
    }
    return result;
}

int productFromWords (char *str) {
    char *first = strtok(str, " ");
    char *second = strtok(NULL, " ");
    int a = wordsToNumber(first);
    int b = wordsToNumber(second);
    printf("%d * %d = %d\n", a, b, a * b);
    return a * b;
}

int main(int argc, const char * argv[]) {
    // Task 1:
    // Input. Read a line from the terminal and print it out to the user.
    printf("Task 1:\n");
    char str[100] = {0};
    printf("Hello, say something, I'll read it out loud: ");
    scanf("%99[0-9a-zA-Z ]", str);
    getchar();
    printf("You said: %s\n\n", str);
    
    
    // Task 2:
    // Integer input. Read a line and convert it to an integer (if you can)
    printf("Task 2:\n");
    printf("Give me an integer (less than 10 digits): ");
    scanf("%99[0-9a-zA-Z ]", str);
    getchar();
    int num = stringToInt(str);
    int add = 5;
    printf("Your input: %d\n", num);
    printf("To prove this is an integer, I added %d to this number: %d\n\n", add, num + add);
    
    // Task 3:
    // Leap Year
    printf("Task 3:\n");
    int year;
    printf("Give me a year: ");
    scanf("%d", &year);
    getchar();
    printf("%d is%s a leap year.\n\n", year, isLeapYear(year) ? "" : " NOT");
    
    // Task 4:
    // Sum all the integers below 1000 that are multiples of 3 or 5
    printf("Task 4:\n");
    printf("Sum all the integers below 1000 that are multiples of 3 or 5: %d\n\n", task4());
    
    // Task 5:
    // What is the largest palindrome made by the product of two three digit numbers?
    printf("Task 5:\n");
    printf("The max palindrome is: %d\n\n", maxPalindrome(10, 999));
    
    // Task 6:
    // Given an integer that is less than a hundred, print out the words for that integer. In other words, given 33 print out thirty-three. By the way don't print out “fourty” for 40.
    printf("Task 6:\n");
    printf("Give me an integer (less than 100): ");
    scanf("%d", &num);
    getchar();
    printf("%d has been converted to words: %s\n\n", num, numberToWord(num));
    
    // Task 7:
    // Given a word for an integer (e.g. Thirty-three) output the integer.
    printf("Task 7:\n");
    printf("Give me a number in words: ");
    scanf("%99[0-9a-zA-Z -]", str);
    getchar();
    printf("%s has been converted to words: ", str);
    printf ("%d\n\n", wordsToNumber(str));
    
    // Task 8:
    // Given two words for integers, output their product as an integer. (i.e. Three eleven outputs 33)
    printf("Task 8:\n");
    printf("Give me two numbers in words: ");
    scanf("%99[0-9a-zA-Z -]", str);
    getchar();
    printf ("The product is: %d\n\n", productFromWords(str));
    
    return 0;
}

