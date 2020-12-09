// costum module
const om = require('./om_crypt.js');
const render_output = require('./send_html.js');

// server module
const express = require('express');
const app = express();

// paths module
const path = require('path');

// serve public folder to public access
app.use(express.static('public'));

// use for input fields and json obj
const bodyParser = require('body-parser');
app.use(bodyParser.urlencoded({extended:true}));
app.use(bodyParser.json());

// home
app.get('/',(req,res)=>{
	res.sendFile(path.join(__dirname + '/index.html'));
})

app.post('/encrypt',(req,res) => {
	let key_str = req.body.KEY_STR_E;
	let msg_str = req.body.TO_ENCRYPT;
	let encrypt_str = om.encrypt(msg_str,key_str);
	res.send(render_output.out_encrypt(encrypt_str));
})

app.post('/decrypt',(req,res) => {
	let key_str = req.body.KEY_STR_D;
	let msg_str = req.body.TO_DECRYPT;
	let decrypt_str = om.decrypt(msg_str,key_str);
	res.send(render_output.out_decrypt(decrypt_str));
})

// use available port
const PORT = process.env.PORT || 8080
app.listen(PORT);
console.log(`serving on port : ${PORT}`);