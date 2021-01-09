package omcrypt;

public class omcrypt
{            
    public String k_char;

    public omcrypt()
    {
        k_char = " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+`~[]\\{}|;\':\",./<>?";
    }

    public int charToInt(char letter)
    {
        for(int i = 0; i < k_char.length(); ++i)
        {
            if(letter == k_char.charAt(i))
                return i+1;
        }
        return '\0';
    }

    public char intToChar(int number)
    {
        return k_char.charAt(number-1);
    }

    public int checking(int add_or_sub_values)
    {
        int return_;
        if(add_or_sub_values < 1)
        {
            return return_ = add_or_sub_values + k_char.length();
        }
        
        if(add_or_sub_values > k_char.length())
        {
            return return_ = add_or_sub_values - k_char.length();
        }
        
        return add_or_sub_values;
    }

    public String encrypt(String filedata_, String key)
    {
        String encrypted;
        String File_uncrypted = filedata_;

        int ky_size = key.length();
        int file_data_size =  filedata_.length();

        int [] key_int_value = new int [ky_size];
        int [] int_val_storage_en_char = new int [file_data_size];
        int [] int_added_val_KeyAndFile = new int [file_data_size];

        char [] cryptEn_char_converted_added_int_val_KeyAndFile = new char[file_data_size];
        
        for(int i = 0; i < file_data_size; ++i)
        {
            int_val_storage_en_char[i] = charToInt(File_uncrypted.charAt(i));
        }
        
        for(int i = 0; i < ky_size; ++i)
        {
            key_int_value[i] = charToInt(key.charAt(i));
        }
        
        for(int i = 0, j = 1; i < file_data_size; ++i)
        {
            if(j < ky_size)
            {
                int_added_val_KeyAndFile[i] = (key_int_value[j-1] + int_val_storage_en_char[i]);
                j = j + 1;
            }
            else if(j == ky_size)
            {
                int_added_val_KeyAndFile[i] = (key_int_value[j-1] + int_val_storage_en_char[i]);
                j =  1;
            }
        }
        
        for(int i = 0; i < file_data_size; ++i)
        {
            int temporary_store2;
            temporary_store2 = checking(int_added_val_KeyAndFile[i]);
            cryptEn_char_converted_added_int_val_KeyAndFile[i] = intToChar(temporary_store2);
        }
        
        String File_crypted;
        
        File_crypted = String.valueOf(cryptEn_char_converted_added_int_val_KeyAndFile); // file encrypted
        encrypted = File_crypted;

        if(encrypted.length() > file_data_size)
        {
            encrypted = encrypted.substring(0,file_data_size);
        }

        return encrypted;
    }


    public String decrypt(String filedata_, String key)
    {
        String decrypted;

        String File_crypted;
        File_crypted = filedata_;

        int ky_size = key.length();
        int file_data_size =  filedata_.length();

        int [] key_int_value = new int[ky_size];
        int [] char_to_int_val_storage_de = new int[file_data_size];
        int [] int_Subtracted_val_KeyAndFile = new int[file_data_size];


        char[] cryptDe_char_converted_Subtracted_int_val_KeyAndFile = new char[file_data_size];

        for(int i = 0; i < file_data_size; ++i)
        {
            char_to_int_val_storage_de[i] = charToInt(File_crypted.charAt(i));
        }

        for(int i = 0; i < ky_size; ++i)
        {
            key_int_value[i] = charToInt(key.charAt(i));
        }
        
        for(int i = 0, j = 1; i < file_data_size; ++i)
        {
            if(j < ky_size)
        {
                int_Subtracted_val_KeyAndFile[i] = (char_to_int_val_storage_de[i] - key_int_value[j-1]);
                j = j + 1;
            }
            else if(j == ky_size)
        {
                int_Subtracted_val_KeyAndFile[i] = (char_to_int_val_storage_de[i] - key_int_value[j-1]);
                j =  1;
            }
        }
        
        for(int i = 0; i < file_data_size; ++i)
        {
            int temporary_store;
            temporary_store = checking(int_Subtracted_val_KeyAndFile[i]);
            cryptDe_char_converted_Subtracted_int_val_KeyAndFile[i] = intToChar(temporary_store);
        }

        File_crypted = String.valueOf(cryptDe_char_converted_Subtracted_int_val_KeyAndFile);
        decrypted = File_crypted;

        if(decrypted.length() > file_data_size)
        {
            decrypted = decrypted.substring(0,file_data_size);
        }
        
        return decrypted;
    }    
}

