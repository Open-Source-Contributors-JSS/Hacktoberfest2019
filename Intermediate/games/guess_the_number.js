const readline = require('readline').createInterface({
  input: process.stdin,
  output: process.stdout
});

async function runGame() {
  const upperBound = await readline.question(`Set the upper bound of the generated number (ex: 100)`)
  const lowerBound = await readline.question(`Set the lower bound of the generated number (ex: 0)`)
  const number = Math.floor(Math.random() * (upperBound-lowerBound)) + lowerBound;
  let guess = await readline.question(`Number generated, start guessing`)
  while(guess != number) {
    if(guess>number) {
      guess = await readline.question(`The number is smaller than your guess, try again`)
    } else {
      guess = await readline.question(`The number is bigger than your guess, try again`)
    }
  }
  console.log('Congratulations, you got it, your guess is correct :)')
}

runGame()
