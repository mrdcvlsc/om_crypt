run in terminal :
compile : **```javac Main.java```**
run : **```java Main```**

# Java - omcrypt

## encryption

**`encrypt(String msg, String key)` function**
  - this function takes two string arguments, first is the text to be encrypted, and the key that will be used to encrypt the text, the longer the key the better
  - this returns a encrypted string text value that you can store in a string variable
  
**`decrypt(String msg, String key)` function**
  - this function also takes two string arguments, the first is the encrypted text to be decrypted back to its original form, the the correct key string
  - returns decrypted string...
  
## sample code
```java
// Main.java

import omcrypt.omcrypt;

public class Main
{
    public static void main(String[] args)
    {
        omcrypt HIDE = new omcrypt();

        String msg = "this is a message that is important needs to be protected";
        String encryptedMsg = HIDE.encrypt(msg,"a secret key of seemingly random characters");
        String decryptedMsg = HIDE.decrypt(encryptedMsg,"a secret key of seemingly random characters");

        System.out.println("Untouched Message : "+msg);
        System.out.println("Encrypted Message : "+encryptedMsg);
        System.out.println("Decrypted Back    : "+decryptedMsg);
    }
}
```

