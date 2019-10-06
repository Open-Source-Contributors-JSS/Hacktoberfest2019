let data = getcommandsData();
let current_page;
let lastActive;
let numberOfPages;
let list;

function getcommandsData(){
let url = '../beginner/json-files/git-commands.json';
  return new Promise((resolve, reject) => {
   fetch(url)
   .then(data => data.json())
   .then(jsondata => resolve(jsondata))
   .catch(err => reject(err));
   })
}
data.then(json => htmldata(json))
let len=0;
function htmldata(jsondata){
  list = [];
  jsondata.forEach(item => {
    list.push(item);
    len++;
  })

  numberOfPages = Math.ceil( len / numberPerPage);
  current_page = 1;
  makeButtons(numberOfPages);
  lastActive = numberOfPages;
  firstPage();
}

// pagination logic
let pageList = [];
let numberPerPage = 9;

const makeButtons = (numberOfPages) => {
  var buttons = '<button id="-1" class="btn btn-light"><</button>';
  for(var i = 1; i<=numberOfPages; i++){
    buttons += `
      <button id="${i}" class="btn btn-light">${i}</button>
    `
  }
  buttons += '<button id="+1" class="btn btn-light">></button>'
  document.querySelectorAll(".button-container")[0].innerHTML = buttons;
  addEvent();
}

const addEvent = () => {
  let totalButtons = document.querySelectorAll(".button-container")[0].querySelectorAll("button").length;
  for(var i=0; i < totalButtons; i++){
    document.querySelectorAll(".button-container")[0].querySelectorAll("button")[i].onclick = function(e){
      var button_no = parseInt(this.id);
      console.log(button_no);
      getCurrentPage(button_no);
    }
  }
}


const previousPage = () => {
  current_page -= 1;
  showButton();
  loadList();
  check();
}

const nextPage = () => {
  current_page += 1;
  showButton();
  loadList();
  check();
}

const firstPage = () => {
  current_page = 1;
  showButton();
  loadList();
  check();
}

const getCurrentPage = (e) => {
  if(e == -1 || e == +1){
    if(e == -1) previousPage();
    else nextPage();
  }
  else{
    current_page = e;
    console.log(e);
    showButton();
    loadList();
    check();
  }
}

const showButton = () =>{
  var i;
  if(current_page == 1 || current_page == 2 || current_page == 3){
    for(i = 1; i<=numberOfPages; i++){
      if(i <= 3) {
        document.querySelectorAll(".button-container")[0].querySelectorAll("button")[i].style.display = "inline-block";
      }
      else {
        document.querySelectorAll(".button-container")[0].querySelectorAll("button")[i].style.display = "none";
      }
    }
  }

  else if(current_page == numberOfPages){
    for(i = 1; i<=numberOfPages; i++){
      if(i >= numberOfPages-2) {
        document.querySelectorAll(".button-container")[0].querySelectorAll("button")[i].style.display = "inline-block";
      }
      else {
        document.querySelectorAll(".button-container")[0].querySelectorAll("button")[i].style.display = "none";
      }
    }
  }

  else {
    for(i = 1; i<=numberOfPages; i++){
      if(i == current_page || i == current_page - 1 || i == current_page + 1) {
        document.querySelectorAll(".button-container")[0].querySelectorAll("button")[i].style.display = "inline-block";
      }
      else {
        document.querySelectorAll(".button-container")[0].querySelectorAll("button")[i].style.display = "none";
      }
    }
  }
  activateButton();
}

const activateButton = () => {
  document.querySelectorAll(".button-container")[0].querySelectorAll("button")[lastActive].classList.remove("btn-active");
  document.querySelectorAll(".button-container")[0].querySelectorAll("button")[current_page].classList.add("btn-active");
}

const loadList = () => {
  let begin = ((current_page - 1) * numberPerPage);
  let end = begin + numberPerPage;

  pageList = list.slice(begin, end);
  drawList();
  lastActive = current_page;
}

const drawList = () => {
  let output = '';
  pageList.forEach(item => {
    output += `
    <div class="">
      <div class="card">
          <div class="card-header">
              <h3 class="title text-center is-4">${item.title}</h3>
          </div>
          <div class="card-body">
              <p>${item.description}</p>
          </div>
      </div>
    </div>`
  })
  document.getElementsByClassName("grid-container")[0].innerHTML = output;
}

const check = () => {
  document.getElementById("-1").style.display = ( current_page == 1 || current_page == 2 || current_page == 3) ? 'none' : 'inline-block';
  document.getElementById("+1").style.display = ( current_page == numberOfPages || current_page == numberOfPages -1 || current_page == numberOfPages + 1) ? 'none' : 'inline-block';
}