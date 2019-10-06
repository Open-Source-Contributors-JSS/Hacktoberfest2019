function leet(word) {
  const leetMap = {
    a: "4",
    b: "8",
    e: "3",
    g: "6",
    i: "1",
    o: "0",
    s: "5",
    t: "7",
    z: "2",
    " ": " " // keep the space
  };
  word = word.toLowerCase(); // make it lowercase
  let tmp = "";
  for (let i = 0; i < word.length; i++) {
    let leet = leetMap[word.charAt(i)];
    if (leet !== undefined) {
      tmp += leet;
    } else {
      tmp += word.charAt(i);
    }
  }
  return tmp;
}

console.log(leet("Hello World!"));
