const readline = require('readline');

// Create an interface for reading input from the terminal
const rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});


let a;
let b;
// Prompt the user for input for 'a'
rl.question((aInput) => {
  a = parseInt(aInput, 10);
});



console.log(a);