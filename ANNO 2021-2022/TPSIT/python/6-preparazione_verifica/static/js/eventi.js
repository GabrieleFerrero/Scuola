function main(){

}

function conferma(){
    var val_indirizzo_ip = document.getElementById("indirizzo_ip").value;
    var val_porta_min = document.getElementById("porta_min").value;
    var val_porta_max = document.getElementById("porta_max").value;

    var int_porta_min = parseInt(val_porta_min);
    var int_porta_max = parseInt(val_porta_max);

    if(int_porta_min == NaN || int_porta_max == NaN){
        alert("Errore nei dati inseriti!");
    }else{
        $.post("/", {
            dati: val_indirizzo_ip+"#"+int_porta_min+"#"+int_porta_max 
        });
    }
}