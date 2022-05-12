var imgArr = document.getElementsByClassName("img");

var cursorPosX = 0;
var cursorPosY = 0;

document.querySelector("html").onmousemove = function(event){
    event = event;
    cursorPosX = event.clientX;
    cursorPosY = event.clientY;
}

function getRandomInt(min, max) {
    min = Math.ceil(min);
    max = Math.floor(max);
    return Math.floor(Math.random() * (max - min)) + min; 
  }

function getRandomPlace(elem){
    let xPos = getRandomInt(50,1500);
    let yPos = getRandomInt(50,500);
    elem.style.left = xPos + "px";
    elem.style.top = yPos + "px";
}

var cnt = 0;
function init(id){
    var elem = document.getElementById(id);
    cnt+=1;
    let timer = setInterval(function(){
            elem.style.left = cursorPosX + "px";
            elem.style.top = cursorPosY + "px";
        if(cnt%2==0){
            elem.style.left = elem.getBoundingClientRect().x + "px";
            elem.style.top = elem.getBoundingClientRect().y + "px";
            clearInterval(timer);
            return;
        }
    },1)
}

for(var i = 0;i<imgArr.length;i++){
    getRandomPlace(imgArr[i]);
}
document.querySelector("#submit").onclick = function(){
    
    var first = false;
    var second = false;
    var third = false;

    var check = false;

    if(Math.abs(imgArr[0].getBoundingClientRect().left - imgArr[3].getBoundingClientRect().left)<5){
        if(Math.abs(imgArr[0].getBoundingClientRect().top+250 - imgArr[3].getBoundingClientRect().top)<5){
            first = true;
        }
    }

    if(Math.abs(imgArr[2].getBoundingClientRect().left - imgArr[5].getBoundingClientRect().left)<5){
        if(Math.abs(imgArr[2].getBoundingClientRect().top+250 - imgArr[5].getBoundingClientRect().top)<5){
            third = true;
        }
    }

    if(Math.abs(imgArr[1].getBoundingClientRect().left - imgArr[4].getBoundingClientRect().left)<5){
        if(Math.abs(imgArr[1].getBoundingClientRect().top+250 - imgArr[4].getBoundingClientRect().top)<5){
            second = true;
        }
    }

    if(first && second && third){
        if(Math.abs(imgArr[0].getBoundingClientRect().top - imgArr[1].getBoundingClientRect().top)){
            if(Math.abs(imgArr[0].getBoundingClientRect().top - imgArr[2].getBoundingClientRect().top)){
                if(Math.abs(imgArr[1].getBoundingClientRect().top - imgArr[2].getBoundingClientRect().top)){
                    if(Math.abs(imgArr[0].getBoundingClientRect().left+150-imgArr[1].getBoundingClientRect().left)){
                        if(Math.abs(imgArr[1].getBoundingClientRect().left+150+imgArr[2].getBoundingClientRect().left)){
                            check = true;
                        }
                    }
                }
            }
        }
    }

    if(check){
        alert(" Well done 0_o")
    }else{
        alert("Try again -_-")
    }
    console.log(first + " 1 "+second + " 2 "+third+" 3 ");
}