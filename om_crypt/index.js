const om = require('./om_crypt.js');

let msg = "this is my message";
let emsg = om.encrypt(msg,"hiasd78d78g2ig3gydgtf76222e27ey2u82y786sed");
let dmsg = om.decrypt(emsg,"hiasd78d78g2ig3gydgtf76222e27ey2u82y786sed");

console.log(msg);
console.log(emsg);
console.log(dmsg);
