function fibonacci(size) {
    var aux1, aux2, num;
    for (var i = 1; i <= size; i++) {
        if (i == 1) {
            num = 0;
        } else if (i == 2) {
            aux2 = num;
            num = 1;
        } else {
            aux1 = aux2;
            aux2 = num;
            num = aux1 + aux2;
        }
        console.log('[' + i + '] = ' + num);
    }
}

fibonacci(10);