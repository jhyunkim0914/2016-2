
/**
 * Module dependencies.
 */

var express     = require('express');
var app         = express();
var bodyParser  = require('body-parser');
var mongoose    = require('mongoose');
 
// [CONFIGURE APP TO USE bodyParser]
app.use(bodyParser.urlencoded({ extended: true }));
app.use(bodyParser.json());
 
// [CONFIGURE SERVER PORT]
var port = process.env.PORT || 8080;
 
//DEFINE MODEL
var Book = require('./models/book');
var Owner = require('./models/owner');
var Worker = require('./models/worker');
var Contract = require('./models/contract');

// [CONFIGURE ROUTER]
var router = require('./routes')(app, Book, Owner, Worker, Contract);
 
// [RUN SERVER]
var server = app.listen(port, function(){
 console.log("Express server has started on port " + port);
});

//[ CONFIGURE mongoose ]

//CONNECT TO MONGODB SERVER
var db = mongoose.connection;
db.on('error', console.error);
db.once('open', function(){
 // CONNECTED TO MONGODB SERVER
 console.log("Connected to mongod server");
});

mongoose.connect('mongodb://localhost/mongodb_tutorial');

