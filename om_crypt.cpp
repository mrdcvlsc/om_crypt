#include <iostream>
#include <string>

#include "om_crypt.h"
		
using namespace std;

//here this is an update

string k_char = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+`~[]\\{}|;\':\",./<>?";

int lander = 0;

int charToInt(char letter){
	for(int i = 0; i < k_char.size(); ++i){
		if(letter == k_char[i])
			return i+1;
	}
     return '\0';
}

char intToChar(int number){
	return k_char[number-1];
}

int checking_95(int add_or_sub_values)
{
     int return_;
     if(add_or_sub_values < 1)
          return return_ = add_or_sub_values + k_char.size();

     if(add_or_sub_values > k_char.size())
          return return_ = add_or_sub_values - k_char.size();

     return add_or_sub_values;
}

string encrypt(string filedata_, string key)
{
     string encrypted;
     string File_uncrypted = filedata_;

     size_t ky_size = key.size();
     size_t file_data_size =  filedata_.size();

     int  *key_int_value = new int [ky_size],
          *int_val_storage_en_char = new int [file_data_size],
          *int_added_val_KeyAndFile = new int [file_data_size];

     char *cryptEn_char_converted_added_int_val_KeyAndFile = new char[file_data_size];

     //encrypt  - the File_uncrypted string per index character is converted into it's integer value then
     //was stored on an int array that have the same size of the File_uncrypted string
     for(unsigned int i = 0; i < file_data_size; ++i)
          int_val_storage_en_char[i] = charToInt(File_uncrypted[i]);

     //same with the process above but was performed for the key
     for(unsigned int i = 0; i < ky_size; ++i)
          key_int_value[i] = charToInt(key[i]);

     // now we got the integer value of each characters that was contained in the string File_uncrypted & key;

     // here we add the integer value of the characters of the File_uncrypted and the key, every time when the key reached it's end
     // we are just going to it's start value again and use it to add with the string File_uncrypted char values.
     for(unsigned int i = 0, j = 1; i < file_data_size; ++i)
     {
          if     (j < ky_size) {
               int_added_val_KeyAndFile[i] = (key_int_value[j-1] + int_val_storage_en_char[i]) - lander;
               j = j + 1;
          }
          else if(j == ky_size) {
               int_added_val_KeyAndFile[i] = (key_int_value[j-1] + int_val_storage_en_char[i]) - lander;
               j =  1;
          }
     }
     //now the int_added_val_KeyAndFile int array contains add the added value of the int_val_storage_en_char and key_int_value integers.

     //Then convert the int value to characters and store it to another character array that also have the same
     // size of the File_uncrypted string.
     for(unsigned int i = 0; i < file_data_size; ++i) {
          int temporary_store2;
          temporary_store2 = checking_95(int_added_val_KeyAndFile[i]);
          cryptEn_char_converted_added_int_val_KeyAndFile[i] = intToChar(temporary_store2);
     }


     // now you have the encrypted the File_uncrypted string and it was stored in the cryptEn_char_converted_added_int_val_KeyAndFile;

     string File_crypted;
     // reading the encrypted file then stores it into a string


     File_crypted = cryptEn_char_converted_added_int_val_KeyAndFile; // file encrypted

     encrypted = File_crypted;

     //
     if(encrypted.size() > file_data_size)
          encrypted.erase(file_data_size);

     delete [] key_int_value;
     delete [] int_val_storage_en_char;
     delete [] int_added_val_KeyAndFile;
     delete [] cryptEn_char_converted_added_int_val_KeyAndFile;
     return encrypted;
}


string decrypt(string filedata_, string key)
{
     string decrypted;

     string File_crypted;
     File_crypted = filedata_;

     size_t ky_size = key.size();
     size_t file_data_size =  filedata_.size();

     int  *key_int_value = new int[ky_size],
          *char_to_int_val_storage_de = new int[file_data_size],
          *int_Subtracted_val_KeyAndFile = new int[file_data_size];


     char *cryptDe_char_converted_Subtracted_int_val_KeyAndFile = new char[file_data_size];

     // Decrypt - converted the encrypted file characters into integer per character
     // then stored in the char_to_int_val_storage_de int array
     // Encrypted File characters to Encrypted File integer value
     for(unsigned int i = 0; i < file_data_size; ++i)
     {
          char_to_int_val_storage_de[i] = charToInt(File_crypted[i]);
     }

     for(unsigned int i = 0; i < ky_size; ++i)
          key_int_value[i] = charToInt(key[i]);

     // Encrypted File integer value to Decrypted File integer value
     // we will do this by subtracting the Encrypted File integer value to the integer value of the key
     // then we will store it to cryptDe_char_converted_Subtracted_int_val_KeyAndFile character array


     for(unsigned int i = 0, j = 1; i < file_data_size; ++i)
     {
          if     (j < ky_size) {
               int_Subtracted_val_KeyAndFile[i] = (char_to_int_val_storage_de[i] - key_int_value[j-1]) + lander;
               j = j + 1;
          }
          else if(j == ky_size) {
               int_Subtracted_val_KeyAndFile[i] = (char_to_int_val_storage_de[i] - key_int_value[j-1]) + lander;
               j =  1;
          }
     }

     // Convert the int_Subtracted_val_KeyAndFile arrays to character arrays
     // then store it to the cryptDe_char_converted_Subtracted_int_val_KeyAndFile character array
     for(unsigned int i = 0; i < file_data_size; ++i)
     {
          int temporary_store;
          temporary_store = checking_95(int_Subtracted_val_KeyAndFile[i]);
          cryptDe_char_converted_Subtracted_int_val_KeyAndFile[i] = intToChar(temporary_store);
     }

     //then store the decrypted characters into a proper string
     File_crypted = cryptDe_char_converted_Subtracted_int_val_KeyAndFile;

     decrypted = File_crypted;

     if(decrypted.size() > file_data_size)
          decrypted.erase(file_data_size);

     delete [] key_int_value;
     delete [] char_to_int_val_storage_de;
     delete [] int_Subtracted_val_KeyAndFile;
     delete [] cryptDe_char_converted_Subtracted_int_val_KeyAndFile;
     return decrypted;
}

