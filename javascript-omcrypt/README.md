## requires node.js

run in terminal **```node main.js```**

# JavaScript - omcrypt

## encryption

**`encrypt(string msg, string key)` function**
  - this function takes two string arguments, first is the text to be encrypted, and the key that will be used to encrypt the text, the longer the key the better
  - this returns a encrypted string text value that you can store in a string variable
  
**`decrypt(string msg, string key)` function**
  - this function also takes two string arguments, the first is the encrypted text to be decrypted back to its original form, the the correct key string
  - returns decrypted string...
  
## sample code
```javascript
// main.js
const om = require('./om_crypt.js');

let msg = "this is my message, an important one that needs protection";
let emsg = om.encrypt(msg,"a key of seemingly random characters");
let dmsg = om.decrypt(emsg,"a key of seemingly random characters");

console.log(msg);
console.log(emsg);
console.log(dmsg);
```

