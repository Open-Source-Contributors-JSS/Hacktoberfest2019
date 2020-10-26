import React, {Component} from 'react';
import {Text, View, StyleSheet, TouchableOpacity} from 'react-native';

export default class App extends Component {
  constructor() {
    super();
    this.state = {
      resultText: '',
      result: '',
    };
  }

  calcResult = () => {
    const text = this.state.resultText;

    this.setState({
      result: eval(text),
    });
  };
  operate = (operation) => {
    switch (operation) {
      case 'D':
        let text = this.state.resultText.split('');
        text.pop();
        this.setState({
          resultText: text.join(''),
        });
        break;
      case '+':
      case '-':
      case '*':
      case '/':
        if (this.state.text == '') return;
        this.setState({
          resultText: this.state.resultText + operation,
        });
    }
  };
  buttonPressed = (text) => {
    if (text == '=') {
      return this.calcResult();
    }
    this.setState({
      resultText: this.state.resultText + text,
    });
  };

  render() {
    let rows = [];
    let nums = [
      [1, 2, 3],
      [4, 5, 6],
      [7, 8, 9],
      ['.', 0, '='],
    ];
    for (let i = 0; i < 4; i++) {
      let row = [];
      for (let j = 0; j < 3; j++) {
        row.push(
          <TouchableOpacity onPress={() => this.buttonPressed(nums[i][j])}>
            <Text style={styles.buttext}>{nums[i][j]}</Text>
          </TouchableOpacity>,
        );
      }
      rows.push(<View style={styles.row}>{row}</View>);
    }
    let oper = [];
    let op = ['D', '+', '-', '*', '/'];
    for (let k = 0; k < 5; k++) {
      oper.push(
        <TouchableOpacity onPress={() => this.operate(op[k])}>
          <View>
            <Text style={styles.oprtext}>{op[k]}</Text>
          </View>
        </TouchableOpacity>,
      );
    }
    return (
      <View style={styles.container}>
        <View style={styles.calculation}>
          <Text style={styles.cText}>{this.state.resultText}</Text>
        </View>
        <View style={styles.result}>
          <Text style={styles.rText}>{this.state.result}</Text>
        </View>
        <View style={styles.buttons}>
          <View style={styles.numbers}>{rows}</View>
          <View style={{borderLeftWidth: 1, borderLeftColor: 'white'}}></View>
          <View style={styles.operators}>{oper}</View>
        </View>
      </View>
    );
  }
}

const styles = StyleSheet.create({
  container: {
    flex: 1,
  },
  calculation: {
    flex: 2.5,
    backgroundColor: '#607D8B',
  },
  result: {
    flex: 2,
    backgroundColor: '#607D8B',
  },
  cText: {
    color: 'white',
    fontSize: 25,
    textAlign: 'right',
  },
  rText: {
    color: 'white',
    fontSize: 30,
    textAlign: 'right',
  },

  buttons: {
    flexGrow: 5,
    flexDirection: 'row',
  },
  row: {
    flex: 6,
    flexDirection: 'row',
    justifyContent: 'space-evenly',
    alignItems: 'center',
  },
  numbers: {
    flex: 6,
    backgroundColor: 'black',
  },
  operators: {
    flex: 2,
    backgroundColor: 'black',
    justifyContent: 'space-around',
    alignItems: 'center',
  },
  buttext: {
    fontSize: 30,
    justifyContent: 'center',
    alignItems: 'center',
    borderRadius: 5,
    height: 80,
    width: 70,
    color: 'white',
    padding: 10,
  },
  oprtext: {
    fontSize: 30,
    justifyContent: 'center',
    alignItems: 'center',
    borderRadius: 5,
    height: 80,
    width: 70,
    color: '#0D47A1',
    paddingLeft: 20,
    paddingTop: 10,
  },
});
