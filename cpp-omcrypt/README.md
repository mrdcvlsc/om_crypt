## requires (mingw) g++

run in terminal :
compile : **```g++ -o main.exe main.cpp```**
run in linux : **```./main.exe```**
run in windows : **```main```**

# C++ - omcrypt

## encryption

**`encrypt(string msg, string key)` function**
  - this function takes two string arguments, first is the text to be encrypted, and the key that will be used to encrypt the text, the longer the key the better
  - this returns a encrypted string text value that you can store in a string variable
  
**`decrypt(string msg, string key)` function**
  - this function also takes two string arguments, the first is the encrypted text to be decrypted back to its original form, the the correct key string
  - returns decrypted string...
  
## sample code
```c++
// main.cpp
#include <iostream>
#include "om_crypt.h"

int main(){

	string message = "this is a message test, to be encrypted and to be decrypted back right away, !<>?!@#$%^&*()_+1234567890-=";
	cout<<"\ndefault : \n"<<message<<endl<<endl;

	string encrypted_message = encrypt(message,"a_random_key_for_decryption");
	cout<<"encrypted value : \n"<<encrypted_message<<endl<<endl;

	string decrypted_back = decrypt(encrypted_message,"a_random_key_for_decryption");
	cout<<"decrypted back message\n"<<decrypted_back<<endl<<endl;

	return 0;
}
```

