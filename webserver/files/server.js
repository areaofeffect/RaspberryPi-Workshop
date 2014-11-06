var express = require('express');
var app     = express();

app.use(express.static(__dirname + '/dist'));

app.get('/', function(req, res) {
  res.sendfile('./dist/index.html');
});

app.listen(8080);