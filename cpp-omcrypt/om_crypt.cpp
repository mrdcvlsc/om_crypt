#include <iostream>
#include <string>
#include "om_crypt.h"
          
using namespace std;

string k_char = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+`~[]\\{}|;\':\",./<>?";

int lander = 0;

int charToInt(char letter)
{
     for(int i = 0; i < k_char.size(); ++i)
     {
          if(letter == k_char[i])
               return i+1;
     }
     return '\0';
}

char intToChar(int number)
{
     return k_char[number-1];
}

int checking(int add_or_sub_values)
{
     int return_;
     if(add_or_sub_values < 1)
     {
          return return_ = add_or_sub_values + k_char.size();
     }
     
     if(add_or_sub_values > k_char.size())
     {
          return return_ = add_or_sub_values - k_char.size();
     }
     
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
     
     for(unsigned int i = 0; i < file_data_size; ++i)
     {
          int_val_storage_en_char[i] = charToInt(File_uncrypted[i]);
     }
     
     for(unsigned int i = 0; i < ky_size; ++i)
     {
          key_int_value[i] = charToInt(key[i]);
     }
     
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
     
     for(unsigned int i = 0; i < file_data_size; ++i)
     {
          int temporary_store2;
          temporary_store2 = checking(int_added_val_KeyAndFile[i]);
          cryptEn_char_converted_added_int_val_KeyAndFile[i] = intToChar(temporary_store2);
     }
     
     string File_crypted;
     
     File_crypted = cryptEn_char_converted_added_int_val_KeyAndFile; // file encrypted
     encrypted = File_crypted;

     if(encrypted.size() > file_data_size)
     {
          encrypted.erase(file_data_size);
     }
     
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

     for(unsigned int i = 0; i < file_data_size; ++i)
     {
          char_to_int_val_storage_de[i] = charToInt(File_crypted[i]);
     }

     for(unsigned int i = 0; i < ky_size; ++i)
     {
          key_int_value[i] = charToInt(key[i]);
     }
     
     for(unsigned int i = 0, j = 1; i < file_data_size; ++i)
     {
          if(j < ky_size)
       {
               int_Subtracted_val_KeyAndFile[i] = (char_to_int_val_storage_de[i] - key_int_value[j-1]) + lander;
               j = j + 1;
          }
          else if(j == ky_size)
       {
               int_Subtracted_val_KeyAndFile[i] = (char_to_int_val_storage_de[i] - key_int_value[j-1]) + lander;
               j =  1;
          }
     }
     
     for(unsigned int i = 0; i < file_data_size; ++i)
     {
          int temporary_store;
          temporary_store = checking(int_Subtracted_val_KeyAndFile[i]);
          cryptDe_char_converted_Subtracted_int_val_KeyAndFile[i] = intToChar(temporary_store);
     }

     File_crypted = cryptDe_char_converted_Subtracted_int_val_KeyAndFile;

     decrypted = File_crypted;

     if(decrypted.size() > file_data_size)
     {
          decrypted.erase(file_data_size);
     }
     
     delete [] key_int_value;
     delete [] char_to_int_val_storage_de;
     delete [] int_Subtracted_val_KeyAndFile;
     delete [] cryptDe_char_converted_Subtracted_int_val_KeyAndFile;
     
     return decrypted;
}