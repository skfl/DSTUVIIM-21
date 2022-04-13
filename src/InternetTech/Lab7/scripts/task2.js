let start = Date.now();
let startPos = 0;
let timer = setInterval(function(){
    let timePassed = Date.now()-start;

    if(timePassed >= 2000){
        startPos -= 4;
        if(startPos == 4 ){
            clearInterval(timer);
            return;            
        }
        console.log(startPos);
        drawBack(startPos);
    }

    if(timePassed>=4000){
        clearInterval(timer);
        return;
    }

    if(timePassed<2000){
        startPos += 4;
        draw(startPos);
    }

},10);

function draw(startPos){
    id2.style.left = startPos + 'px';
}


function drawBack(startPos){
    id2.style.left = startPos + 'px';
}