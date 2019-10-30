'use strict';


var Cell = React.createClass({
    render : function () {
        
        var cssClass = "empty";
        if (this.props.value === "x") cssClass = "red";
        if (this.props.value === "o") cssClass = "green";
        if (!isNaN(this.props.value) && this.props.shipsVisible) cssClass = "black";
        
        return (
            <div className={"cell " + cssClass} 
                 onClick={() => this.props.click()}
                 onMouseEnter={() => this.props.hoverStart()}
                 onMouseLeave={() => this.props.hoverEnd()} />
        );
    },
});

var GameBoard = React.createClass({
    
    renderCell : function (row, col, value) {
        return <Cell key={row + "_" + col} 
                     value={value} 
                     click={() => this.props.click(row, col)}
                     hoverStart={() => this.props.hoverStart(row, col)}
                     hoverEnd={() => this.props.hoverEnd(row, col)}
                     shipsVisible={this.props.shipsVisible} />
 
    },
    
    render : function () {
        
        var size = this.props.grid.length;
        var style = {
            width : size * 27,
            height : size * 27
        };
        
        
        var cells = [];
        for (var i = 0; i < size; i++) {
            for (var j = 0; j < size; j++) {
                cells.push(this.renderCell(i, j, this.props.grid[i][j]));
            }
        }
                           
        return (
            <div className="gameBoard" style={style}>
                {cells}
            </div>
        );
    },
});
        
