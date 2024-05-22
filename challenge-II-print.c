#include <stdio.h>
#include <string.h>

#define STR_(X) #X
#define STR(X) STR_(X)
#define TICKET_MAX_SIZE 100

void leadingZeros(char* ticketId, unsigned long long ticketLength) {

    int numberOfZeros = ticketLength - strlen(ticketId);
    int isTicketAtSpecifiedLength = numberOfZeros <= 0;

    if(isTicketAtSpecifiedLength) {
        printf("%s", ticketId);
    } else {
        printf("%0*x%s", numberOfZeros, 0, ticketId);
    }

}

void main() {

    char ticketId[TICKET_MAX_SIZE];
    unsigned long long ticketLength;

    scanf("%" STR(TICKET_MAX_SIZE) "[^ ]%llu", ticketId, &ticketLength);

    leadingZeros(ticketId, ticketLength);

}
