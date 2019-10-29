function palindrome(word) {
    word = word.toLowerCase();
    var reverseWord = word.split('').reverse().join('');
    if (word == reverseWord) {
        console.log(true);
    } else {
        console.log(false);
    }
}

palindrome('arara');