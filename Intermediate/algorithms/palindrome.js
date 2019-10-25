function palindrome(word) {
    word = word.toLowerCase();
    var reverseWord = word.split('').reverse().join('');
    if (word == reverseWord) {
        console.log("The gven word is a Palindrome");
    } else {
        console.log("The gven word is not a Palindrome");
    }
}

palindrome('arara');
