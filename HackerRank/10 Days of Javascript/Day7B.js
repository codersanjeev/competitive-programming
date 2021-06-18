'use strict';

process.stdin.resume();
process.stdin.setEncoding('utf-8');

let inputString = '';
let currentLine = 0;

process.stdin.on('data', inputStdin => {
    inputString += inputStdin;
});

process.stdin.on('end', _ => {
    inputString = inputString.trim().split('\n').map(string => {
        return string.trim();
    });

    main();
});

function readLine() {
    return inputString[currentLine++];
}

function regexVar() {
    let re = new RegExp('^(Mr|Mrs|Ms|Dr|Er)(\\.)([a-zA-Z])+$');
    return re;
}


function main() {
    const re = regexVar();
    const s = readLine();

    console.log(!!s.match(re));
}