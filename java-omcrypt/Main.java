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