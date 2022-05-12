let pass = new Array();

function append(value){
    if(value=='Backspace'){
        pass = [];
        return;
    }
    pass.push(value);
    console.log(pass.join(''))    
}

document.querySelector("html").onkeydown = function(event){
    event = event;
    append(event.key);
}

let timer = setInterval(function(){
    if(pass.join('')=='cocojambo'){
        pass = [];
        window.open('file:///C:/Users/ssskfl/IdeaProjects/DSTU2/src/InternetTech/Lab16/index3.html');
    }
},50);

