// Number of pagination buttons to show before and after active button
const pageBtnLR = 2;
const dataPerPage = "30";
let data = getcontributorsData();
data.then(function(json) {
  const jsonSize = json.length;
  for (var i = 0; i < jsonSize; i++) {
    json[i]["pageId"] = i + 1;
    if (i == 0) json[i]["active"] = true;
    else json[i]["active"] = false;
  }
});

function getcontributorsData() {
  let client_id = "45ebb6d8e84478c05bec";
  let client_secret = "11ffca05704f88d486072382012903f147489b8c";
  let url1 = `https://api.github.com/repos/Open-Source-Contributors-JSS/Hacktoberfest2019/contributors?per_page=500&client_id=${this.client_id}&client_secret=${this.client_secret}`;
  return new Promise((resolve, reject) => {
    fetch(url1)
      .then(data => data.json())
      .then(jsondata => resolve(jsondata))
      .catch(err => reject(err));
  });
}

$(document).ready(function() {
  //data.then(json => console.log(json));
  data.then(json => render(json, dataPerPage, 1));

  $("#team").click(function() {
    if (!$(this).hasClass("selected")) {
      $(this).addClass("selected");
      $("#contributors").removeClass("selected");

      $("#contributors-block").fadeOut(300, function() {
        $("#team-block").fadeIn(300);
      });
    }
  });

  $("#contributors").click(function() {
    if (!$(this).hasClass("selected")) {
      $(this).addClass("selected");
      $("#team").removeClass("selected");

      $("#team-block").fadeOut(300, function() {
        $("#contributors-block").fadeIn(300);
      });
    }
  });
});

// UI Elements
const pagesContainer = document.querySelector(".contributors-list"),
  buttonsContainer = document.querySelector(".contributors-pagination"),
  numButtonsContainer = document.querySelector(".page-nums");

function clearPages() {
  while (pagesContainer.firstChild) {
    pagesContainer.firstChild.remove();
  }
}

function clearButtons() {
  while (numButtonsContainer.firstChild) {
    numButtonsContainer.firstChild.remove();
  }
}

function renderButtons(activePage, jsondata) {
  clearButtons();

  const total_page = Math.ceil(
    parseInt(jsondata.length) / parseInt(dataPerPage)
  );
  var count = 0;
  jsondata.forEach(function(current) {
    count++;
    if (
      count <= total_page &&
      (activePage.pageId - pageBtnLR <= count && count <= activePage.pageId + pageBtnLR)
    ) {
      const button = document.createElement("button");
      button.className = "page-num";
      button.type = "button";
      button.title = current.pageId;
      button.textContent = current.pageId;

      if (current.pageId === activePage.pageId) {
        button.classList.add("active");
      } else {
        button.classList.remove("active");
      }

      numButtonsContainer.appendChild(button);
    }
  });

  if (activePage.pageId - 1 === 0) {
    document.getElementsByClassName("arrow-left")[0].style.display = "none";
  } else {
    document.getElementsByClassName("arrow-left")[0].style.display =
      "inline-block";
  }

  if (activePage.pageId - 1 === total_page - 1) {
    document.getElementsByClassName("arrow-right")[0].style.display = "none";
  } else {
    document.getElementsByClassName("arrow-right")[0].style.display =
      "inline-block";
  }
}

// Main render
function render(jsondata, req_per_page, page_no) {
  clearPages();

  let activePage = jsondata.find(function(current) {
    return current.active === true;
  });

  let output = "";
  const startRange = req_per_page * (page_no - 1);
  const endRange = req_per_page * page_no;
  for (let i = startRange; i < endRange; i++) {
    let item = jsondata[i];
    output += `<div class="column card">
            <img src=${item.avatar_url} alt="" />
            <div>
                <a href=${item.html_url} target="_blank"><h4 class="title is-4">${item.login}</h4></a>
                <p><small>Contributions: ${item.contributions}</small></p>
            </div>
        </div>`;
    //console.log(i);
    if (i == jsondata.length - 1) break;
  }

  const div = document.createElement("div");
  div.className = "page";
  div.dataset.pageId = activePage.pageId;
  div.innerHTML = output;

  pagesContainer.appendChild(div);

  setTimeout(function() {
    div.classList.add("active");
  }, 10);

  renderButtons(activePage, jsondata);
}

// Event listeners for button clicks
// Buttons with page numbers click event
numButtonsContainer.addEventListener("click", function(e) {
  if (e.target.classList.contains("page-num")) {
    data.then(function(jsondata) {
      const activePage = jsondata.find(function(current) {
        return current.active;
      });

      if (e.target.title != activePage.pageId) {
        jsondata.forEach(function(current) {
          current.active = false;
        });

        jsondata[e.target.title - 1].active = true;
        render(jsondata, dataPerPage, e.target.title);
      }
    });
  }
});

// Arrow buttons click event
buttonsContainer.addEventListener("click", function(e) {
  data.then(function(jsondata) {
    let activePage = jsondata.find(function(current) {
      return current.active === true;
    });

    if (e.target.className === "arrow-left") {
      document.getElementsByClassName("arrow-right")[0].style.display =
        "inline-block";

      if (jsondata[0].active !== true) {
        jsondata[activePage.pageId - 1].active = false;
        jsondata[activePage.pageId - 1 - 1].active = true;
        render(jsondata, dataPerPage, activePage.pageId - 1);
      }
    } else if (e.target.className === "arrow-right") {
      document.getElementsByClassName("arrow-left")[0].style.display =
        "inline-block";

      if (jsondata[jsondata.length - 1].active !== true) {
        jsondata[activePage.pageId - 1].active = false;
        jsondata[activePage.pageId - 1 + 1].active = true;
        render(jsondata, dataPerPage, activePage.pageId + 1);
      }
    } else return;
  });
});
