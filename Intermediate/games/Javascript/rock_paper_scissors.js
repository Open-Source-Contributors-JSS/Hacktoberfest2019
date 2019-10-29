// Rock paper scissors with RNG

// Run using 
// node rock_paper_scissors.js

const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});  

const options = ["rock", "paper", "scissors"];

function getRandomChoice() {
  const randomIndex = Math.floor(Math.random() * options.length);
  return options[randomIndex];
}

function determineWinner(userChoice, rngChoice) {
  if (userChoice === rngChoice) {
    console.log('Tie');
  } else if (
    (userChoice === "paper" && rngChoice === "rock") ||
    (userChoice === "rock" && rngChoice === "scissors") ||
    (userChoice === "scissors" && rngChoice === "paper")
  ) {
    console.log('You won!');
  } else {
    console.log('You didn\'t win :(');
  }
}

function doRPC() {
  readline.question(`Rock paper or scissors? `, (input) => {
    const choice = input.toLowerCase();
    if (options.indexOf(choice) > -1) {
      const rngChoice = getRandomChoice();
      console.log('Bot chose ' + rngChoice);
      determineWinner(choice, rngChoice);
    }
    console.log(input);
    doRPC();
  });
}

doRPC();
