x = 100  // center
y = 50   // center
r = 50   // radius
a = 0    // angle (from 0 to Math.PI * 2)

function rotate(a) {

  var px = x + r * Math.cos(a); // <-- that's the maths you need
  var py = y + r * Math.sin(a);

  document.getElementById("id3").style.left = px + "px";
  document.getElementById("id3").style.top = py + "px";
}


setInterval(function() {
  a = (a + Math.PI / 360) % (Math.PI * 2);
  rotate(a);
}, 5);
