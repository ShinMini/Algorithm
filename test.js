const fs = require("fs");
let [A, B] = fs.readFileSync("./dev/stdin").toString().split(" ");

if(A > B) console.log(">");
if(A < B) console.log("<");
if(A === B) console.log("==");


