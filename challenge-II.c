#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define STR_(X) #X
#define STR(X) STR_(X)
#define BUFFER_MAX_SIZE 100

char* prefixCharacterToString(char prefixCharacter, char* string, int stringLength, int repeatCount) {

    int mallocSize = sizeof(char) * (stringLength + repeatCount + 1);
    char* newString = malloc(mallocSize);

    int currentIndex = 0;
    for(; currentIndex < repeatCount; currentIndex++) {
        newString[currentIndex] = prefixCharacter;
    }
    for(currentIndex = 0; currentIndex < stringLength; currentIndex++) {
        newString[currentIndex + repeatCount] = string[currentIndex];
    }
    newString[currentIndex + repeatCount] = '\0';

    return newString;

}

// zerosEsquerda (seq , N)
char* leadingZeros(char* ticketId, unsigned long long ticketLength) {

    int ticketIdLength = strlen(ticketId);
    int numberOfZeros = ticketLength - ticketIdLength;

    // guard if
    int isTicketAtSpecifiedLength = numberOfZeros <= 0;
    if(isTicketAtSpecifiedLength) {
        return ticketId;
    }

    return prefixCharacterToString('0', ticketId, ticketIdLength, numberOfZeros);

}

void main() {
    char ticketId[BUFFER_MAX_SIZE];
    unsigned long long ticketLength;
    scanf("%" STR(BUFFER_MAX_SIZE) "[^ ]%llu", ticketId, &ticketLength);

    char* newTicketId = leadingZeros(ticketId, ticketLength);
    printf("%s", newTicketId);
}
