function alternateCase(text) {
    var newText = "";
    for (var i = 0; i < text.length; i++) {
        if (i % 2 == 0) {
            newText += text.charAt(i).toUpperCase();
        } else {
            newText += text.charAt(i).toLowerCase();
        }
    }
    console.log(newText);
}

alternateCase('hello world');