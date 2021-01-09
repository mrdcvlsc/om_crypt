const om = require('./om_crypt.js');

var test = 'a';
var newt = om.char_to_int(test);
var news = om.int_to_char(newt);

console.log(test);
console.log(newt);
console.log(news);

let msg = "this is my message, an important one that needs protection";
let emsg = om.encrypt(msg,"a key of seemingly random characters");
let dmsg = om.decrypt(emsg,"a key of seemingly random characters");

console.log(msg);
console.log(emsg);
console.log(dmsg);