let pass = new Array();

function append(value){
    pass.push(value);
    console.log(pass.join(''))    
}

let timer = setInterval(function(){
    if(pass.join('') == "1132"){
        pass = [];
        window.open('file:///C:/Users/ssskfl/IdeaProjects/DSTU2/src/InternetTech/Lab16/index2.html');
    }else{
        pass = [];
    }
},5000);