var BattleshipGame = React.createClass({
    getInitialState : function () {
        var size = 9;
        var grid1 = [];
        var grid2 = [];
        
        var ships = [5, 4, 3, 3, 2, 1]; //lengths of ships
        
        for (var i = 0; i < size; i++) {
            grid1.push(Array(size).fill('-'));
            grid2.push(Array(size).fill('-'));
        }
        
        return {
            size : size,
            playerOne : {
                grid : grid1,
                shipsToPlace : ships.slice(),
                shotsFiredAt : 0,
                numberOfShips : 0,
                sunkenShips : 0
            },
            playerTwo : {
                grid : grid2,
                shipsToPlace : ships.slice(),
                shotsFiredAt : 0,
                numberOfShips : 0,
                sunkenShips : 0
            },
            playerOneActive : true,
            horizontalPlacement : true,
            shipNumber : 1, //every ship get unique id to enable removal and check if ship sunk
            statusMessage : "Player 1 start placing ships",
            gameStarted : false,
            gameOver : false,
        }
    },
    
    handleClick : function (row, col, player) { //player = 'playerOne' or 'playerTwo'
        
        
        if (player === 'playerOne' ? !this.state.playerOneActive : this.state.playerOneActive) return; //stop if click on wrong grid
        
        var ship;
        if (!this.state.gameStarted) { //placement phase
            if (!isNaN(ship = this.state[player].grid[row][col])) {
                this.removeShip(ship, player);
                this.state[player].numberOfShips--;
            } else {
                if (this.state[player].shipsToPlace.length === 0) return;
                
                if (this.placeShip(row, col, player)) {
                    this.state.shipNumber++;
                    this.state[player].numberOfShips++;
                }
                
            }
        } else {
            if (this.fire(row, col, player)) {
                this.state[player].shotsFiredAt++;
                this.state.playerOneActive = !this.state.playerOneActive;
                this.state.statusMessage = (this.state.playerOneActive ? "Player 2" : "Player 1") + " attack!"
               
                if (this.state[player].sunkenShips === this.state[player].numberOfShips) {
                    this.state.statusMessage = "GAME OVER! " + (this.state.playerOneActive ? "Player 1 won" : "Player 2 won");
                    this.state.gameOver = true;
                }
            }
        }

            
        this.forceUpdate();
    },
    
    handleHoverStart : function (row, col, player) {
        if (this.state.gameStarted) return; //only hover graphics on placement phase
        if (player === 'playerOne' ? !this.state.playerOneActive : this.state.playerOneActive) return; //stop if hover on wrong grid
        if (!isNaN(this.state[player].grid[row][col])) return; //dont change color if already a ship
        
        if (this.checkBoundry(row, col, player)) //if ship fits show green ship
            this.setCellValues('o', row, col, player);
        else
            this.state[player].grid[row][col] = 'x'; //otherwise just on red box
        
        this.forceUpdate();
        
    },
    
    handleHoverEnd : function (row, col, player) {
        if (this.state.gameStarted) return; //only hover graphics on placement phase
        if (player === 'playerOne' ? !this.state.playerOneActive : this.state.playerOneActive) return;
        if (!isNaN(this.state[player].grid[row][col])) return;
        
        if (this.checkBoundry(row, col, player))
            this.setCellValues('-', row, col, player);
        else
            this.state[player].grid[row][col] = '-';
        
        
        this.forceUpdate();
    },
    
    checkBoundry : function (row, col, player) {
        var axis = this.state.horizontalPlacement ? col : row;
        if ((axis + this.state[player].shipsToPlace[0]) > this.state.size) return false; //if ship outside grid
        
        for (var i = 0; i < this.state[player].shipsToPlace[0]; i++) {
            var value = this.state.horizontalPlacement ? this.state[player].grid[row][col+i] : this.state[player].grid[row+i][col];
            
            if (!isNaN(value)) return false; //check if collision with placed ship
        }
        
        return true;
    },
    
    setCellValues : function (value, startRow, startCol, player) {
        for (var i = 0; i < this.state[player].shipsToPlace[0]; i++) {
            if (this.state.horizontalPlacement) 
                this.state[player].grid[startRow][startCol+i] = value; //set horizontal
            else
                this.state[player].grid[startRow+i][startCol] = value; //set vertical
        }
    },
    
    changeShipSize : function () { //rotates ship array
        var first = this.state[(this.state.playerOneActive ? 'playerOne' : 'playerTwo')].shipsToPlace.shift();
        this.state[(this.state.playerOneActive ? 'playerOne' : 'playerTwo')].shipsToPlace.push(first);
        this.forceUpdate();
    },
    
    changeDirection : function () {
        this.state.horizontalPlacement = !this.state.horizontalPlacement;
        this.forceUpdate();
    },
    
    placeShip : function (row, col, player) {
        if (this.checkBoundry(row, col, player)) {
            this.setCellValues(this.state.shipNumber, row, col, player);
            this.state[player].shipsToPlace.shift();
            
            return true;
        }
        return false;
    },
    
    removeShip : function (shipNumber, player) {
        var length = 0;
        for (var i = 0; i < this.state.size; i++) //check whole grid for other ship parts and remove
            for (var j = 0; j < this.state.size; j++) 
                if (this.state[player].grid[i][j] === shipNumber) {
                    this.state[player].grid[i][j] = '-';
                    length++;
                }
        this.state[player].shipsToPlace.push(length);
        
    },
    
    donePlacing : function () {
        if (!this.state.playerOneActive) {
            this.state.gameStarted = true;
            this.state.statusMessage = 'Player 1 attack';
        } else {
            this.state.playerOneActive = false;
            this.state.statusMessage = 'Player 2 start placing ships';
        }
        this.forceUpdate();
    },
    
    fire : function (row, col, player) {
        var value = this.state[player].grid[row][col];
        if (value === 'x' || value === 'o') return false;
        
        if (isNaN(value)) {
            this.state[player].grid[row][col] = 'x';
            return true;
        }
        
        this.state[player].grid[row][col] = 'o';
        
        for (var i = 0; i < this.state.size; i++) {
            for (var j = 0; j < this.state.size; j++) {
                if (this.state[player].grid[i][j] === value) return true;
            }
        }
        this.state[player].sunkenShips++;
        return true;
    },
    
    render : function () {
        
        
        var shipSize = this.state[(this.state.playerOneActive ? 'playerOne' : 'playerTwo')].shipsToPlace[0];
        if (this.state.gameOver) {
            return (
                <div>
                    <h2>Battleships</h2>
                    <h3>{this.state.statusMessage}</h3>
                </div>
            )
        }
        return (
            <div>
                <h2>Battleships</h2>
                <h3>{this.state.statusMessage}</h3>
                <button onClick={this.changeDirection}>Change direction</button>
                <button onClick={this.changeShipSize}>Ship Size: {shipSize}</button>
                <button onClick={this.donePlacing}>Finish placing ships</button>
                <h3>Player 1</h3>
                Shots fired: {this.state.playerTwo.shotsFiredAt} <br />
                Ships sunk: {this.state.playerTwo.sunkenShips} <br />
                <GameBoard grid={this.state.playerOne.grid}
                           shipsVisible={(!this.state.gameStarted && this.state.playerOneActive)}
                           click={(r, c) => this.handleClick(r, c, 'playerOne')}
                           hoverStart={(r, c) => this.handleHoverStart(r, c, 'playerOne')}
                           hoverEnd={(r, c) => this.handleHoverEnd(r, c, 'playerOne')} />
                <h3>Player 2</h3>
                Shots fired: {this.state.playerOne.shotsFiredAt} <br />
                Ships sunk: {this.state.playerOne.sunkenShips} <br />
                <GameBoard grid={this.state.playerTwo.grid}
                           shipsVisible={(!this.state.gameStarted && !this.state.playerOneActive)}
                           click={(r, c) => this.handleClick(r, c, 'playerTwo')}
                           hoverStart={(r, c) => this.handleHoverStart(r, c, 'playerTwo')}
                           hoverEnd={(r, c) => this.handleHoverEnd(r, c, 'playerTwo')} />
            </div>

        );
    },
});

var renderGame = function () {
    ReactDOM.unmountComponentAtNode(document.getElementById('container'));
    ReactDOM.render(<BattleshipGame />, document.getElementById('container'));
};

renderGame();
$('#clear').click(renderGame);