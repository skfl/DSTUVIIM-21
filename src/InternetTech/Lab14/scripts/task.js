var form = document.forms.form;

var screen = form.elements.screenX
var client = form.elements.clientX
var offset = form.elements.offsetX

var cursorPosX = 0;
var cursorPosY = 0;

var firstGhost = document.getElementById("ghost1");
var secondGhost =  document.getElementById("ghost2");

document.querySelector("html").onmousemove = function(event){
    event = event;
    screen.value = event.screenX;
    offset.value = event.offsetX;
    client.value = event.clientX;
    cursorPosX = event.clientX;
    cursorPosY = event.clientY;
}

let timer = setInterval(function(){
    
    if(Math.abs(firstGhost.getBoundingClientRect().x - cursorPosX)<10){
        firstGhost.style.left = firstGhost.getBoundingClientRect().x+"px";
    }else{
        if(firstGhost.getBoundingClientRect().x-cursorPosX<0){
            movePositive(firstGhost);
        }
        if(firstGhost.getBoundingClientRect().x-cursorPosX>0){
            moveNegative(firstGhost);
        }
    }

    if(Math.abs(firstGhost.getBoundingClientRect().y - cursorPosY)<10){
        firstGhost.style.top = firstGhost.getBoundingClientRect().y+"px";
    }else{
        if(firstGhost.getBoundingClientRect().y - cursorPosY < 0){
            moveYpositive(firstGhost);
        }
        if(firstGhost.getBoundingClientRect().y - cursorPosY > 0){
            moveYnegative(firstGhost);
        }
    }

    if(Math.abs(secondGhost.getBoundingClientRect().x - cursorPosX)<20){
        secondGhost.style.left = secondGhost.getBoundingClientRect().x +"px";
    }else{
        if(secondGhost.getBoundingClientRect().x-cursorPosX<0){
            movePositive(secondGhost);
        }
        if(secondGhost.getBoundingClientRect().x-cursorPosX>0){
            moveNegative(secondGhost);
        }
    }

    if(Math.abs(secondGhost.getBoundingClientRect().y - cursorPosY)<20){
        secondGhost.style.top = secondGhost.getBoundingClientRect().y + "px";
    }else{
        if(secondGhost.getBoundingClientRect().y - cursorPosY<0){
            moveYpositive(secondGhost);
        }
        if(secondGhost.getBoundingClientRect().y - cursorPosY>0){
            moveYnegative(secondGhost);
        }
    }
},10);

function movePositive(ghost){
    var ghostPos = ghost.getBoundingClientRect().x + 1;
    ghost.style.left = ghostPos+"px";
}

function moveNegative(ghost){
    var ghostPos = ghost.getBoundingClientRect().x - 1;
    ghost.style.left = ghostPos+"px";
}

function moveYpositive(ghost){
    var ghostYPos = ghost.getBoundingClientRect().y+1;
    ghost.style.top = ghostYPos + "px";
}

function moveYnegative(ghost){
    var ghostYPos = ghost.getBoundingClientRect().y - 1;
    ghost.style.top = ghostYPos + "px";
}