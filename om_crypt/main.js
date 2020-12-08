const om = require('./om_crypt.js');

var test = 'a';
var newt = om.char_to_int(test);
var news = om.int_to_char(newt);

console.log(test);
console.log(newt);
console.log(news);

let msg = "this is my message, I am mordecai the ruler";
let emsg = om.encrypt(msg,"this is my key this is my key this is my key this is my key ");
let dmsg = om.decrypt(emsg,"this is my key this is my key this is my key this is my key ");

console.log(msg);
console.log(emsg);
console.log(dmsg);