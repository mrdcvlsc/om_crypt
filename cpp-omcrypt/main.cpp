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