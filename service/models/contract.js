/**
 * http://usejsdoc.org/
 */
var mongoose = require('mongoose');
var Schema = mongoose.Schema;

var contractSchema = new Schema({
    start_date: Date,
    end_date: Date,
    content: String,
    working_time: [Number],
    wage_timing: Boolean,
    wage: Number,
    bonus: Number,
    other_pay: Number,
    bonus_rate: Number,
    payday: String,
    howto_pay: String,
    social_insurance: [Number],
    contract_date: Date,
    owner_id: Schema.Types.ObjectId,
    worker_id: Schema.Types.ObjectId
});
 
module.exports = mongoose.model('contract', contractSchema);