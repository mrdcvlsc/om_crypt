/* 
put this in your driver js file (main.js/index.js):
	const om = require('./om_crypt.js');

om.encrypt("your_msg","secret_key");
om.decrypt("your_encrypted_msg","secret_key");
*/

module.exports = {

	characters: " abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890-=!@#$%^&*()_+[]\\;\',./{}|:\"<>?",

	char_to_int: function(character)
	{
		const char_table_size = this.characters.length;
		for(let i=0; i<char_table_size; ++i)
		{
			if(character == this.characters[i])
				return i+1;
		}
    		return '\0';
	},

	int_to_char: function(integer)
	{
		return this.characters[integer-1];
	},

	checking: function(add_or_sub_values)
	{
		let return_;
		if(add_or_sub_values < 1)
			return return_ = add_or_sub_values + this.characters.length;

		if(add_or_sub_values > this.characters.length)
			return return_ = add_or_sub_values - this.characters.length;

    		return add_or_sub_values;
	},

	encrypt: function(message,key)
	{
		     let encrypted;

		     const ky_size = key.length;
		     const file_data_size =  message.length;

		     let  key_int_value = Array.apply(null, Array(ky_size)).map(function () {});
		     let  int_val_storage_en_char = Array.apply(null, Array(file_data_size)).map(function () {});
		     let  int_added_val_KeyAndFile = Array.apply(null, Array(file_data_size)).map(function () {});

		     let cryptEn_char_converted_added_int_val_KeyAndFile = Array.apply(null, Array(file_data_size)).map(function () {});

		     for(let i=0; i<file_data_size; ++i)
		          int_val_storage_en_char[i] = this.char_to_int(message[i]);

		     for(let i=0; i<ky_size; ++i)
		          key_int_value[i] = this.char_to_int(key[i]);

		     for(let i=0, j=1; i < file_data_size; ++i)
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

		     let temporary_store2;
		     for(let i=0; i<file_data_size; ++i)
		     {
		          temporary_store2 = this.checking(int_added_val_KeyAndFile[i]);
		          cryptEn_char_converted_added_int_val_KeyAndFile[i] = this.int_to_char(temporary_store2);
		     }

		     let File_crypted;
		     File_crypted = cryptEn_char_converted_added_int_val_KeyAndFile; // file encrypted

		     encrypted = File_crypted;

		     if(encrypted.lenght > file_data_size)
		          encrypted = encrypted.substring(0,file_data_size);

		     return encrypted.join('');
	},

	decrypt: function (message, key)
	{
		let decrypted;
		let File_crypted = message;

		let ky_size = key.length;
		let file_data_size =  message.length;

		let key_int_value = Array.apply(null, Array(ky_size)).map(function () {});
		let char_to_int_val_storage_de = Array.apply(null, Array(file_data_size)).map(function () {});
        	let int_Subtracted_val_KeyAndFile = Array.apply(null, Array(file_data_size)).map(function () {});


		let cryptDe_char_converted_Subtracted_int_val_KeyAndFile = Array.apply(null, Array(file_data_size)).map(function () {});

		for(let i = 0; i < file_data_size; ++i)
     		{
        		char_to_int_val_storage_de[i] = this.char_to_int(File_crypted[i]);
     		}

		for(let i = 0; i < ky_size; ++i)
			key_int_value[i] = this.char_to_int(key[i]);

     		for(let i = 0, j = 1; i < file_data_size; ++i)
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

    		let temporary_store;
		for(let i = 0; i < file_data_size; ++i)
     		{
          		temporary_store = this.checking(int_Subtracted_val_KeyAndFile[i]);
			cryptDe_char_converted_Subtracted_int_val_KeyAndFile[i] = this.int_to_char(temporary_store);
		}

		File_crypted = cryptDe_char_converted_Subtracted_int_val_KeyAndFile;

		decrypted = File_crypted;

		if(decrypted.length > file_data_size)
			decrypted.substring(0,file_data_size);

		return decrypted.join('');
	}
}
