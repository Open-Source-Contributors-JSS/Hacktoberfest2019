function getRand(min, max) {
    return Math.floor( Math.random() * (max-min+1)) + min;
}

var grid; //Generated Sudoku Board
var gridPoints = [ //List of each 3x3 Grid
    [ 0,0 ],
    [ 0,3 ],
    [ 0,6 ],
    [ 3,0 ],
    [ 3,3 ],
    [ 3,6 ],
    [ 6,0 ],
    [ 6,3 ],
    [ 6,6 ]
];
var size = 9; //Number of Rows & Columns
var gridLocations = {}; //Object containing i,j coordinates => gridPoints
var hidden;
var hintUsed;

for(var i=0;i<gridPoints.length;i++) {
    var point = gridPoints[i];
    var r = point[0] , c = point[1];

    for(var j=0;j<3;j++) {
        for(var k=0;k<3;k++) {
            gridLocations[ (j+r) + "," + (k+c) ] = i;
        }
    }
}

function restart() {

    var num = document.getElementById("difficulty").value;
    num = parseInt(num);

    var div = document.getElementById("tableHolder");
    if(!num || num < 1) {
        div.innerHTML = "Please select a difficulty level";
        return;
    }

    div.innerHTML = "Generating the sudoku board";

    hintUsed = 0;
    grid = []; //Resetting the sudoku grid

    for(var i=0;i<size;i++) {
        var arr = [];
        for(var j=0;j<size;j++) {
            arr[j] = 0;
        }
        grid[i] = arr;
    }
    
    //Filling the diagonal 3x3 Grid boxes first
    fillGrid(0);
    fillGrid(4);
    fillGrid(8);

    //Filling the rest of the Cells recursively
    fillCell(0, 0);

    var html = "Hints Used : <a id='hintsUsed' >0</a><br><table align=center border=2 cellpadding=1 >";

    var copy = hideElements(num);

    for(var i=0;i<size;i++) {
        //Loop to create a Sudoku board
        html = html + "<tr>";

        for(var j=0;j<size;j++) {
            var cls;
            var loc = gridLocations[ i + "," + j ];

            if(loc%2 == 0) {
                cls = 'even';
            }
            else {
                cls = 'odd';
            }

            html += "<td class='" + cls + "'>";

            if(copy[i][j] == 0) {
                html += "<input type='text' id='grid_" + i + "_" + j + "' min=1 max=9 />";
            }
            else {
                html += copy[i][j];
            }
        }

        html += "</tr>";
    }

    div.innerHTML = html;

    hidden = copy;
    
}

//Checks if the Number can be placed in the given 3x3 Grid
function checkGrid(r,c,n) {

    for(var i=0;i<3;i++) {
        for(var j=0;j<3;j++) {
            console.log(r+i, c+j, grid[r+i]);
            if(grid[r+i][c+j] == n) {
                return false;
            }
        }
    }

    return true;
}

//Checks if Number can be placed in the given Row
function checkRow(r, n) {

    for(var i=0; i<9;i++) {
        if(grid[r][i] == n) {
            return false;
        }
    }

    return true;
}

//Checks if number can be placed in the given Column
function checkCol(c, n) {

    for(var i=0;i<9;i++) {
        if(grid[i][c] == n) {
            return false;
        }
    }

    return true;
}

//Fills the given 3x3 Grid Box
function fillGrid(num) {
    
    var point = gridPoints[num]; //Gets the Starting Position of the 3x3 Grid Box (x,y)
    var r = point[0], c = point[1]; //Gets Row number & Column number

    console.log("Grid#" + num + " (" + r + "," + c  + ")");
    for(var i=0;i<3;i++) {
        for(var j=0;j<3;j++) { //Loop through every Element of Grid

            var numbers = [1,2,3,4,5,6,7,8,9];//List of Possible values

            while(numbers.length > 0) {//Has atleast one Possible value

                var index = getRand(0, numbers.length-1); //Gets one Random value between 0 & (array's size) -1
                var n = numbers[index]; //Gets number present at Index of array

                if(checkGrid(r,c,n) && checkRow(r+i, n) && checkCol(c+j, n)) { //Checks if number can be placed on Sudoku board
                    grid[r+i][c+j] = n; //Assigns the number to board
                    break;
                }
                else {
                    console.log("Position(" + (r+i) + "," + (c+j) + ") cant take " + n + " at grid(" + r + "," + c + ")");
                    numbers.splice(index, 1);//Removes number from the Possible number list
                }
            }
            
        }
    }

}

