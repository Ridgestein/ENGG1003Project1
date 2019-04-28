#include <stdio.h> 
#include <stdlib.h>

char ROCE (char *message, int k, int length); //function defintion for rotation cipher encryption
char ROCD (char *message, int k, int length); //function defintion for rotation cihper decryption
char SUBCE (char *message, char *subK, int length); //the function definiton for substitution cipher encryption

int main()
{

    char message[20] = "HELLO THERE"; //hardcoded message to be translated 
    int k = 10; //the current cipher key from 1 to 25
    char subK[30] = "PHQGIUMEAYLNOFDXJKRCVSTZWB"; //the key specifically for the substitution cipher  
    int l = sizeof(message)/sizeof(message[0]); //allows the changing size of the message array to be updated when the message is changed
    int option; //allows for the user interface to be interacted with 
            
do {
    printf("Select one: Rotation Encrypt(1), Rotation Decrypt(2), Substitution Encrypt(3), Exit(0)"); //prints the user interface, which is then interacted with by the 'option variable'
    scanf("%d", &option); 
    switch (option) { 
    
        case 1:
            ROCE(message, k, l);
            break;  
        
        case 2:
            for(k = 0; k < 26; k++) {
                ROCD(message, k, l); 
            }   
            break;
        
        case 3:
            SUBCE(message, subK, l);
            break;
    }
   
    } while (option != 0);

return 0;
}
    
char ROCE (char *message, int k, int length) {
             
        int i; //the current postion of a indiviual character being read
        char ch; //single character of the message to be read
        char result[length]; //variable for the final encrypted/decrypted message to be stored in
        
        for(i = 0; message[i] != '\0'; ++i){
            ch = message[i];
            if (message[i] >= 65 && message[i] <= 90) { //checks for non-alphabet characters e.g. the space character
                ch = (ch + k - 65) % 26 + 65; 
            }
        result[i] = ch;
        }
        result[length] = '\0';
            
        printf("Encrypted message: %s\n", result);

   return 0; 
}

char ROCD (char *message, int k, int length) {
    
    int i; 
    char ch; 
    char result[length];
    int e_count = 0;
    
    for(i = 0; message[i] != '\0'; ++i){
        ch = message[i];
        if (message[i] >= 65 && message[i] <= 90) { 
            ch = (ch - k - 65 + 26) % 26 + 65;
        }
        if (ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') { //checks for vowels and adds them to a counter, making it easier to tell if a decrypted message is the right one
            e_count++;  
        }
        result[i] = ch;
    }
        result[length] = '\0';
            
        printf("Vowels: %d, Decrypted message: %s\n\n", e_count, result);
    
    return 0;
    
}

char SUBCE (char *message, char *subK, int length) {
    
    int i = 0; 
    int x = 0; //the current position of a letter in the nAlpha and subK arrays
    //char ch; 
    char result[length]; 
    //char subK[] = "PHQGIUMEAYLNOFDXJKRCVSTZWB";
    char nAlpha[30] = "ABCDEFGHIJKLMNOPQRSTUVWXZY"; //the normal alphabet to be compared to the cipher alphabet
    
    while (message[i] != '\0') {
        if (nAlpha[x] == message[i]) {
        result[i] = subK[x];
        i++;
        x = 0; 
        }
        else {
        x++;    
        }
    }

        printf("Encrypted message: %s\n", result);
        
    return 0;
}
