var express = require('express');
var router = express.Router();

router.post('/dan', function (req, res) {
    const url = req.body.profile_url;
    try{
        res.redirect(url);  //@violation
    }catch (e) {
        return res.status(500).send("ERROR");
    }
});
router.post('/safe', function (req, res) {
    const url = req.body.profile_url;
    const white_list = ["https://www.fasoo.com", "https://www.google.com"];
    if (white_list.indexOf(url) < 0) {
        return res.status(500).send("허용되지 않은 url 입니다");
    } else {
        try {
            res.redirect(url);
        } catch (e) {
            return res.status(500).send("ERROR");
        }
    }
});
module.exports = router;