//Fills the given Cell and Checks if the Sudoku board will have a valid Solution
function fillCell(i, j) {

    console.log(i,j);

    if(i >= size-1 && j >= size) { //Reached the end of board
        return true;
    }
    else if(j >= size && i < size-1) { //Reached the end of Row , go to next Row
        i++;
        j = 0;
    }

    var gridPoint = gridPoints[ gridLocations[ i + "," + j  ] ]; //Loads the Grid's Initial location (i,j);

    if(grid[i][j] != 0) { //If this cell has already been filled, proceed to next cell
        return fillCell(i, j+1);
    }

    for(var n=1;n <= size;n++) {
        if(checkGrid(gridPoint[0],gridPoint[1],n) && checkRow(i, n) && checkCol(j, n)) { //Checks if given number is safe to assign to board
            grid[i][j] = n; //Assigns actual number to cell

            if(fillCell(i, j+1)) { //Fills the next cell & checks if Solution will still be valid
                return true; //solution is valid & no furthur manipulation is required
            }
            
            grid[i][j] = 0; //Resets cell to 0 and fill it with next possible number
        }
        else {
            console.log("Position(" + (r) + "," + (i) + ") cant take " + n + " at grid(" + gridPoint.join(",") + ")");
        }
        
    }
}

//Hides given number of elements so that user can solve the board
function hideElements(num) {
    var copy = []; //Creates copy of board

    for(var i=0;i<grid.length;i++) {
        
        copy[i] = [];
        for(var j=0;j<grid[i].length;j++) {
            copy[i][j] = grid[i][j];
        }
    }

    for(var i=0;i<num;i++) {

        var r = getRand(0, size-1), c = getRand(0, size-1); //Gets a random (r,c) cell

        if(copy[r][c] != 0) { //If cell is not 0 then set it to 0
            copy[r][c] = 0;
        }
        else {
            i--; //cell was 0, find next cell to set 0
        }
    }

    return copy;//Returns the grid copy with hidden elements
}
//Function to find error
function getErrorPosition() {
    var copy = [];

    for(var i=0;i <size;i++) {
        copy[i] = [];

        for(var j=0;j<size;j++) {
            
            var val = hidden[i][j];

            if(val == 0) {
                var inp = document.getElementById("grid_" + i + "_" + j);

                val = parseInt( inp.value ) || 0;

            }
            
            copy[i][j] = val;

            if(copy[i][j] != grid[i][j]) {
                
                return [i,j];
            }
        }
    }

}
//Checking win condition
function checkWin() {
    var position = getErrorPosition();//Gets position of error if any

    var list = document.getElementsByClassName('highlight');

    for(var i=0;i<list.length;i++) {
        list[i].className = '';
    }

    if(!position) {
        alert("You've won");
    }
    else {
        document.getElementById('grid_' + position[0] + '_' + position[1]).className = 'highlight';//Highlights the error position if any
    }
}
//Function to provide hints
function getHint() {
    var position = getErrorPosition();

    if(!position) {
        return alert("No hint possible");//If no error, no hint possible
    }

    var inp = document.getElementById("grid_" + position[0] + "_" + position[1] );//Position to provide hint at

    inp.className = '';
    inp.value = grid[ position[0] ][ position[1] ];//Gets hint
    
    hintUsed++;

    document.getElementById("hintsUsed").innerHTML = hintUsed;
}