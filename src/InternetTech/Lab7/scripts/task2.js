let start = Date.now();

let timer = setInterval(function(){
    let timePassed = Date.now()-start;
    
    if(timePassed >2000 && timePassed<4000){
        drawBack(timePassed);
    }


    if(timePassed>=4000){
        clearInterval(timer);
        return;
    }
    if(timePassed<2000){
        draw(timePassed);
    }
    
    

},10);

function draw(timePassed){
    id2.style.left = timePassed / 5 + 'px';
}
function drawBack(timePassed){
    id2.style.left = timePassed + 'px';
}