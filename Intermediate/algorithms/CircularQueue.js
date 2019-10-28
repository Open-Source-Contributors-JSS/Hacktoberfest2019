/**
 * Circular queue with amortized O(1) complexity, queue resets when it's empty
 * @param size
 * @constructor
 */
export function Queue(size=2) {
    if(typeof size != 'number') {
        console.log('Argument must be a number');
        return
    }
    let reset = size;
    let list = new Array(size);
    let firstPointer = null;
    let lastPointer = null;

    this.enqueue = function(data) {
        if (firstPointer === 0 && lastPointer === list.length - 1) {
            list = list.concat(new Array(list.length));
        }
        if (firstPointer - lastPointer === 1) {
            let size = list.length;
            list = list.slice(0, firstPointer).concat(new Array(size)).concat(list.slice(firstPointer))
            firstPointer += size;
        }

        if ((!firstPointer && firstPointer !== 0) && (!lastPointer && lastPointer !== 0)) {
            firstPointer = 0;
            lastPointer = 0;
            list[lastPointer] = data;
        } else if (lastPointer === list.length - 1 && firstPointer !== 0) {
            lastPointer = 0;
            list[lastPointer] = data;
        } else {
            list[++lastPointer] = data;
        }
        return list.length;
    };

    this.dequeue = function() {
        let dequeueData = null;
        if (firstPointer === list.length - 1) {
            dequeueData = list[firstPointer];
            list[firstPointer] = null;
            firstPointer = 0;
        } else if (firstPointer === lastPointer) {
            dequeueData = list[firstPointer];
            list[firstPointer] = null;
            firstPointer = null;
            lastPointer = null;
            list.length = reset;
        } else {
            dequeueData = list[firstPointer];
            list[firstPointer++] = null;
        }
        return dequeueData;
    }
}