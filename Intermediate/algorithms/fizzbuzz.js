// If number is multiple of 3, log 'Fizz' after the number;
// If number is multiple of 5, log 'Buzz' after the number;
// If number is multiple of 3 and 5, log 'FizzBuzz' after the number;
// If number isn't a multiple, only print the number

for(var i = 0; i <=100; i++){
  let toPrint = '';
  if(i % 3 === 0 && i % 5 === 0){
     toPrint = `${i} - FizzBuzz`;
  }else if(i % 3 === 0){
     toPrint = `${i} - Fizz`;
  }else if(i % 5 === 0){
     toPrint = `${i} - Buzz`;
  }else{
    toPrint = i
  }
  console.log(toPrint);
}
