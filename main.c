#include <stdio.h>

char RoC (char m, char c, char message); // function defintion for rotation cipher

int main()
{
    int k = 0 ; // the cipher key
    char m; // a letter of the message before encryption
    char c ; // a letter of the message after encryption
    char message[100] = "Hello There"; // the given message to be encrypted
    //scanf("%s", message);
    
    return k;
}

char RoC (char m, char c, char message) {
    //for loop here later for rotation
    int k = 0;
    
    for(k = 0; k <= 26; k++;) {
        message = message (m + k % 26);
        printf("%s", &message);
    } 
    
    
    return message;
}