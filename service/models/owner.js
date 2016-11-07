/**
 * http://usejsdoc.org/
 */
var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var ownerSchema = new Schema({
    id: String,
    password: String,
	name: String,
    address: String,
    company: String,
    company_id: String,
    phone: String
});
 
module.exports = mongoose.model('owner', ownerSchema);