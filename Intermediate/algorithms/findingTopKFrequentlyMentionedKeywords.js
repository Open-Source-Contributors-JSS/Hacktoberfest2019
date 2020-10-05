## Problem Statement: 
/*Given a list of reviews, a list of keywords and an integer k. Find the most popular k keywords in order of most to least frequently mentioned.
The comparison of strings is case-insensitive.
Multiple occurances of a keyword in a review should be considred as a single mention.
If keywords are mentioned an equal number of times in reviews, sort alphabetically.

## Example:
Example 1:
Input:
k = 2
keywords = ["anacell", "cetracular", "betacellular"]
reviews = [
  "Anacell provides the best services in the city",
  "betacellular has awesome services",
  "Best services provided by anacell, everyone should use anacell",
]

## Output:
["anacell", "betacellular"]

## Explanation:
"anacell" is occuring in 2 different reviews and "betacellular" is only occuring in 1 review.*/

## Solution / Code:

function solution(k, keywords, reviews){
    let keywordsMap = {};
    keywords.forEach(word => keywordsMap[word] = 0);

    let reviewsArr = [];
    reviews.forEach(review => {
        let arr = review.toLowerCase().split(/\W/g); // https://www.w3schools.com/jsref/jsref_regexp_wordchar_non.asp
        reviewsArr = [...reviewsArr, ...arr];
    });

    reviewsArr.forEach(review => {
        if(keywordsMap[review] || keywordsMap[review] === 0) { // or if(keywordsMap[review] !== undefined)
            keywordsMap[review] += 1;
        }
    });

    const frequency = Object.keys(keywordsMap)
        .sort((a,b) => {
            if(keywordsMap[b] === keywordsMap[a]) {
                return a.localeCompare(b); // if equal - sort alphabetically
            }
            else {
                return keywordsMap[b] - keywordsMap[a] // we want to sort from highest to low frequency
            }

        });
    return frequency.slice(0, k);
}

let res1 = solution(2,
    ['anacell', 'cetracular', 'betacellular'],
    ['Anacell provides the best services in the city', 'betacellular has awesome services',
    'Best services provided by anacell, everyone should use anacell']
);

let res2 = solution(2,
    ['anacell', 'betacellular', 'cetracular', 'deltacellular', 'eurocell'],
    ['I love anacell Best services; Best services provided by anacell',
        'betacellular has great services', 'deltacellular provides much better services than betacellular',
        'cetracular is worse than anacell', 'Betacellular is better than deltacellular.']
);

console.log(res1, res2); // [ 'anacell', 'betacellular' ] [ 'anacell', 'betacellular' ]
