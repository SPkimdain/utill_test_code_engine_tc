var o;
if(Math.random()) o = null;
if(Math.random()) o = false;
if(Math.random()) o = 5432;
if(Math.random()) o = "asdf";
//if(Math.random()) o = {};

"x" in o;  // @violation
"x" instanceof o; // @violation

Date instanceof Object; // true
var o2 = new Object();
c in o2;
Date instanceof o2;   // true

var d = "11";
c instanceof d; //@violation


