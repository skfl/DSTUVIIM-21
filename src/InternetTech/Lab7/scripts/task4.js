x = 100 
y = 50   
r = 100  
a = 0    

function rotate(a) {

  var px = x + r *(1-Math.sin(a))*Math.cos(a); 
  var py = y + r * (1-Math.sin(a))*Math.sin(a);

  document.getElementById("id3").style.left = px + "px";
  document.getElementById("id3").style.top = py + "px";
}


setInterval(function() {
  a = (a + Math.PI / 360) % (Math.PI * 2);
  rotate(a);
}, 5);
