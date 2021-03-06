module.exports = {

	out_decrypt: function(msg){
		let output = `
			<!DOCTYPE html>
			<html>
			<head>
				<title>om_crypt</title>
				<meta name="theme-color" content="rgb(252,3,65)">
				<meta charset="utf-8">
				<meta name="viewport" content="width=device-width,initial-scale=1"> 
				<link rel="stylesheet" type="text/css" href="/index.css">
				<script type="text/javascript" src="/index.js"></script>

			</head>
			<body>

				<div id="main">
					<form action="/encrypt" id="encrypt-form" method="POST"></form>
					<form action="/decrypt" id="decrypt-form" method="POST"></form>

					<div id="heading">
						<h1>om_crypt</h1>
					</div><!--heading-->

					<div id="crypt">

						<div id="encrypt" class="crypt-child">
							<h3>Encrypt</h3>
							<input    name="KEY_STR_E"  form="encrypt-form" type="text" required placeholder="input encryption key" style="text-align: center">
							<textarea name="TO_ENCRYPT" form="encrypt-form" class="crypt-fileds" placeholder="message to encrypt" required>${msg}</textarea><br>
							<p>NOTE</p>
							<p>DO NOT put a "LINE SPACE" or "ENTER SPACE"</p>
							<input type="submit" form="encrypt-form" value="Lock" class="cbuttons">
						</div><!--encrypt-->

						<div id="decrypt" class="crypt-child">
							<h3>Decrypt</h3>
							<input    name="KEY_STR_D"  form="decrypt-form" type="text" required placeholder="input decryption key" style="text-align: center">
							<textarea name="TO_DECRYPT" form="decrypt-form" class="crypt-fileds" placeholder="message to decrypt" required></textarea><br>
							<p>NOTE</p>
							<p>DO NOT put a "LINE SPACE" or "ENTER SPACE"</p>
							<input type="submit" form="decrypt-form" value="Unlock" class="cbuttons">
						</div><!--decrypt-->
					</div><!--crypt-->
				</div><!--main-->
				<br>
				<br>
				<a href="https://github.com/mrdcvlsc/om_crypt">see code for encryption/decryption</a>
				<p>email me at : mordecaivelasco@gmail.com</p>
			</body>
			</html>
		`
		return output;
	},

	out_encrypt: function(msg){
		let output = `
			<!DOCTYPE html>
			<html>
			<head>
				<title>om_crypt</title>
				<meta name="theme-color" content="rgb(252,3,65)">
				<meta charset="utf-8">
				<meta name="viewport" content="width=device-width,initial-scale=1"> 
				<link rel="stylesheet" type="text/css" href="/index.css">
				<script type="text/javascript" src="/index.js"></script>

			</head>
			<body>

				<div id="main">
					<form action="/encrypt" id="encrypt-form" method="POST"></form>
					<form action="/decrypt" id="decrypt-form" method="POST"></form>

					<div id="heading">
						<h1>om_crypt</h1>
					</div><!--heading-->

					<div id="crypt">

						<div id="encrypt" class="crypt-child">
							<h3>Encrypt</h3>
							<input    name="KEY_STR_E"  form="encrypt-form" type="text" required placeholder="input encryption key" style="text-align: center">
							<textarea name="TO_ENCRYPT" form="encrypt-form" class="crypt-fileds" placeholder="message to encrypt" required></textarea><br>
							<p>NOTE</p>
							<p>DO NOT put a "LINE SPACE" or "ENTER SPACE"</p>
							<input type="submit" form="encrypt-form" value="Lock" class="cbuttons">
						</div><!--encrypt-->

						<div id="decrypt" class="crypt-child">
							<h3>Decrypt</h3>
							<input    name="KEY_STR_D"  form="decrypt-form" type="text" required placeholder="input decryption key" style="text-align: center">
							<textarea name="TO_DECRYPT" form="decrypt-form" class="crypt-fileds" placeholder="message to decrypt" required>${msg}</textarea><br>
							<p>NOTE</p>
							<p>DO NOT put a "LINE SPACE" or "ENTER SPACE"</p>
							<input type="submit" form="decrypt-form" value="Unlock" class="cbuttons">
						</div><!--decrypt-->
					</div><!--crypt-->
				</div><!--main-->
				<br>
				<br>
				<a href="https://github.com/mrdcvlsc/om_crypt">see code for encryption/decryption</a>
				<p>email me at : mordecaivelasco@gmail.com</p>
			</body>
			</html>
		`
		return output;
	}
}