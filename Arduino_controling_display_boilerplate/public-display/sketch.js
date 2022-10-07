let socket = io();
let character = {
    x: 0,
    y: 0
};
let speed = 10;
let r = 255; 

function setup() {
    frameRate(60);
    createCanvas(windowWidth, windowHeight);
    character.x = windowWidth / 2;
    character.y = windowHeight / 2;
}

function draw() {
    background(0, 10);
    fill(r, 255, 255);
    noStroke();
    ellipse(character.x, character.y, 50, 50);
}

socket.on('positions', (positions) => {
    
    character.x = map(positions.x, 0, 100, 0, windowWidth);
    character.y = map(positions.y, 100, 0, 0, windowHeight);
    if (positions.colorValue === 1) {
        r = 0;
    } if (positions.colorValue === 0) {
        r = 255;
    }

});