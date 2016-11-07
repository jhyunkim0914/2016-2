/**
 * http://usejsdoc.org/
 */
var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var workerSchema = new Schema({
    id: String,
    password: String,
	name: String,
    address: String,
    phone: String
});
 
module.exports = mongoose.model('worker', workerSchema);