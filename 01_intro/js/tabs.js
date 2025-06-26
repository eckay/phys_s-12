window.onload = function(){
  document.getElementById("automaton").addEventListener("click", function(e){
    changeHidden();
  });
  document.getElementById("cat-toy").addEventListener("click", function(e){
    changeHidden();
  });
}

function changeHidden() {
  let selectedButton = [...document.querySelectorAll('.idea-select:checked')].map((d) => d.id)[0];
  if (selectedButton === "automaton") {
    document.getElementById("option-1").style.display="block";
    document.getElementById("option-2").style.display="none";
  }
  else {
    document.getElementById("option-1").style.display="none";
    document.getElementById("option-2").style.display="block";

  }
}